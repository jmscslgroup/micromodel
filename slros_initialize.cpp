#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "micromodel";

// For Block micromodel/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_micromodel_std_msgs_Float64> Sub_micromodel_19;

// For Block micromodel/Subscribe2
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Sub_micromodel_22;

// For Block micromodel/Subscribe3
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Sub_micromodel_15;

// For Block micromodel/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Pub_micromodel_29;

// For Block micromodel/Publish1
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Pub_micromodel_50;

// For Block micromodel/Publish2
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Pub_micromodel_51;

// For Block micromodel/Get Parameter1
SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_30;

// For Block micromodel/Get Parameter2
SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_31;

// For Block micromodel/Get Parameter3
SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_32;

// For Block micromodel/Get Parameter4
SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_33;

// For Block micromodel/Get Parameter5
SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_40;

// For Block micromodel/Get Parameter6
SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_41;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

