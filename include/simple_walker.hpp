/**
 * @file simple_walker.hpp
 * @author Dani Lerner (dalerner@umd.edu)
 * @brief SimpleWalker Class declaration
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021. All rights reserved.
 * This project is released under the MIT Public License.
 * 
 */

#include <ros/ros.h>
#include <memory>
#include <geometry_msgs/Twist.h>

#pragma once

class SimpleWalker {
 private:
    ros::Publisher _cmd_vel_pub;
 public:
    SimpleWalker(ros::NodeHandle* nh) {
        _cmd_vel_pub = nh->advertise<geometry_msgs::Twist>("cmd_vel", 100);
    }
    ~SimpleWalker(){}

    void walk(double lin_spd, double ang_spd);

};
