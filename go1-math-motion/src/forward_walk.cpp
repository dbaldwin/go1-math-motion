#include "ros/ros.h"
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "forward_walk");

	ros::NodeHandle nh;

	ros::Rate loop_rate(500);

	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);

	geometry_msgs::Twist twist;

    ros::Time beginTime = ros::Time::now();
    ros::Duration duration = ros::Duration(3);
    ros::Time endTime = beginTime + duration;

	while (ros::ok() && ros::Time::now() < endTime)
	{
        twist.linear.x = -1; // forward / back
        twist.linear.y = 0;
        twist.linear.z = 0;
        twist.angular.x = 0;
        twist.angular.y = 0;
        twist.angular.z = 0;

		pub.publish(twist);

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
