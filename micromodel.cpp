//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: micromodel.cpp
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
#include "micromodel.h"
#include "micromodel_private.h"

// Block signals (default storage)
B_micromodel_T micromodel_B;

// Block states (default storage)
DW_micromodel_T micromodel_DW;

// Real-time model
RT_MODEL_micromodel_T micromodel_M_ = RT_MODEL_micromodel_T();
RT_MODEL_micromodel_T *const micromodel_M = &micromodel_M_;

// Model step function
void micromodel_step(void)
{
  SL_Bus_micromodel_std_msgs_Float64 b_varargout_2;
  real_T bsum;
  real_T dx_4;
  real_T dx_5;
  real_T rtb_Subtract1;
  real_T rtb_TotalTime;
  real_T value;
  int32_T i;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
  // MATLABSystem: '<S10>/SourceBlock' incorporates:
  //   Inport: '<S13>/In1'

  b_varargout_1 = Sub_micromodel_15.getLatestMessage(&micromodel_B.BusAssignment);

  // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (b_varargout_1) {
    micromodel_B.In1 = micromodel_B.BusAssignment;
  }

  // End of MATLABSystem: '<S10>/SourceBlock'
  // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe3'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Inport: '<S11>/In1'

  b_varargout_1 = Sub_micromodel_19.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  if (b_varargout_1) {
    micromodel_B.In1_n = b_varargout_2;
  }

  // End of MATLABSystem: '<S8>/SourceBlock'
  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // MATLABSystem: '<S9>/SourceBlock' incorporates:
  //   Inport: '<S12>/In1'

  b_varargout_1 = Sub_micromodel_22.getLatestMessage(&micromodel_B.BusAssignment);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  if (b_varargout_1) {
    micromodel_B.In1_p = micromodel_B.BusAssignment;
  }

  // End of MATLABSystem: '<S9>/SourceBlock'
  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe2'

  // Sum: '<Root>/Subtract1'
  rtb_Subtract1 = micromodel_B.In1_p.Linear.Z + micromodel_B.In1.Linear.X;

  // MATLABSystem: '<Root>/Current Time'
  currentROSTimeBus(&micromodel_B.r);

  // Sum: '<Root>/Total Time' incorporates:
  //   Gain: '<Root>/Gain'
  //   MATLABSystem: '<Root>/Current Time'

  rtb_TotalTime = micromodel_P.Gain_Gain * micromodel_B.r.Nsec +
    micromodel_B.r.Sec;

  // MATLABSystem: '<Root>/Get Parameter2'
  ParamGet_micromodel_31.get_parameter(&dx_5);

  // MATLABSystem: '<Root>/Get Parameter1'
  ParamGet_micromodel_30.get_parameter(&micromodel_B.dx_2);

  // MATLABSystem: '<Root>/Get Parameter3'
  ParamGet_micromodel_32.get_parameter(&micromodel_B.dx_3);

  // MATLABSystem: '<Root>/Get Parameter4'
  ParamGet_micromodel_33.get_parameter(&micromodel_B.dx_1);

  // MATLABSystem: '<Root>/Get Parameter5'
  ParamGet_micromodel_40.get_parameter(&value);

  // MATLABSystem: '<Root>/Get Parameter6'
  ParamGet_micromodel_41.get_parameter(&dx_4);

  // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter1'
  //   MATLABSystem: '<Root>/Get Parameter2'
  //   MATLABSystem: '<Root>/Get Parameter3'
  //   MATLABSystem: '<Root>/Get Parameter4'
  //   MATLABSystem: '<Root>/Get Parameter5'
  //   MATLABSystem: '<Root>/Get Parameter6'
  //   Memory: '<Root>/Memory'
  //   Sum: '<Root>/Subtract'

  if (!micromodel_DW.time_avg_target_not_empty) {
    micromodel_DW.t_length = 1.0;
    memset(&micromodel_DW.time_avg_target[0], 0, 1280U * sizeof(real_T));
    micromodel_DW.time_avg_target_not_empty = true;
    micromodel_DW.time_avg_target[1279] = rtb_Subtract1;
  } else {
    for (i = 0; i < 1279; i++) {
      micromodel_DW.time_avg_target[i] = micromodel_DW.time_avg_target[i + 1];
    }

    micromodel_DW.time_avg_target[1279] = rtb_Subtract1;
    if (micromodel_DW.t_length < 1280.0) {
      micromodel_DW.t_length++;
    }
  }

  micromodel_B.v_des = micromodel_DW.time_avg_target[0];
  for (i = 0; i < 1023; i++) {
    micromodel_B.v_des += micromodel_DW.time_avg_target[i + 1];
  }

  bsum = micromodel_DW.time_avg_target[1024];
  for (i = 0; i < 255; i++) {
    bsum += micromodel_DW.time_avg_target[i + 1025];
  }

  micromodel_B.v_des = (micromodel_B.v_des + bsum) / micromodel_DW.t_length;
  if ((micromodel_DW.d1 == 0.0) && (micromodel_DW.d2 == 0.0)) {
    bsum = micromodel_B.v_des * 0.8;
    micromodel_DW.d2 = 1.0;
  } else {
    bsum = ((rtb_TotalTime - micromodel_DW.Memory_PreviousInput) * 0.01 + 1.0) *
      micromodel_B.v_des;
    if ((!(bsum < micromodel_B.v_des)) && (!rtIsNaN(micromodel_B.v_des))) {
      bsum = micromodel_B.v_des;
    }
  }

  if (rtb_Subtract1 > 20.0) {
    bsum = rtb_Subtract1;
  } else if (rtb_Subtract1 > 15.0) {
    bsum += (rtb_Subtract1 - bsum) * (rtb_Subtract1 - 15.0) / 5.0;
  }

  micromodel_B.dv_minus = rtb_Subtract1 - micromodel_B.In1.Linear.X;
  if (!(micromodel_B.dv_minus < 0.0)) {
    micromodel_B.dv_minus = 0.0;
  }

  if (!(rtb_Subtract1 > 0.0)) {
    rtb_Subtract1 = 0.0;
  }

  if ((!(rtb_Subtract1 < micromodel_B.v_des)) && (!rtIsNaN(micromodel_B.v_des)))
  {
    rtb_Subtract1 = micromodel_B.v_des;
  }

  dx_5 *= micromodel_B.In1.Linear.X;
  if ((micromodel_B.dx_1 > dx_5) || rtIsNaN(dx_5)) {
    dx_5 = micromodel_B.dx_1;
  }

  micromodel_B.dv_minus *= micromodel_B.dv_minus;
  micromodel_B.dx_1 = micromodel_B.dv_minus * 0.33333333333333331 + dx_5;
  dx_5 = micromodel_B.dx_2 * micromodel_B.In1.Linear.X;
  if ((value > dx_5) || rtIsNaN(dx_5)) {
    dx_5 = value;
  }

  micromodel_B.dx_2 = micromodel_B.dv_minus * 0.5 + dx_5;
  dx_5 = micromodel_B.dx_3 * micromodel_B.In1.Linear.X;
  if ((dx_4 > dx_5) || rtIsNaN(dx_5)) {
    dx_5 = dx_4;
  }

  micromodel_B.dx_3 = micromodel_B.dv_minus + dx_5;
  value = dx_4 * 5.0;
  dx_5 = 1.3 * micromodel_B.dx_3;
  if ((value > dx_5) || rtIsNaN(dx_5)) {
    dx_5 = value;
  }

  value = dx_4 * 2.0;
  dx_4 = 1.1 * micromodel_B.dx_3;
  if ((value > dx_4) || rtIsNaN(dx_4)) {
    dx_4 = value;
  }

  if (micromodel_B.In1_n.Data >= dx_5) {
    rtb_Subtract1 = ((micromodel_B.In1_n.Data - dx_5) / dx_5 + 1.0) *
      micromodel_B.v_des;
    if (!(rtb_Subtract1 < 40.0)) {
      rtb_Subtract1 = 40.0;
    }
  } else if (micromodel_B.In1_n.Data >= dx_4) {
    dx_5 = (bsum - micromodel_B.v_des) * (dx_5 - micromodel_B.In1_n.Data) /
      (dx_5 - dx_4);
    if ((0.0 < dx_5) || rtIsNaN(dx_5)) {
      dx_5 = 0.0;
    }

    rtb_Subtract1 = micromodel_B.v_des + dx_5;
  } else if (micromodel_B.In1_n.Data >= micromodel_B.dx_3) {
    rtb_Subtract1 = bsum;
  } else if (micromodel_B.In1_n.Data >= micromodel_B.dx_2) {
    rtb_Subtract1 += (bsum - rtb_Subtract1) * (micromodel_B.In1_n.Data -
      micromodel_B.dx_2) / (micromodel_B.dx_3 - micromodel_B.dx_2);
  } else if (micromodel_B.In1_n.Data >= micromodel_B.dx_1) {
    rtb_Subtract1 = (micromodel_B.In1_n.Data - micromodel_B.dx_1) *
      rtb_Subtract1 / (micromodel_B.dx_2 - micromodel_B.dx_1);
    micromodel_DW.d1 = 1.0;
    micromodel_DW.d2 = 0.0;
  } else {
    rtb_Subtract1 = 0.0;
    micromodel_DW.d1 = 0.0;
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<S1>/Constant'

  micromodel_B.BusAssignment = micromodel_P.Constant_Value;
  micromodel_B.BusAssignment.Linear.X = rtb_Subtract1;
  micromodel_B.BusAssignment.Angular.Z = micromodel_P.Constant_Value_i;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S5>/SinkBlock'
  Pub_micromodel_29.publish(&micromodel_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<S2>/Constant'
  //   MATLAB Function: '<Root>/MATLAB Function1'

  micromodel_B.BusAssignment = micromodel_P.Constant_Value_g;
  micromodel_B.BusAssignment.Linear.X = micromodel_B.v_des;
  micromodel_B.BusAssignment.Angular.Z = micromodel_P.Constant1_Value;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_micromodel_50.publish(&micromodel_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // BusAssignment: '<Root>/Bus Assignment2' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<S3>/Constant'
  //   MATLAB Function: '<Root>/MATLAB Function1'

  micromodel_B.BusAssignment = micromodel_P.Constant_Value_h;
  micromodel_B.BusAssignment.Linear.X = bsum;
  micromodel_B.BusAssignment.Angular.Z = micromodel_P.Constant2_Value;

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S7>/SinkBlock'
  Pub_micromodel_51.publish(&micromodel_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish2'

  // Update for Memory: '<Root>/Memory'
  micromodel_DW.Memory_PreviousInput = rtb_TotalTime;
}

// Model initialize function
void micromodel_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic_0[10];
    char_T b_zeroDelimTopic_1[8];
    char_T b_zeroDelimTopic_3[7];
    char_T b_zeroDelimTopic_2[6];
    char_T b_zeroDelimTopic[4];
    char_T b_zeroDelimName[3];
    static const char_T tmp[9] = { 'l', 'e', 'a', 'd', '_', 'd', 'i', 's', 't' };

    static const char_T tmp_0[7] = { 'r', 'e', 'l', '_', 'v', 'e', 'l' };

    static const char_T tmp_1[7] = { 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_2[5] = { 'v', '_', 'd', 'e', 's' };

    static const char_T tmp_3[6] = { 'v', '_', 'd', 'e', 's', '2' };

    // InitializeConditions for Memory: '<Root>/Memory'
    micromodel_DW.Memory_PreviousInput = micromodel_P.Memory_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S10>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S13>/Out1' incorporates:
    //   Inport: '<S13>/In1'

    micromodel_B.In1 = micromodel_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S10>/Enabled Subsystem'

    // Start for MATLABSystem: '<S10>/SourceBlock'
    micromodel_DW.obj_cg.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_cg.isInitialized = 1;
    b_zeroDelimTopic[0] = 'v';
    b_zeroDelimTopic[1] = 'e';
    b_zeroDelimTopic[2] = 'l';
    b_zeroDelimTopic[3] = '\x00';
    Sub_micromodel_15.createSubscriber(&b_zeroDelimTopic[0], 1);
    micromodel_DW.obj_cg.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S11>/Out1' incorporates:
    //   Inport: '<S11>/In1'

    micromodel_B.In1_n = micromodel_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    micromodel_DW.obj_m.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_0[i] = tmp[i];
    }

    b_zeroDelimTopic_0[9] = '\x00';
    Sub_micromodel_19.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    micromodel_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S12>/Out1' incorporates:
    //   Inport: '<S12>/In1'

    micromodel_B.In1_p = micromodel_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // Start for MATLABSystem: '<S9>/SourceBlock'
    micromodel_DW.obj_d.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic_1[i] = tmp_0[i];
    }

    b_zeroDelimTopic_1[7] = '\x00';
    Sub_micromodel_22.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    micromodel_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1'
    micromodel_DW.d1 = 1.0;
    micromodel_DW.d2 = 1.0;

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    micromodel_DW.obj_jz.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_jz.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic_1[i] = tmp_1[i];
    }

    b_zeroDelimTopic_1[7] = '\x00';
    Pub_micromodel_29.createPublisher(&b_zeroDelimTopic_1[0], 1);
    micromodel_DW.obj_jz.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    micromodel_DW.obj_f.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b_zeroDelimTopic_2[i] = tmp_2[i];
    }

    b_zeroDelimTopic_2[5] = '\x00';
    Pub_micromodel_50.createPublisher(&b_zeroDelimTopic_2[0], 1);
    micromodel_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S7>/SinkBlock'
    micromodel_DW.obj_ct.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_ct.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      b_zeroDelimTopic_3[i] = tmp_3[i];
    }

    b_zeroDelimTopic_3[6] = '\x00';
    Pub_micromodel_51.createPublisher(&b_zeroDelimTopic_3[0], 1);
    micromodel_DW.obj_ct.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // Start for MATLABSystem: '<Root>/Current Time'
    micromodel_DW.obj.matlabCodegenIsDeleted = false;
    micromodel_DW.obj.isInitialized = 1;
    micromodel_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter2'
    micromodel_DW.obj_k.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_k.isInitialized = 1;
    b_zeroDelimTopic[0] = 't';
    b_zeroDelimTopic[1] = 'h';
    b_zeroDelimTopic[2] = '1';
    b_zeroDelimTopic[3] = '\x00';
    ParamGet_micromodel_31.initialize(&b_zeroDelimTopic[0]);
    ParamGet_micromodel_31.initialize_error_codes(0, 1, 2, 3);
    ParamGet_micromodel_31.set_initial_value(0.4);
    micromodel_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter1'
    micromodel_DW.obj_c.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_c.isInitialized = 1;
    b_zeroDelimTopic[0] = 't';
    b_zeroDelimTopic[1] = 'h';
    b_zeroDelimTopic[2] = '2';
    b_zeroDelimTopic[3] = '\x00';
    ParamGet_micromodel_30.initialize(&b_zeroDelimTopic[0]);
    ParamGet_micromodel_30.initialize_error_codes(0, 1, 2, 3);
    ParamGet_micromodel_30.set_initial_value(1.2);
    micromodel_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter3'
    micromodel_DW.obj_p.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_p.isInitialized = 1;
    b_zeroDelimTopic[0] = 't';
    b_zeroDelimTopic[1] = 'h';
    b_zeroDelimTopic[2] = '3';
    b_zeroDelimTopic[3] = '\x00';
    ParamGet_micromodel_32.initialize(&b_zeroDelimTopic[0]);
    ParamGet_micromodel_32.initialize_error_codes(0, 1, 2, 3);
    ParamGet_micromodel_32.set_initial_value(1.8);
    micromodel_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter4'
    micromodel_DW.obj_h.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_h.isInitialized = 1;
    b_zeroDelimName[0] = 'w';
    b_zeroDelimName[1] = '1';
    b_zeroDelimName[2] = '\x00';
    ParamGet_micromodel_33.initialize(&b_zeroDelimName[0]);
    ParamGet_micromodel_33.initialize_error_codes(0, 1, 2, 3);
    ParamGet_micromodel_33.set_initial_value(4.5);
    micromodel_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter5'
    micromodel_DW.obj_a.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_a.isInitialized = 1;
    b_zeroDelimName[0] = 'w';
    b_zeroDelimName[1] = '2';
    b_zeroDelimName[2] = '\x00';
    ParamGet_micromodel_40.initialize(&b_zeroDelimName[0]);
    ParamGet_micromodel_40.initialize_error_codes(0, 1, 2, 3);
    ParamGet_micromodel_40.set_initial_value(5.25);
    micromodel_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter6'
    micromodel_DW.obj_j.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_j.isInitialized = 1;
    b_zeroDelimName[0] = 'w';
    b_zeroDelimName[1] = '3';
    b_zeroDelimName[2] = '\x00';
    ParamGet_micromodel_41.initialize(&b_zeroDelimName[0]);
    ParamGet_micromodel_41.initialize_error_codes(0, 1, 2, 3);
    ParamGet_micromodel_41.set_initial_value(6.0);
    micromodel_DW.obj_j.isSetupComplete = true;
  }
}

// Model terminate function
void micromodel_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S10>/SourceBlock'
  if (!micromodel_DW.obj_cg.matlabCodegenIsDeleted) {
    micromodel_DW.obj_cg.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!micromodel_DW.obj_m.matlabCodegenIsDeleted) {
    micromodel_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!micromodel_DW.obj_d.matlabCodegenIsDeleted) {
    micromodel_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for MATLABSystem: '<Root>/Current Time'
  if (!micromodel_DW.obj.matlabCodegenIsDeleted) {
    micromodel_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Current Time'

  // Terminate for MATLABSystem: '<Root>/Get Parameter2'
  if (!micromodel_DW.obj_k.matlabCodegenIsDeleted) {
    micromodel_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter2'

  // Terminate for MATLABSystem: '<Root>/Get Parameter1'
  if (!micromodel_DW.obj_c.matlabCodegenIsDeleted) {
    micromodel_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter1'

  // Terminate for MATLABSystem: '<Root>/Get Parameter3'
  if (!micromodel_DW.obj_p.matlabCodegenIsDeleted) {
    micromodel_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter3'

  // Terminate for MATLABSystem: '<Root>/Get Parameter4'
  if (!micromodel_DW.obj_h.matlabCodegenIsDeleted) {
    micromodel_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter4'

  // Terminate for MATLABSystem: '<Root>/Get Parameter5'
  if (!micromodel_DW.obj_a.matlabCodegenIsDeleted) {
    micromodel_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter5'

  // Terminate for MATLABSystem: '<Root>/Get Parameter6'
  if (!micromodel_DW.obj_j.matlabCodegenIsDeleted) {
    micromodel_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter6'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!micromodel_DW.obj_jz.matlabCodegenIsDeleted) {
    micromodel_DW.obj_jz.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  if (!micromodel_DW.obj_f.matlabCodegenIsDeleted) {
    micromodel_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S7>/SinkBlock'
  if (!micromodel_DW.obj_ct.matlabCodegenIsDeleted) {
    micromodel_DW.obj_ct.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'
}

//
// File trailer for generated code.
//
// [EOF]
//
