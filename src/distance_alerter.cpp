


#include <std_msgs/Empty.h>
#include <sensor_msgs/PointCloud2.h>
#include "../include/distance_alerter.hpp"

void DistanceAlerter::pcd_callback(const sensor_msgs::PointCloud2::ConstPtr& pcd) {
    bool close = false;
    for (const auto dist : pcd->data) {
        if (dist < _max_dist_to_obj) {
            close = true;
            break;
        }
    }
    if (close)
        _danger_alerter_pub.publish(std_msgs::Empty());
}