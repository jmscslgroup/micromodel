#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "micromodel";

// For Block micromodel/Subscribe6
SimulinkSubscriber<std_msgs::Float64, SL_Bus_micromodel_std_msgs_Float64> Sub_micromodel_500;

// For Block micromodel/Subscribe7
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Sub_micromodel_501;

// For Block micromodel/Subscribe8
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Sub_micromodel_502;

// For Block micromodel/Publish1
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Pub_micromodel_542;

// For Block micromodel/Publish2
SimulinkPublisher<std_msgs::Float64, SL_Bus_micromodel_std_msgs_Float64> Pub_micromodel_549;

// For Block micromodel/Get Parameter4
SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_525;

// For Block micromodel/Get Parameter5
SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_526;

// For Block micromodel/Get Parameter6
SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_527;

// For Block micromodel/Limit of Unsafe Zone1
SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_499;

// For Block micromodel/Limit of Unsafe Zone2
SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_516;

// For Block micromodel/Limit of Unsafe Zone3
SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_518;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

