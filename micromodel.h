//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: micromodel.h
//
// Code generated for Simulink model 'micromodel'.
//
// Model version                  : 3.171
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri Nov 26 20:34:01 2021
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
#include "rtw_continuous.h"
#include "rtw_solver.h"
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
  SL_Bus_micromodel_geometry_msgs_Twist In1;// '<S11>/In1'
  SL_Bus_micromodel_geometry_msgs_Twist In1_k;// '<S10>/In1'
  SL_Bus_micromodel_geometry_msgs_Twist BusAssignment1;// '<Root>/Bus Assignment1' 
  SL_Bus_micromodel_ros_time_Time r;
  real_T v_des;
  real_T dv_minus;
  real_T dx_1;
  real_T dx_2;
  real_T dx_3;
  real_T dx_5;
  real_T dx_4;
  SL_Bus_micromodel_std_msgs_Float64 In1_o;// '<S9>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_micromodel_T {
  ros_slros_internal_block_Curr_T obj; // '<Root>/Current Time2'
  ros_slros_internal_block_GetP_T obj_l;// '<Root>/Limit of Unsafe Zone3'
  ros_slros_internal_block_GetP_T obj_i;// '<Root>/Limit of Unsafe Zone2'
  ros_slros_internal_block_GetP_T obj_g;// '<Root>/Limit of Unsafe Zone1'
  ros_slros_internal_block_GetP_T obj_a;// '<Root>/Get Parameter6'
  ros_slros_internal_block_GetP_T obj_az;// '<Root>/Get Parameter5'
  ros_slros_internal_block_GetP_T obj_c;// '<Root>/Get Parameter4'
  ros_slroscpp_internal_block_P_T obj_f;// '<S5>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_cy;// '<S4>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S8>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_o;// '<S7>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_p;// '<S6>/SourceBlock'
  real_T Memory_PreviousInput;         // '<Root>/Memory'
  real_T v_des2;                       // '<Root>/MATLAB Function1'
  real_T v3;                           // '<Root>/MATLAB Function1'
  real_T d1;                           // '<Root>/MATLAB Function1'
  real_T d2;                           // '<Root>/MATLAB Function1'
  real_T time_avg_target[1280];        // '<Root>/MATLAB Function1'
  real_T t_length;                     // '<Root>/MATLAB Function1'
  boolean_T v_des2_not_empty;          // '<Root>/MATLAB Function1'
  boolean_T time_avg_target_not_empty; // '<Root>/MATLAB Function1'
};

// Parameters (default storage)
struct P_micromodel_T_ {
  SL_Bus_micromodel_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                          //  Referenced by: '<S1>/Constant'

  SL_Bus_micromodel_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                   //  Referenced by: '<S10>/Out1'

  SL_Bus_micromodel_geometry_msgs_Twist Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                            //  Referenced by: '<S7>/Constant'

  SL_Bus_micromodel_geometry_msgs_Twist Out1_Y0_d;// Computed Parameter: Out1_Y0_d
                                                     //  Referenced by: '<S11>/Out1'

  SL_Bus_micromodel_geometry_msgs_Twist Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                            //  Referenced by: '<S8>/Constant'

  SL_Bus_micromodel_std_msgs_Float64 Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                         //  Referenced by: '<S2>/Constant'

  SL_Bus_micromodel_std_msgs_Float64 Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                  //  Referenced by: '<S9>/Out1'

  SL_Bus_micromodel_std_msgs_Float64 Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                         //  Referenced by: '<S6>/Constant'

  real_T Gain2_Gain;                   // Expression: 1e-9
                                          //  Referenced by: '<Root>/Gain2'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<Root>/Memory'

  real_T Constant1_Value;              // Expression: 0.0
                                          //  Referenced by: '<Root>/Constant1'

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
//  '<S1>'   : 'micromodel/Blank Message1'
//  '<S2>'   : 'micromodel/Blank Message2'
//  '<S3>'   : 'micromodel/MATLAB Function1'
//  '<S4>'   : 'micromodel/Publish1'
//  '<S5>'   : 'micromodel/Publish2'
//  '<S6>'   : 'micromodel/Subscribe6'
//  '<S7>'   : 'micromodel/Subscribe7'
//  '<S8>'   : 'micromodel/Subscribe8'
//  '<S9>'   : 'micromodel/Subscribe6/Enabled Subsystem'
//  '<S10>'  : 'micromodel/Subscribe7/Enabled Subsystem'
//  '<S11>'  : 'micromodel/Subscribe8/Enabled Subsystem'

#endif                                 // RTW_HEADER_micromodel_h_

//
// File trailer for generated code.
//
// [EOF]
//
