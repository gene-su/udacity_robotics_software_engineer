#include <math.h>
#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

// pick up goal
float pick_up_x = 0.6;
float pick_up_y = 1.0;
// drop off goal
float drop_off_x = 0.6;
float drop_off_y = -1.0;

int main(int argc, char** argv) {
    ros::init(argc, argv, "add_markers_test");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher marker_publusher =
        n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    // Initialize marker
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();
    // Set the namespace and id for this marker.
    marker.ns = "basic_shapes";
    marker.id = 0;
    // Set the marker type
    marker.type = visualization_msgs::Marker::CUBE;
    // Set the scale
    marker.scale.x = 0.2;
    marker.scale.y = 0.2;
    marker.scale.z = 0.2;
    // Set the color
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;
    // Set the pose of the marker.
    marker.pose.position.x = pick_up_x;
    marker.pose.position.y = pick_up_y;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    // Set the lifetime
    marker.lifetime = ros::Duration();
    // Set the marker action
    marker.action = visualization_msgs::Marker::ADD;

    while (marker_publusher.getNumSubscribers() < 1) {
        if (!ros::ok()) {
            return 0;
        }
        ROS_WARN_ONCE("Please create a subscriber to the marker");
        sleep(1);
    }

    marker_publusher.publish(marker);
    ros::spinOnce();
    ros::Duration(5.0).sleep();
    marker.action = visualization_msgs::Marker::DELETE;
    marker_publusher.publish(marker);
    ROS_INFO("Object was picked up");
    ROS_INFO("Delivering...");
    ros::spinOnce();
    ros::Duration(5.0).sleep();
    marker.pose.position.x = drop_off_x;
    marker.pose.position.y = drop_off_y;
    marker.action = visualization_msgs::Marker::ADD;
    marker_publusher.publish(marker);
    ros::spinOnce();
    ROS_INFO("Object was dropped off");

    ros::spin();

    return 0;
}