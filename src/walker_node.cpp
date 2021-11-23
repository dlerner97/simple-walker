

#include <ros/ros.h>
#include "../include/simple_walker.hpp"

int main(int argc, char **argv) {
    ros::init(argc, argv, "walker_node");
    ros::NodeHandle nh;
    SimpleWalker walker(&nh);
    ros::Duration(10).sleep();
    while (ros::Time::now().is_zero()) ros::Duration(0.5).sleep();
    walker.walk(1, 1);


}