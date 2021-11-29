/**
 * @author Dani Lerner (dalerner@umd.edu)
 * @brief Danger Node class declaration
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021. All rights reserved.
 * This project is released under the MIT Public License.
 * 
 */

#include <ros/ros.h>
#include "../include/distance_alerter.hpp"

int main(int argc, char **argv) {
    ros::init(argc, argv, "danger_node");
    ros::NodeHandle nh;
    ros::Duration(5).sleep();
    DistanceAlerter alerter(&nh, 1);
    ros::spin();
    return 0;
}
