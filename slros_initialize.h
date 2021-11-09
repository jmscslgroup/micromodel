#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "slros_time.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block micromodel/Subscribe6
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_micromodel_std_msgs_Float64> Sub_micromodel_500;

// For Block micromodel/Subscribe7
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Sub_micromodel_501;

// For Block micromodel/Subscribe8
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Sub_micromodel_502;

// For Block micromodel/Publish1
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Pub_micromodel_542;

// For Block micromodel/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_micromodel_std_msgs_Float64> Pub_micromodel_549;

// For Block micromodel/Get Parameter4
extern SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_525;

// For Block micromodel/Get Parameter5
extern SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_526;

// For Block micromodel/Get Parameter6
extern SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_527;

// For Block micromodel/Limit of Unsafe Zone1
extern SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_499;

// For Block micromodel/Limit of Unsafe Zone2
extern SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_516;

// For Block micromodel/Limit of Unsafe Zone3
extern SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_518;

void slros_node_init(int argc, char** argv);

#endif
