#include <ros/ros.h>
#include <tf/tf.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>
#include <nav_msgs/Odometry.h>
#include <math.h>
#include <sensor_msgs/LaserScan.h>
bool quiet=true;
int angle_seguir=0;
float dist=0;

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
    // Iterar sobre los rangos del láser y buscar la distancia mínima
    double min_range = 2;
    quiet=true;
    for (int i = 0; i < 360; ++i) {
        if (msg->ranges[i] < min_range) {
			angle_seguir=i;
			min_range = msg->ranges[i];
			dist=msg->ranges[i];
        	
        }
        
        }
     if (dist >0.6) {
			quiet=false;
    }
    ROS_INFO("angle: %d",angle_seguir);
}

 

int main(int argc, char** argv)
{
    ros::init(argc, argv, "person_follower");
    ros::NodeHandle nh;

    ros::Subscriber sub_laser = nh.subscribe("scan", 1, scanCallback);
    ros::Publisher movement_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1);

    ros::Rate rate(10);

    while (ros::ok()) {
		if (not quiet){
			if(0 <= angle_seguir && angle_seguir <= 25 or 335 <= angle_seguir && angle_seguir <= 360){
				geometry_msgs::Twist move;
				move.angular.z =0;
				move.linear.x = 0.4;
				movement_pub.publish(move);
				
				}
			 else if(25 < angle_seguir && angle_seguir <= 180){
				geometry_msgs::Twist move;
				move.angular.z =0.3;
				move.linear.x = 0;
				movement_pub.publish(move);
				
				}
			 else if(180 <= angle_seguir && angle_seguir < 335){
				geometry_msgs::Twist move;
				move.angular.z =-0.3;
				move.linear.x = 0;
				movement_pub.publish(move);
				
				}
	        }
	 
		else{
			 if(20 < angle_seguir && angle_seguir <= 180){
				geometry_msgs::Twist move;
				move.angular.z =0.3;
				move.linear.x = 0;
				movement_pub.publish(move);
			}
			
			else if(180 <= angle_seguir && angle_seguir < 340){
				geometry_msgs::Twist move;
				move.angular.z =-0.3;
				move.linear.x = 0;
				movement_pub.publish(move);
				
				}
			else{
				geometry_msgs::Twist move;
				move.angular.z =0;
				move.linear.x = 0;
				movement_pub.publish(move);
				}

}
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
