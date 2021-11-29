/**
 * @file distance_alerter.cpp
 * @author Dani Lerner (dalerner@umd.du)
 * @brief Distance Alerter executable
 * @version 0.1
 * @date 2021-11-24
 * 
 * @copyright Copyright (c) 2021. All rights reserved.
 * This project is released under the MIT Public License.
 * 
 */

#include <std_msgs/Empty.h>
#include <sensor_msgs/LaserScan.h>

#include <algorithm>
#include "../include/distance_alerter.hpp"

void DistanceAlerter::laser_callback(
        const sensor_msgs::LaserScan::ConstPtr& laser_msg) {
    static int halfway = laser_msg->ranges.size()/2;
    auto min = std::min_element(laser_msg->ranges.begin() + halfway - 30,
        laser_msg->ranges.begin() + halfway + 31);
    if (*min < _dist_danger_threshold) {
        _danger_alerter_pub.publish(std_msgs::Empty());
    }
}
