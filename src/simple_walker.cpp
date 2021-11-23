/**
 * @file simple_walker.cpp
 * @author Dani Lerner (dalerner@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021. All rights reserved.
 * This project is released under the MIT Public License.
 * 
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "../include/simple_walker.hpp"

void SimpleWalker::walk(double lin_spd, double ang_spd) {
    geometry_msgs::Twist twist;
    twist.linear.x = lin_spd;
    twist.angular.z = ang_spd;
    _cmd_vel_pub.publish(twist);
}