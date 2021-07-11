//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: micromodel.h
//
// Code generated for Simulink model 'micromodel'.
//
// Model version                  : 1.57
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun Jul 11 15:16:18 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_micromodel_h_
#define RTW_HEADER_micromodel_h_
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "micromodel_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_micromodel_T {
  SL_Bus_micromodel_geometry_msgs_Twist In1;// '<S13>/In1'
  SL_Bus_micromodel_geometry_msgs_Twist In1_p;// '<S12>/In1'
  SL_Bus_micromodel_geometry_msgs_Twist BusAssignment;// '<Root>/Bus Assignment' 
  SL_Bus_micromodel_ros_time_Time r;
  real_T v_des;
  real_T dv_minus;
  real_T dx_1;
  real_T dx_2;
  real_T dx_3;
  SL_Bus_micromodel_std_msgs_Float64 In1_n;// '<S11>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_micromodel_T {
  ros_slros_internal_block_Curr_T obj; // '<Root>/Current Time'
  ros_slros_internal_block_GetP_T obj_j;// '<Root>/Get Parameter6'
  ros_slros_internal_block_GetP_T obj_a;// '<Root>/Get Parameter5'
  ros_slros_internal_block_GetP_T obj_h;// '<Root>/Get Parameter4'
  ros_slros_internal_block_GetP_T obj_p;// '<Root>/Get Parameter3'
  ros_slros_internal_block_GetP_T obj_k;// '<Root>/Get Parameter2'
  ros_slros_internal_block_GetP_T obj_c;// '<Root>/Get Parameter1'
  ros_slroscpp_internal_block_P_T obj_ct;// '<S7>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_f;// '<S6>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_jz;// '<S5>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_cg;// '<S10>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_d;// '<S9>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_m;// '<S8>/SourceBlock'
  real_T Memory_PreviousInput;         // '<Root>/Memory'
  real_T d1;                           // '<Root>/MATLAB Function1'
  real_T d2;                           // '<Root>/MATLAB Function1'
  real_T time_avg_target[1280];        // '<Root>/MATLAB Function1'
  real_T t_length;                     // '<Root>/MATLAB Function1'
  boolean_T time_avg_target_not_empty; // '<Root>/MATLAB Function1'
};

// Parameters (default storage)
struct P_micromodel_T_ {
  SL_Bus_micromodel_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                          //  Referenced by: '<S1>/Constant'

  SL_Bus_micromodel_geometry_msgs_Twist Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                            //  Referenced by: '<S2>/Constant'

  SL_Bus_micromodel_geometry_msgs_Twist Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                            //  Referenced by: '<S3>/Constant'

  SL_Bus_micromodel_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                   //  Referenced by: '<S12>/Out1'

  SL_Bus_micromodel_geometry_msgs_Twist Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                            //  Referenced by: '<S9>/Constant'

  SL_Bus_micromodel_geometry_msgs_Twist Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                                     //  Referenced by: '<S13>/Out1'

  SL_Bus_micromodel_geometry_msgs_Twist Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                            //  Referenced by: '<S10>/Constant'

  SL_Bus_micromodel_std_msgs_Float64 Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                                  //  Referenced by: '<S11>/Out1'

  SL_Bus_micromodel_std_msgs_Float64 Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                         //  Referenced by: '<S8>/Constant'

  real_T Gain_Gain;                    // Expression: 1e-9
                                          //  Referenced by: '<Root>/Gain'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<Root>/Memory'

  real_T Constant_Value_i;             // Expression: 0
                                          //  Referenced by: '<Root>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant2'

};

// Real-time Model Data Structure
struct tag_RTM_micromodel_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_micromodel_T micromodel_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_micromodel_T micromodel_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_micromodel_T micromodel_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void micromodel_initialize(void);
  extern void micromodel_step(void);
  extern void micromodel_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_micromodel_T *const micromodel_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'micromodel'
//  '<S1>'   : 'micromodel/Blank Message'
//  '<S2>'   : 'micromodel/Blank Message1'
//  '<S3>'   : 'micromodel/Blank Message2'
//  '<S4>'   : 'micromodel/MATLAB Function1'
//  '<S5>'   : 'micromodel/Publish'
//  '<S6>'   : 'micromodel/Publish1'
//  '<S7>'   : 'micromodel/Publish2'
//  '<S8>'   : 'micromodel/Subscribe'
//  '<S9>'   : 'micromodel/Subscribe2'
//  '<S10>'  : 'micromodel/Subscribe3'
//  '<S11>'  : 'micromodel/Subscribe/Enabled Subsystem'
//  '<S12>'  : 'micromodel/Subscribe2/Enabled Subsystem'
//  '<S13>'  : 'micromodel/Subscribe3/Enabled Subsystem'

#endif                                 // RTW_HEADER_micromodel_h_

//
// File trailer for generated code.
//
// [EOF]
//
