#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <math.h>

#define PI 3.14

int main(int argc, char **argv)
{
	ros::init(argc, argv, "dennis_test");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
	ros::Rate rate(10);

	geometry_msgs::Twist vel_msg;

	double t = 0.0;
	double T = 10;


	while(ros::ok()) {
	
		// Linear velocity
		double xdot = 3.0 * cos(4.0*PI*t/T) * 4.0 * PI/T;
		double ydot = 3.0 * cos(2.0*PI*t/T) * 2.0 * PI/T;
		double lv = sqrt(xdot*xdot + ydot*ydot);

		// Angular velocity
		double xdotdot = -3.0 * sin(4*PI*t/T) * (4.0*PI/T) * (4.0*PI/T);
		double ydotdot = -3.0 * sin(2*PI*t/T) * (2.0*PI/T) * (2.0*PI/T);
		double av = (ydotdot * xdot - xdotdot * ydot) / (xdot*xdot + ydot*ydot);

		vel_msg.linear.x = lv / 5.0;
		vel_msg.angular.z = av;

		pub.publish(vel_msg);

		if (t == T) {
			t = 0.0;
		} else {
			t = t + 0.1;
		}

		ros::spinOnce();
		rate.sleep();
	}


	return 0;



}
