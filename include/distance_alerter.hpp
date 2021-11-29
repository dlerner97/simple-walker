/**
 * @file distance_alerter.hpp
 * @author Dani Lerner (dalerner@umd.du)
 * @brief Distance Alerter declaration
 * @version 0.1
 * @date 2021-11-24
 * 
 * @copyright Copyright (c) 2021. All rights reserved.
 * This project is released under the MIT Public License.
 * 
 */

#pragma once

#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <sensor_msgs/LaserScan.h>

class DistanceAlerter {
 private:
    const double _dist_danger_threshold;
    ros::Subscriber _laser_scan_sub;
    ros::Publisher _danger_alerter_pub;

    void laser_callback(const sensor_msgs::LaserScan::ConstPtr& laser_msg);

 public:
    explicit DistanceAlerter(ros::NodeHandle* nh, double danger_threshold = 1) :
            _dist_danger_threshold{danger_threshold} {
        ROS_INFO_STREAM("Spinnging up Distance Alerter.");
        _laser_scan_sub = nh->subscribe("/realsense/scan", 1,
            &DistanceAlerter::laser_callback, this);
        _danger_alerter_pub = nh->advertise<std_msgs::Empty>("/danger", 1);
    }
    ~DistanceAlerter() {
        ROS_INFO_STREAM("Shutting down Distance Alerter.");
    }
};
