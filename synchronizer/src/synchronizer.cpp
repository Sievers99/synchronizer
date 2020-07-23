#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>

ros::Publisher image_pub;
ros::Publisher info_pub;

using namespace sensor_msgs;
using namespace message_filters;

void callback(const ImageConstPtr& image, const CameraInfoConstPtr& cam_info)
{
  image_pub.publish(image);
  info_pub.publish(cam_info);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "vision_node");

  ros::NodeHandle nh;

  image_pub = nh.advertise<sensor_msgs::Image>("/synchronized/image_rect", 1000);
  info_pub = nh.advertise<sensor_msgs::CameraInfo>("/synchronized/camera_info", 1000);

  message_filters::Subscriber<Image> image_sub(nh, "/main_camera/image_rect", 1);
  message_filters::Subscriber<CameraInfo> info_sub(nh, "/main_camera/camera_info", 1);
  TimeSynchronizer<Image, CameraInfo> sync(image_sub, info_sub, 10);
  sync.registerCallback(boost::bind(&callback, _1, _2));

  ros::spin();

  return 0;
}
