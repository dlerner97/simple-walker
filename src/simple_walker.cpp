/**
 * @file simple_walker.cpp
 * @author Dani Lerner (dalerner@umd.edu)
 * @brief Simple Walker class executable file
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

void SimpleWalker::danger_callback(const std_msgs::Empty::ConstPtr&) {
    static ros::Duration turn_rate(0.25);
    _prev_turn_time = ros::Time::now();
    danger = true;
}

void SimpleWalker::walk(double lin_spd, double ang_spd) {
    geometry_msgs::Twist twist;
    twist.linear.x = lin_spd;
    twist.angular.z = ang_spd;
    _cmd_vel_pub.publish(twist);
}

void SimpleWalker::wander(double no_danger_duration) {
    ros::Duration since_last_danger(no_danger_duration);
    ros::Rate rate(8);
    while (ros::ok()) {
        ros::spinOnce();
        if (ros::Time::now() - _prev_turn_time > since_last_danger)
            danger = false;
        if (danger)
            walk(0, 1);
        else
            walk(0.5, 0);
        rate.sleep();
    }
}
