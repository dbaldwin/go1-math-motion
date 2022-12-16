#include "ros/ros.h"
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "circle_walk");

	ros::NodeHandle nh;

	ros::Rate loop_rate(500);

	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);

	geometry_msgs::Twist twist;

	while (ros::ok())
	{
        twist.linear.x = 1; // radius (meters)
        twist.linear.y = 0;
        twist.linear.z = 0;
        twist.angular.x = 0;
        twist.angular.y = 0;
        twist.angular.z = 0; // direction (positive = left, negative = right)

		pub.publish(twist);

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
