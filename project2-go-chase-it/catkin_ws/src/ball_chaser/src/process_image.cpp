#include <sensor_msgs/Image.h>

#include <array>
#include <numeric>

#include "ball_chaser/DriveToTarget.h"
#include "ros/ros.h"

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the
// specified direction
void drive_robot(double linear_x, double angular_z) {
    // TODO: Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget drive_to_target_srv;
    drive_to_target_srv.request.linear_x = linear_x;
    drive_to_target_srv.request.angular_z = angular_z;
    client.call(drive_to_target_srv);
    ROS_INFO_STREAM(drive_to_target_srv.response.msg_feedback);
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img) {
    // Find all white pixels' column value
    std::array<int, 3> white_pixel{255, 255, 255};
    std::vector<int> white_pixel_column_value_list;
    for (int i = 0; i < img.data.size(); i += 3) {
        if (img.data[i] == white_pixel[0] &&
            img.data[i + 1] == white_pixel[1] &&
            img.data[i + 2] == white_pixel[2]) {
            white_pixel_column_value_list.push_back((i / 3) % img.width);
        }
    }

    // If there is no white pixels, stop the robot and return.
    if (white_pixel_column_value_list.empty()) {
        drive_robot(0.0, 0.0);
        return;
    }

    // Find area that the most white pixels fall in. Left, middle or right.
    double average_column_value =
        std::accumulate(white_pixel_column_value_list.begin(),
                        white_pixel_column_value_list.end(), 0.) /
        white_pixel_column_value_list.size();

    // Decide velocities base on the area has the most white pixel , and call
    // drive_robot(linear_x, angular_z) to deliver the velocities
    if (average_column_value < img.width / 3) {
        drive_robot(0.0, 0.5);
    } else if (average_column_value < img.width * 2 / 3) {
        drive_robot(0.5, 0.0);
    } else {
        drive_robot(0.0, -0.5);
    }
}

int main(int argc, char** argv) {
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>(
        "/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside
    // the process_image_callback function
    ros::Subscriber sub1 =
        n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}