cmake_minimum_required(VERSION 2.8.3)
project(synchronizer)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg message_filters)

## Declare ROS messages and services
#add_message_files(DIRECTORY msg FILES Num.msg)
#add_service_files(DIRECTORY srv FILES AddTwoInts.srv)

## Generate added messages and services
#generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(synchronizer src/synchronizer.cpp)
target_link_libraries(synchronizer ${catkin_LIBRARIES})
#add_dependencies(example )
