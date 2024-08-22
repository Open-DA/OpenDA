/*
 * untitled.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "untitled".
 *
 * Model version              : 15.0
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Dec 13 18:10:34 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"
#include <math.h>
#include "untitled_private.h"
#include "rt_nonfinite.h"
#include <float.h>
#include <string.h>
#include "untitled_dt.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Continuous states */
X_untitled_T untitled_X;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  untitled_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  untitled_output();
  untitled_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  untitled_output();
  untitled_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model output function */
void untitled_output(void)
{
  real_T rtb_Abs;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T tmp;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* set solver stop time */
    if (!(untitled_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&untitled_M->solverInfo,
                            ((untitled_M->Timing.clockTickH0 + 1) *
        untitled_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&untitled_M->solverInfo,
                            ((untitled_M->Timing.clockTick0 + 1) *
        untitled_M->Timing.stepSize0 + untitled_M->Timing.clockTickH0 *
        untitled_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(untitled_M)) {
    untitled_M->Timing.t[0] = rtsiGetT(&untitled_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(untitled_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: untitled/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(untitled_DW.HILReadEncoderTimebase_Task, 1,
        &untitled_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        rtb_HILReadEncoderTimebase_o1 = 0;
        rtb_Abs = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          untitled_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_Abs = untitled_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }

    /* Bias: '<Root>/Bias' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<Root>/Gain2'
     *  Math: '<Root>/Mod'
     */
    untitled_B.Bias = rt_modd_snf(untitled_P.Gain2_Gain * rtb_Abs,
      untitled_P.Constant_Value) + untitled_P.Bias_Bias;

    /* Abs: '<Root>/Abs' */
    rtb_Abs = fabs(untitled_B.Bias);

    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Constant: '<S1>/Constant'
     */
    untitled_B.Compare = (rtb_Abs <= untitled_P.CompareToConstant_const);
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  rtb_Abs = untitled_P.SignalGenerator_Frequency * untitled_M->Timing.t[0];
  if (rtb_Abs - floor(rtb_Abs) >= 0.5) {
    tmp = untitled_P.SignalGenerator_Amplitude;
  } else {
    tmp = -untitled_P.SignalGenerator_Amplitude;
  }

  /* Gain: '<S2>/Gain1' incorporates:
   *  Gain: '<Root>/Gain3'
   *  SignalGenerator: '<Root>/Signal Generator'
   */
  rtb_Abs = untitled_P.Gain3_Gain * tmp * untitled_P.Gain1_Gain;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Gain: '<Root>/Gain1' */
    untitled_B.Gain1 = untitled_P.Gain1_Gain_j * rtb_HILReadEncoderTimebase_o1;
  }

  /* MultiPortSwitch: '<Root>/Multiport Switch' */
  if (!untitled_B.Compare) {
    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    untitled_B.MultiportSwitch = untitled_P.Constant1_Value;
  } else {
    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Gain: '<Root>/Gain4'
     *  Gain: '<Root>/Gain5'
     *  Sum: '<Root>/Sum'
     *  TransferFcn: '<Root>/Transfer Fcn'
     *  TransferFcn: '<Root>/Transfer Fcn1'
     */
    untitled_B.MultiportSwitch = (((untitled_P.Gain4_Gain[0] * rtb_Abs -
      untitled_B.Gain1) * untitled_P.K[0] + (untitled_P.Gain4_Gain[1] * rtb_Abs
      - untitled_B.Bias) * untitled_P.K[1]) + (untitled_P.Gain4_Gain[2] *
      rtb_Abs - (untitled_P.TransferFcn_C * untitled_X.TransferFcn_CSTATE +
                 untitled_P.TransferFcn_D * untitled_B.Gain1)) * untitled_P.K[2])
      + (untitled_P.Gain4_Gain[3] * rtb_Abs - (untitled_P.TransferFcn1_C *
          untitled_X.TransferFcn1_CSTATE + untitled_P.TransferFcn1_D *
          untitled_B.Bias)) * untitled_P.K[3];
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* Saturate: '<Root>/Saturation' */
  if (untitled_B.MultiportSwitch > untitled_P.Saturation_UpperSat) {
    tmp = untitled_P.Saturation_UpperSat;
  } else if (untitled_B.MultiportSwitch < untitled_P.Saturation_LowerSat) {
    tmp = untitled_P.Saturation_LowerSat;
  } else {
    tmp = untitled_B.MultiportSwitch;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Saturate: '<Root>/Saturation'
   */
  untitled_B.Gain = untitled_P.Gain_Gain * tmp;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: untitled/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(untitled_DW.HILInitialize_Card,
        &untitled_P.HILWriteAnalog_channels, 1, &untitled_B.Gain);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
      }
    }

    /* Gain: '<S6>/Gain' */
    untitled_B.Gain_j = untitled_P.Gain_Gain_a * untitled_B.Bias;
  }

  /* Gain: '<S5>/Gain' */
  untitled_B.Gain_f[0] = untitled_P.Gain_Gain_n * rtb_Abs;
  untitled_B.Gain_f[1] = untitled_P.Gain_Gain_n * untitled_B.Gain1;
  if (rtmIsMajorTimeStep(untitled_M)) {
  }
}

/* Model update function */
void untitled_update(void)
{
  if (rtmIsMajorTimeStep(untitled_M)) {
    rt_ertODEUpdateContinuousStates(&untitled_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++untitled_M->Timing.clockTick0)) {
    ++untitled_M->Timing.clockTickH0;
  }

  untitled_M->Timing.t[0] = rtsiGetSolverStopTime(&untitled_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++untitled_M->Timing.clockTick1)) {
      ++untitled_M->Timing.clockTickH1;
    }

    untitled_M->Timing.t[1] = untitled_M->Timing.clockTick1 *
      untitled_M->Timing.stepSize1 + untitled_M->Timing.clockTickH1 *
      untitled_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void untitled_derivatives(void)
{
  XDot_untitled_T *_rtXdot;
  _rtXdot = ((XDot_untitled_T *) untitled_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = untitled_P.TransferFcn_A *
    untitled_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += untitled_B.Gain1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = untitled_P.TransferFcn1_A *
    untitled_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += untitled_B.Bias;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: untitled/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo3_usb", "0", &untitled_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(untitled_DW.HILInitialize_Card,
      "deadband_compensation=0.65;pwm_en=0;enc0_velocity=3.0;enc1_velocity=3.0;",
      73);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(untitled_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }

    if ((untitled_P.HILInitialize_AIPStart && !is_switching) ||
        (untitled_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(untitled_DW.HILInitialize_Card,
        &untitled_P.HILInitialize_AIChannels, 1U,
        &untitled_P.HILInitialize_AILow, &untitled_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_AOPStart && !is_switching) ||
        (untitled_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(untitled_DW.HILInitialize_Card,
        &untitled_P.HILInitialize_AOChannels, 1U,
        &untitled_P.HILInitialize_AOLow, &untitled_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_AOStart && !is_switching) ||
        (untitled_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(untitled_DW.HILInitialize_Card,
        &untitled_P.HILInitialize_AOChannels, 1U,
        &untitled_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if (untitled_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (untitled_DW.HILInitialize_Card, &untitled_P.HILInitialize_AOChannels,
         1U, &untitled_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(untitled_DW.HILInitialize_Card, NULL, 0U,
      &untitled_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }

    if ((untitled_P.HILInitialize_DOStart && !is_switching) ||
        (untitled_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(untitled_DW.HILInitialize_Card,
        &untitled_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &untitled_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if (untitled_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (untitled_DW.HILInitialize_Card, &untitled_P.HILInitialize_DOChannels,
         1U, (const t_digital_state *) &untitled_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_EIPStart && !is_switching) ||
        (untitled_P.HILInitialize_EIPEnter && is_switching)) {
      untitled_DW.HILInitialize_QuadratureModes[0] =
        untitled_P.HILInitialize_EIQuadrature;
      untitled_DW.HILInitialize_QuadratureModes[1] =
        untitled_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(untitled_DW.HILInitialize_Card,
        untitled_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &untitled_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_EIStart && !is_switching) ||
        (untitled_P.HILInitialize_EIEnter && is_switching)) {
      untitled_DW.HILInitialize_InitialEICounts[0] =
        untitled_P.HILInitialize_EIInitial;
      untitled_DW.HILInitialize_InitialEICounts[1] =
        untitled_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(untitled_DW.HILInitialize_Card,
        untitled_P.HILInitialize_EIChannels, 2U,
        &untitled_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_OOStart && !is_switching) ||
        (untitled_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(untitled_DW.HILInitialize_Card,
        untitled_P.HILInitialize_OOChannels, 3U,
        untitled_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if (untitled_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (untitled_DW.HILInitialize_Card, untitled_P.HILInitialize_OOChannels, 3U,
         untitled_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: untitled/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(untitled_DW.HILInitialize_Card,
      untitled_P.HILReadEncoderTimebase_SamplesI,
      untitled_P.HILReadEncoderTimebase_Channels, 2,
      &untitled_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (untitled_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (untitled_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  untitled_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  untitled_X.TransferFcn1_CSTATE = 0.0;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: untitled/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(untitled_DW.HILInitialize_Card);
    hil_monitor_stop_all(untitled_DW.HILInitialize_Card);
    is_switching = false;
    if ((untitled_P.HILInitialize_AOTerminate && !is_switching) ||
        (untitled_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((untitled_P.HILInitialize_DOTerminate && !is_switching) ||
        (untitled_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((untitled_P.HILInitialize_OOTerminate && !is_switching) ||
        (untitled_P.HILInitialize_OOExit && is_switching)) {
      num_final_other_outputs = 3U;
    } else {
      num_final_other_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(untitled_DW.HILInitialize_Card
                         , &untitled_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &untitled_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , untitled_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &untitled_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &untitled_P.HILInitialize_DOFinal
                         , untitled_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(untitled_DW.HILInitialize_Card,
            &untitled_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &untitled_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(untitled_DW.HILInitialize_Card,
            &untitled_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &untitled_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(untitled_DW.HILInitialize_Card,
            untitled_P.HILInitialize_OOChannels, num_final_other_outputs,
            untitled_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(untitled_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(untitled_DW.HILInitialize_Card);
    hil_monitor_delete_all(untitled_DW.HILInitialize_Card);
    hil_close(untitled_DW.HILInitialize_Card);
    untitled_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  untitled_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  untitled_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  untitled_initialize();
}

void MdlTerminate(void)
{
  untitled_terminate();
}

/* Registration function */
RT_MODEL_untitled_T *untitled(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetdXPtr(&untitled_M->solverInfo, &untitled_M->derivs);
    rtsiSetContStatesPtr(&untitled_M->solverInfo, (real_T **)
                         &untitled_M->contStates);
    rtsiSetNumContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&untitled_M->solverInfo,
      &untitled_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&untitled_M->solverInfo,
      &untitled_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  untitled_M->intgData.y = untitled_M->odeY;
  untitled_M->intgData.f[0] = untitled_M->odeF[0];
  untitled_M->intgData.f[1] = untitled_M->odeF[1];
  untitled_M->intgData.f[2] = untitled_M->odeF[2];
  untitled_M->contStates = ((real_T *) &untitled_X);
  rtsiSetSolverData(&untitled_M->solverInfo, (void *)&untitled_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&untitled_M->solverInfo, false);
  rtsiSetSolverName(&untitled_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = untitled_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "untitled_M points to
       static memory which is guaranteed to be non-NULL" */
    untitled_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    untitled_M->Timing.sampleTimes = (&untitled_M->Timing.sampleTimesArray[0]);
    untitled_M->Timing.offsetTimes = (&untitled_M->Timing.offsetTimesArray[0]);

    /* task periods */
    untitled_M->Timing.sampleTimes[0] = (0.0);
    untitled_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    untitled_M->Timing.offsetTimes[0] = (0.0);
    untitled_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = untitled_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    untitled_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.002;
  untitled_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (448622629U);
  untitled_M->Sizes.checksums[1] = (4052225775U);
  untitled_M->Sizes.checksums[2] = (306397325U);
  untitled_M->Sizes.checksums[3] = (767809918U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  untitled_M->solverInfoPtr = (&untitled_M->solverInfo);
  untitled_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&untitled_M->solverInfo, 0.002);
  rtsiSetSolverMode(&untitled_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  untitled_M->blockIO = ((void *) &untitled_B);
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* parameters */
  untitled_M->defaultParam = ((real_T *)&untitled_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &untitled_X;
    untitled_M->contStates = (x);
    (void) memset((void *)&untitled_X, 0,
                  sizeof(X_untitled_T));
  }

  /* states (dwork) */
  untitled_M->dwork = ((void *) &untitled_DW);
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  untitled_M->Sizes.numContStates = (2);/* Number of continuous states */
  untitled_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  untitled_M->Sizes.numY = (0);        /* Number of model outputs */
  untitled_M->Sizes.numU = (0);        /* Number of model inputs */
  untitled_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  untitled_M->Sizes.numSampTimes = (2);/* Number of sample times */
  untitled_M->Sizes.numBlocks = (29);  /* Number of blocks */
  untitled_M->Sizes.numBlockIO = (7);  /* Number of block outputs */
  untitled_M->Sizes.numBlockPrms = (113);/* Sum of parameter "widths" */
  return untitled_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
