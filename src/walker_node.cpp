/**
 * @file walker_node.cpp
 * @author Dani Lerner (dalerner@umd.edu)
 * @brief Walker node main
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021. All rights reserved.
 * This project is released under the MIT Public License.
 * 
 */

#include <ros/ros.h>
#include "../include/simple_walker.hpp"

int main(int argc, char **argv) {
    ros::init(argc, argv, "walker_node");
    ros::NodeHandle nh;
    SimpleWalker walker(&nh);
    ros::Duration(5).sleep();
    while (ros::Time::now().is_zero()) ros::Duration(0.5).sleep();
    walker.wander();
    ros::spin();
    return 0;
}
