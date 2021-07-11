#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "slros_time.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block micromodel/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_micromodel_std_msgs_Float64> Sub_micromodel_19;

// For Block micromodel/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Sub_micromodel_22;

// For Block micromodel/Subscribe3
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Sub_micromodel_15;

// For Block micromodel/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Pub_micromodel_29;

// For Block micromodel/Publish1
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Pub_micromodel_50;

// For Block micromodel/Publish2
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_micromodel_geometry_msgs_Twist> Pub_micromodel_51;

// For Block micromodel/Get Parameter1
extern SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_30;

// For Block micromodel/Get Parameter2
extern SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_31;

// For Block micromodel/Get Parameter3
extern SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_32;

// For Block micromodel/Get Parameter4
extern SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_33;

// For Block micromodel/Get Parameter5
extern SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_40;

// For Block micromodel/Get Parameter6
extern SimulinkParameterGetter<real64_T, double> ParamGet_micromodel_41;

void slros_node_init(int argc, char** argv);

#endif
