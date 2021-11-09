//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: micromodel.cpp
//
// Code generated for Simulink model 'micromodel'.
//
// Model version                  : 3.170
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue Nov  9 12:59:40 2021
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
  SL_Bus_micromodel_std_msgs_Float64 rtb_BusAssignment2;
  real_T bsum;
  real_T rtb_Leader1;
  real_T rtb_Subtract1;
  real_T rtb_TotalTime2;
  real_T value;
  int32_T i;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe8'
  // MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Inport: '<S11>/In1'

  b_varargout_1 = Sub_micromodel_502.getLatestMessage
    (&micromodel_B.BusAssignment1);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  if (b_varargout_1) {
    micromodel_B.In1 = micromodel_B.BusAssignment1;
  }

  // End of MATLABSystem: '<S8>/SourceBlock'
  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe8'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe6'
  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S9>/In1'

  b_varargout_1 = Sub_micromodel_500.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  if (b_varargout_1) {
    micromodel_B.In1_o = b_varargout_2;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe6'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe7'
  // MATLABSystem: '<S7>/SourceBlock' incorporates:
  //   Inport: '<S10>/In1'

  b_varargout_1 = Sub_micromodel_501.getLatestMessage
    (&micromodel_B.BusAssignment1);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S10>/Enable'

  if (b_varargout_1) {
    micromodel_B.In1_k = micromodel_B.BusAssignment1;
  }

  // End of MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe7'

  // Sum: '<Root>/Leader1'
  rtb_Leader1 = micromodel_B.In1_k.Linear.Z + micromodel_B.In1.Linear.X;

  // MATLABSystem: '<Root>/Current Time2'
  currentROSTimeBus(&micromodel_B.r);

  // Sum: '<Root>/Total Time2' incorporates:
  //   Gain: '<Root>/Gain2'
  //   MATLABSystem: '<Root>/Current Time2'

  rtb_TotalTime2 = micromodel_P.Gain2_Gain * micromodel_B.r.Nsec +
    micromodel_B.r.Sec;

  // Sum: '<Root>/Subtract1' incorporates:
  //   Memory: '<Root>/Memory'

  rtb_Subtract1 = rtb_TotalTime2 - micromodel_DW.Memory_PreviousInput;

  // MATLABSystem: '<Root>/Limit of Unsafe Zone1'
  ParamGet_micromodel_499.get_parameter(&value);

  // MATLABSystem: '<Root>/Limit of Unsafe Zone2'
  ParamGet_micromodel_516.get_parameter(&micromodel_B.dx_2);

  // MATLABSystem: '<Root>/Limit of Unsafe Zone3'
  ParamGet_micromodel_518.get_parameter(&micromodel_B.dx_3);

  // MATLABSystem: '<Root>/Get Parameter4'
  ParamGet_micromodel_525.get_parameter(&micromodel_B.dx_1);

  // MATLABSystem: '<Root>/Get Parameter5'
  ParamGet_micromodel_526.get_parameter(&micromodel_B.dx_5);

  // MATLABSystem: '<Root>/Get Parameter6'
  ParamGet_micromodel_527.get_parameter(&micromodel_B.dx_4);

  // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter4'
  //   MATLABSystem: '<Root>/Get Parameter5'
  //   MATLABSystem: '<Root>/Get Parameter6'
  //   MATLABSystem: '<Root>/Limit of Unsafe Zone1'
  //   MATLABSystem: '<Root>/Limit of Unsafe Zone2'
  //   MATLABSystem: '<Root>/Limit of Unsafe Zone3'

  if (!micromodel_DW.time_avg_target_not_empty) {
    micromodel_DW.t_length = 1.0;
    memset(&micromodel_DW.time_avg_target[0], 0, 1280U * sizeof(real_T));
    micromodel_DW.time_avg_target_not_empty = true;
    micromodel_DW.time_avg_target[1279] = rtb_Leader1;
  } else {
    for (i = 0; i < 1279; i++) {
      micromodel_DW.time_avg_target[i] = micromodel_DW.time_avg_target[i + 1];
    }

    micromodel_DW.time_avg_target[1279] = rtb_Leader1;
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
  if (!micromodel_DW.v_des2_not_empty) {
    micromodel_DW.v_des2 = micromodel_B.v_des;
    micromodel_DW.v_des2_not_empty = true;
  }

  if ((micromodel_DW.d1 == 0.0) && (micromodel_DW.d2 == 0.0)) {
    bsum = micromodel_DW.v_des2 * 0.8;
    micromodel_DW.v_des2 = micromodel_B.v_des * 0.8;
    if ((bsum < micromodel_DW.v_des2) || rtIsNaN(micromodel_DW.v_des2)) {
      micromodel_DW.v_des2 = bsum;
    }

    micromodel_DW.v3 = micromodel_DW.v_des2;
    micromodel_DW.d2 = 1.0;
  } else if ((micromodel_DW.d1 == 0.0) && (micromodel_DW.d2 == 1.0)) {
    if ((micromodel_DW.v3 < micromodel_B.v_des) || rtIsNaN(micromodel_B.v_des))
    {
      micromodel_DW.v_des2 = micromodel_DW.v3;
    } else {
      micromodel_DW.v_des2 = micromodel_B.v_des;
    }
  } else {
    micromodel_DW.v_des2 *= 0.01 * rtb_Subtract1 + 1.0;
    if ((!(micromodel_DW.v_des2 < micromodel_B.v_des)) && (!rtIsNaN
         (micromodel_B.v_des))) {
      micromodel_DW.v_des2 = micromodel_B.v_des;
    }
  }

  micromodel_B.dv_minus = rtb_Leader1 - micromodel_B.In1.Linear.X;
  if (!(micromodel_B.dv_minus < 0.0)) {
    micromodel_B.dv_minus = 0.0;
  }

  if (!(rtb_Leader1 > 0.0)) {
    rtb_Leader1 = 0.0;
  }

  if ((!(rtb_Leader1 < micromodel_B.v_des)) && (!rtIsNaN(micromodel_B.v_des))) {
    rtb_Leader1 = micromodel_B.v_des;
  }

  bsum = value * micromodel_B.In1.Linear.X;
  if ((micromodel_B.dx_1 > bsum) || rtIsNaN(bsum)) {
    bsum = micromodel_B.dx_1;
  }

  value = micromodel_B.dv_minus * micromodel_B.dv_minus;
  micromodel_B.dx_1 = value * 0.33333333333333331 + bsum;
  bsum = micromodel_B.dx_2 * micromodel_B.In1.Linear.X;
  if ((micromodel_B.dx_5 > bsum) || rtIsNaN(bsum)) {
    bsum = micromodel_B.dx_5;
  }

  micromodel_B.dx_2 = value * 0.5 + bsum;
  bsum = micromodel_B.dx_3 * micromodel_B.In1.Linear.X;
  if ((micromodel_B.dx_4 > bsum) || rtIsNaN(bsum)) {
    bsum = micromodel_B.dx_4;
  }

  micromodel_B.dx_3 = value + bsum;
  bsum = micromodel_B.dx_4 * 5.0;
  micromodel_B.dx_5 = 1.3 * micromodel_B.dx_3;
  if ((bsum > micromodel_B.dx_5) || rtIsNaN(micromodel_B.dx_5)) {
    micromodel_B.dx_5 = bsum;
  }

  bsum = micromodel_B.dx_4 * 2.0;
  micromodel_B.dx_4 = 1.1 * micromodel_B.dx_3;
  if ((bsum > micromodel_B.dx_4) || rtIsNaN(micromodel_B.dx_4)) {
    micromodel_B.dx_4 = bsum;
  }

  if (micromodel_B.In1_o.Data >= micromodel_B.dx_5) {
    i = 0;
    bsum = ((micromodel_B.In1_o.Data - micromodel_B.dx_5) / micromodel_B.dx_5 +
            1.0) * micromodel_B.v_des;
    if (!(bsum < 15.0)) {
      bsum = 15.0;
    }
  } else if (micromodel_B.In1_o.Data >= micromodel_B.dx_4) {
    i = 1;
    bsum = (micromodel_DW.v_des2 - micromodel_B.v_des) * (micromodel_B.dx_5 -
      micromodel_B.In1_o.Data) / (micromodel_B.dx_5 - micromodel_B.dx_4);
    if ((0.0 < bsum) || rtIsNaN(bsum)) {
      bsum = 0.0;
    }

    bsum += micromodel_B.v_des;
  } else if (micromodel_B.In1_o.Data >= micromodel_B.dx_3) {
    i = 2;
    bsum = micromodel_DW.v_des2;
  } else if (micromodel_B.In1_o.Data >= micromodel_B.dx_2) {
    i = 3;
    bsum = (micromodel_DW.v_des2 - rtb_Leader1) * (micromodel_B.In1_o.Data -
      micromodel_B.dx_2) / (micromodel_B.dx_3 - micromodel_B.dx_2) + rtb_Leader1;
  } else if (micromodel_B.In1_o.Data >= micromodel_B.dx_1) {
    i = 4;
    bsum = (micromodel_B.In1_o.Data - micromodel_B.dx_1) * rtb_Leader1 /
      (micromodel_B.dx_2 - micromodel_B.dx_1);
    micromodel_DW.d1 = 1.0;
    micromodel_DW.d2 = 0.0;
  } else {
    i = 5;
    bsum = 0.0;
    micromodel_DW.d1 = 0.0;
  }

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<S1>/Constant'
  //   MATLAB Function: '<Root>/MATLAB Function1'

  micromodel_B.BusAssignment1 = micromodel_P.Constant_Value;
  micromodel_B.BusAssignment1.Linear.X = bsum;
  micromodel_B.BusAssignment1.Linear.Y = micromodel_B.v_des;
  micromodel_B.BusAssignment1.Linear.Z = micromodel_DW.v_des2;
  micromodel_B.BusAssignment1.Angular.Z = micromodel_P.Constant1_Value;
  micromodel_B.BusAssignment1.Angular.X = i;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_micromodel_542.publish(&micromodel_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // MATLAB Function: '<Root>/MATLAB Function1'
  bsum = (bsum - micromodel_B.In1.Linear.X) / rtb_Subtract1;
  if (!(bsum > -3.0)) {
    bsum = -3.0;
  }

  if (bsum < 1.0) {
    // BusAssignment: '<Root>/Bus Assignment2'
    rtb_BusAssignment2.Data = bsum;
  } else {
    // BusAssignment: '<Root>/Bus Assignment2'
    rtb_BusAssignment2.Data = 1.0;
  }

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S5>/SinkBlock'
  Pub_micromodel_549.publish(&rtb_BusAssignment2);

  // End of Outputs for SubSystem: '<Root>/Publish2'

  // Update for Memory: '<Root>/Memory'
  micromodel_DW.Memory_PreviousInput = rtb_TotalTime2;
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
    char_T b_zeroDelimTopic[4];
    char_T b_zeroDelimName[3];
    static const char_T tmp[9] = { 'l', 'e', 'a', 'd', '_', 'd', 'i', 's', 't' };

    static const char_T tmp_0[7] = { 'r', 'e', 'l', '_', 'v', 'e', 'l' };

    static const char_T tmp_1[7] = { 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_2[9] = { 'c', 'm', 'd', '_', 'a', 'c', 'c', 'e', 'l'
    };

    // InitializeConditions for Memory: '<Root>/Memory'
    micromodel_DW.Memory_PreviousInput = micromodel_P.Memory_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe8'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S11>/Out1' incorporates:
    //   Inport: '<S11>/In1'

    micromodel_B.In1 = micromodel_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    micromodel_DW.obj_n.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_n.isInitialized = 1;
    b_zeroDelimTopic[0] = 'v';
    b_zeroDelimTopic[1] = 'e';
    b_zeroDelimTopic[2] = 'l';
    b_zeroDelimTopic[3] = '\x00';
    Sub_micromodel_502.createSubscriber(&b_zeroDelimTopic[0], 1);
    micromodel_DW.obj_n.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe8'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe6'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S9>/Out1' incorporates:
    //   Inport: '<S9>/In1'

    micromodel_B.In1_o = micromodel_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    micromodel_DW.obj_p.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_0[i] = tmp[i];
    }

    b_zeroDelimTopic_0[9] = '\x00';
    Sub_micromodel_500.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    micromodel_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe6'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe7'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S10>/Out1' incorporates:
    //   Inport: '<S10>/In1'

    micromodel_B.In1_k = micromodel_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    micromodel_DW.obj_o.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic_1[i] = tmp_0[i];
    }

    b_zeroDelimTopic_1[7] = '\x00';
    Sub_micromodel_501.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    micromodel_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe7'

    // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1'
    micromodel_DW.d1 = 1.0;
    micromodel_DW.d2 = 1.0;

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    micromodel_DW.obj_cy.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_cy.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic_1[i] = tmp_1[i];
    }

    b_zeroDelimTopic_1[7] = '\x00';
    Pub_micromodel_542.createPublisher(&b_zeroDelimTopic_1[0], 1);
    micromodel_DW.obj_cy.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    micromodel_DW.obj_f.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_0[i] = tmp_2[i];
    }

    b_zeroDelimTopic_0[9] = '\x00';
    Pub_micromodel_549.createPublisher(&b_zeroDelimTopic_0[0], 1);
    micromodel_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // Start for MATLABSystem: '<Root>/Current Time2'
    micromodel_DW.obj.matlabCodegenIsDeleted = false;
    micromodel_DW.obj.isInitialized = 1;
    micromodel_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Limit of Unsafe Zone1'
    micromodel_DW.obj_g.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_g.isInitialized = 1;
    b_zeroDelimTopic[0] = 't';
    b_zeroDelimTopic[1] = 'h';
    b_zeroDelimTopic[2] = '1';
    b_zeroDelimTopic[3] = '\x00';
    ParamGet_micromodel_499.initialize(&b_zeroDelimTopic[0]);
    ParamGet_micromodel_499.initialize_error_codes(0, 1, 2, 3);
    ParamGet_micromodel_499.set_initial_value(0.4);
    micromodel_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Limit of Unsafe Zone2'
    micromodel_DW.obj_i.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_i.isInitialized = 1;
    b_zeroDelimTopic[0] = 't';
    b_zeroDelimTopic[1] = 'h';
    b_zeroDelimTopic[2] = '2';
    b_zeroDelimTopic[3] = '\x00';
    ParamGet_micromodel_516.initialize(&b_zeroDelimTopic[0]);
    ParamGet_micromodel_516.initialize_error_codes(0, 1, 2, 3);
    ParamGet_micromodel_516.set_initial_value(0.4);
    micromodel_DW.obj_i.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Limit of Unsafe Zone3'
    micromodel_DW.obj_l.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_l.isInitialized = 1;
    b_zeroDelimTopic[0] = 't';
    b_zeroDelimTopic[1] = 'h';
    b_zeroDelimTopic[2] = '3';
    b_zeroDelimTopic[3] = '\x00';
    ParamGet_micromodel_518.initialize(&b_zeroDelimTopic[0]);
    ParamGet_micromodel_518.initialize_error_codes(0, 1, 2, 3);
    ParamGet_micromodel_518.set_initial_value(0.4);
    micromodel_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter4'
    micromodel_DW.obj_c.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_c.isInitialized = 1;
    b_zeroDelimName[0] = 'w';
    b_zeroDelimName[1] = '1';
    b_zeroDelimName[2] = '\x00';
    ParamGet_micromodel_525.initialize(&b_zeroDelimName[0]);
    ParamGet_micromodel_525.initialize_error_codes(0, 1, 2, 3);
    ParamGet_micromodel_525.set_initial_value(4.5);
    micromodel_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter5'
    micromodel_DW.obj_az.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_az.isInitialized = 1;
    b_zeroDelimName[0] = 'w';
    b_zeroDelimName[1] = '2';
    b_zeroDelimName[2] = '\x00';
    ParamGet_micromodel_526.initialize(&b_zeroDelimName[0]);
    ParamGet_micromodel_526.initialize_error_codes(0, 1, 2, 3);
    ParamGet_micromodel_526.set_initial_value(5.25);
    micromodel_DW.obj_az.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter6'
    micromodel_DW.obj_a.matlabCodegenIsDeleted = false;
    micromodel_DW.obj_a.isInitialized = 1;
    b_zeroDelimName[0] = 'w';
    b_zeroDelimName[1] = '3';
    b_zeroDelimName[2] = '\x00';
    ParamGet_micromodel_527.initialize(&b_zeroDelimName[0]);
    ParamGet_micromodel_527.initialize_error_codes(0, 1, 2, 3);
    ParamGet_micromodel_527.set_initial_value(6.0);
    micromodel_DW.obj_a.isSetupComplete = true;
  }
}

// Model terminate function
void micromodel_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe8'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!micromodel_DW.obj_n.matlabCodegenIsDeleted) {
    micromodel_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe8'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe6'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!micromodel_DW.obj_p.matlabCodegenIsDeleted) {
    micromodel_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe6'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe7'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!micromodel_DW.obj_o.matlabCodegenIsDeleted) {
    micromodel_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe7'

  // Terminate for MATLABSystem: '<Root>/Current Time2'
  if (!micromodel_DW.obj.matlabCodegenIsDeleted) {
    micromodel_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Current Time2'

  // Terminate for MATLABSystem: '<Root>/Limit of Unsafe Zone1'
  if (!micromodel_DW.obj_g.matlabCodegenIsDeleted) {
    micromodel_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Limit of Unsafe Zone1'

  // Terminate for MATLABSystem: '<Root>/Limit of Unsafe Zone2'
  if (!micromodel_DW.obj_i.matlabCodegenIsDeleted) {
    micromodel_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Limit of Unsafe Zone2'

  // Terminate for MATLABSystem: '<Root>/Limit of Unsafe Zone3'
  if (!micromodel_DW.obj_l.matlabCodegenIsDeleted) {
    micromodel_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Limit of Unsafe Zone3'

  // Terminate for MATLABSystem: '<Root>/Get Parameter4'
  if (!micromodel_DW.obj_c.matlabCodegenIsDeleted) {
    micromodel_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter4'

  // Terminate for MATLABSystem: '<Root>/Get Parameter5'
  if (!micromodel_DW.obj_az.matlabCodegenIsDeleted) {
    micromodel_DW.obj_az.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter5'

  // Terminate for MATLABSystem: '<Root>/Get Parameter6'
  if (!micromodel_DW.obj_a.matlabCodegenIsDeleted) {
    micromodel_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter6'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!micromodel_DW.obj_cy.matlabCodegenIsDeleted) {
    micromodel_DW.obj_cy.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!micromodel_DW.obj_f.matlabCodegenIsDeleted) {
    micromodel_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'
}

//
// File trailer for generated code.
//
// [EOF]
//
