//usage: save pointcloud when one topic subscribed.
//input: realsense default pcl
//input2: save_flg:bool
//output: pcd file

#include <ros/ros.h>
#include <pcl_ros/point_cloud.h>
#include <std_msgs/Bool.h>
#include <stdio.h>
#include <stdlib.h>

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

void pcl_callback(const PointCloud::ConstPtr& msg)
{
  //
  //
  ROS_INFO("pcl_cb");
}

void save_callback(const std_msgs::Bool::ConstPtr& msg)
{
  //
  //
  //system("rosrun ");
  ROS_INFO("sf_cb");
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "pclsaver");
  ros::NodeHandle nh;
  
  //point cloud subscriber
  ros::Subscriber pcl_sub = nh.subscribe<PointCloud>("/camera/depth_registered/points", 3, pcl_callback);
  //save_flg subscriber
  ros::Subscriber save_sub = nh.subscribe<std_msgs::Bool>("/save_flg", 3, save_callback);
  //publish pcl state
  ros::Publisher pcl_state_pub = nh.advertise<std_msgs::Bool>("pcl_state", 3);

  //TODO:createtimer
  //publish timer 2Hz
  ros::Rate loop_rate(2);
  ros::spin();

  while(ros::ok())
  {
    //publish pcl state
    //because realsense connection is weak...
    std_msgs::Bool msg;
    msg.data = true;
    pcl_state_pub.publish(msg);
    loop_rate.sleep();
  }

  return 0;

}
