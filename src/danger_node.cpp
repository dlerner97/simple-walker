

#include <ros/ros.h>
#include "../include/distance_alerter.hpp"

int main(int argc, char **argv) {
    ros::init(argc, argv, "danger_node");
    ros::NodeHandle nh;
    DistanceAlerter alerter(&nh, 1);
    ros::spin();
    return 0;
}