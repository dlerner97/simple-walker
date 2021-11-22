

#include <ros/ros.h>
#include "../include/simple_walker.hpp"

int main(int argc, char **argv) {
    ros::init(argc, argv, "walker_node");
    ros::NodeHandle nh;
    SimpleWalker walker(&nh);

}