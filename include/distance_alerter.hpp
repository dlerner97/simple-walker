

#pragma once;

#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <sensor_msgs/PointCloud2.h>

class DistanceAlerter {
 private:
    const double _max_dist_to_obj;
    ros::Subscriber _cam_depth_sub;
    ros::Publisher _danger_alerter_pub;

    void pcd_callback(const sensor_msgs::PointCloud2::ConstPtr& pcd);

 public:
    DistanceAlerter(ros::NodeHandle* nh, double max_dist=1) : _max_dist_to_obj{max_dist} {
        ROS_INFO_STREAM("Spinnging up Distance Alerter.");
        _cam_depth_sub = nh->subscribe("/realsense/depth/color/points", 1, &DistanceAlerter::pcd_callback, this);
        _danger_alerter_pub = nh->advertise<std_msgs::Empty>("/danger", 100);
    }
    ~DistanceAlerter() {
        ROS_INFO_STREAM("Shutting down Distance Alerter.");
    }
};
