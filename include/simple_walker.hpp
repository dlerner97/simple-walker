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

#pragma once

#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

#include <memory>

class SimpleWalker {
 private:
    ros::Publisher _cmd_vel_pub;
    ros::Subscriber _danger_sub;
    ros::Time _prev_turn_time;

    void danger_callback(const std_msgs::Empty::ConstPtr&);

 public:
    explicit SimpleWalker(ros::NodeHandle* nh) {
        _cmd_vel_pub = nh->advertise<geometry_msgs::Twist>("/cmd_vel", 100);
        _danger_sub = nh->subscribe("/danger", 1,
            &SimpleWalker::danger_callback, this);
        _prev_turn_time = ros::Time::now();
    }
    ~SimpleWalker() {
        ROS_INFO_STREAM("Shutting down Walker.");
    }

    void walk(double lin_spd, double ang_spd);
    void wander(double no_danger_rate = 0.5);
};
