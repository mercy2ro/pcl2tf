# pcl2tf
ROS1 package, calc camera pose from past and current pcl.

input
realsense pcl

output
tf

By using pcl_ros and the following command, either bag or topic can be transformed to pcd.

rosrun pcl_ros bag_to_pcd <input_file.bag> <topic> <output_directory>

rosrun pcl_ros pointcloud_to_pcd input:=/velodyne/pointcloud2

plz refer http://wiki.ros.org/pcl_ros

how to install pcl_ros
sudo install ros-noetic-pcl-ros
