/*
 * gjwwzq.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "gjwwzq".
 *
 * Model version              : 15.5
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Dec 28 16:53:32 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "gjwwzq.h"
#include "rtwtypes.h"
#include <math.h>
#include "gjwwzq_private.h"
#include "rt_nonfinite.h"
#include <float.h>
#include <string.h>
#include "gjwwzq_dt.h"

/* Block signals (default storage) */
B_gjwwzq_T gjwwzq_B;

/* Continuous states */
X_gjwwzq_T gjwwzq_X;

/* Block states (default storage) */
DW_gjwwzq_T gjwwzq_DW;

/* Real-time model */
static RT_MODEL_gjwwzq_T gjwwzq_M_;
RT_MODEL_gjwwzq_T *const gjwwzq_M = &gjwwzq_M_;

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
  gjwwzq_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  gjwwzq_output();
  gjwwzq_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  gjwwzq_output();
  gjwwzq_derivatives();

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
void gjwwzq_output(void)
{
  real_T rtb_Abs1;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T tmp;
  if (rtmIsMajorTimeStep(gjwwzq_M)) {
    /* set solver stop time */
    if (!(gjwwzq_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&gjwwzq_M->solverInfo,
                            ((gjwwzq_M->Timing.clockTickH0 + 1) *
        gjwwzq_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&gjwwzq_M->solverInfo, ((gjwwzq_M->Timing.clockTick0
        + 1) * gjwwzq_M->Timing.stepSize0 + gjwwzq_M->Timing.clockTickH0 *
        gjwwzq_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(gjwwzq_M)) {
    gjwwzq_M->Timing.t[0] = rtsiGetT(&gjwwzq_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(gjwwzq_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: gjwwzq/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(gjwwzq_DW.HILReadEncoderTimebase_Task, 1,
        &gjwwzq_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        rtb_HILReadEncoderTimebase_o1 = 0;
        rtb_Abs1 = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 = gjwwzq_DW.HILReadEncoderTimebase_Buffer
          [0];
        rtb_Abs1 = gjwwzq_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }

    /* Bias: '<Root>/Bias1' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<Root>/Gain1'
     *  Math: '<Root>/Math Function'
     */
    gjwwzq_B.Bias1 = rt_modd_snf(gjwwzq_P.Gain1_Gain * rtb_Abs1,
      gjwwzq_P.Constant_Value) + gjwwzq_P.Bias1_Bias;

    /* Abs: '<Root>/Abs1' */
    rtb_Abs1 = fabs(gjwwzq_B.Bias1);

    /* RelationalOperator: '<S1>/Compare' incorporates:
     *  Constant: '<S1>/Constant'
     */
    gjwwzq_B.Compare = (rtb_Abs1 <= gjwwzq_P.CompareToConstant1_const);
  }

  /* SignalGenerator: '<Root>/Signal Generator1' */
  rtb_Abs1 = gjwwzq_P.SignalGenerator1_Frequency * gjwwzq_M->Timing.t[0];
  if (rtb_Abs1 - floor(rtb_Abs1) >= 0.5) {
    tmp = gjwwzq_P.SignalGenerator1_Amplitude;
  } else {
    tmp = -gjwwzq_P.SignalGenerator1_Amplitude;
  }

  /* Gain: '<S2>/Gain1' incorporates:
   *  Gain: '<Root>/Gain9'
   *  SignalGenerator: '<Root>/Signal Generator1'
   */
  rtb_Abs1 = gjwwzq_P.Gain9_Gain * tmp * gjwwzq_P.Gain1_Gain_j;
  if (rtmIsMajorTimeStep(gjwwzq_M)) {
    /* Gain: '<Root>/Gain2' */
    gjwwzq_B.Gain2 = gjwwzq_P.Gain2_Gain * rtb_HILReadEncoderTimebase_o1;
  }

  /* MultiPortSwitch: '<Root>/Multiport Switch1' */
  if (!gjwwzq_B.Compare) {
    /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    gjwwzq_B.MultiportSwitch1 = gjwwzq_P.Constant3_Value;
  } else {
    /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
     *  Gain: '<Root>/Gain10'
     *  Gain: '<Root>/Gain11'
     *  Sum: '<Root>/Sum'
     *  TransferFcn: '<Root>/Transfer Fcn2'
     *  TransferFcn: '<Root>/Transfer Fcn3'
     */
    gjwwzq_B.MultiportSwitch1 = (((gjwwzq_P.Gain10_Gain[0] * rtb_Abs1 -
      gjwwzq_B.Gain2) * gjwwzq_P.Gain11_Gain[0] + (gjwwzq_P.Gain10_Gain[1] *
      rtb_Abs1 - gjwwzq_B.Bias1) * gjwwzq_P.Gain11_Gain[1]) +
      (gjwwzq_P.Gain10_Gain[2] * rtb_Abs1 - (gjwwzq_P.TransferFcn2_C *
      gjwwzq_X.TransferFcn2_CSTATE + gjwwzq_P.TransferFcn2_D * gjwwzq_B.Gain2)) *
      gjwwzq_P.Gain11_Gain[2]) + (gjwwzq_P.Gain10_Gain[3] * rtb_Abs1 -
      (gjwwzq_P.TransferFcn3_C * gjwwzq_X.TransferFcn3_CSTATE +
       gjwwzq_P.TransferFcn3_D * gjwwzq_B.Bias1)) * gjwwzq_P.Gain11_Gain[3];
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch1' */

  /* Saturate: '<Root>/Saturation1' */
  if (gjwwzq_B.MultiportSwitch1 > gjwwzq_P.Saturation1_UpperSat) {
    tmp = gjwwzq_P.Saturation1_UpperSat;
  } else if (gjwwzq_B.MultiportSwitch1 < gjwwzq_P.Saturation1_LowerSat) {
    tmp = gjwwzq_P.Saturation1_LowerSat;
  } else {
    tmp = gjwwzq_B.MultiportSwitch1;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Saturate: '<Root>/Saturation1'
   */
  gjwwzq_B.Gain = gjwwzq_P.Gain_Gain * tmp;
  if (rtmIsMajorTimeStep(gjwwzq_M)) {
    /* S-Function (hil_write_block): '<Root>/HIL Write' */

    /* S-Function Block: gjwwzq/HIL Write (hil_write_block) */
    {
      t_error result;
      result = hil_write(gjwwzq_DW.HILInitialize_Card,
                         &gjwwzq_P.HILWrite_analog_channels, 1U,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         &gjwwzq_B.Gain,
                         NULL,
                         NULL,
                         NULL
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S5>/Gain' */
  gjwwzq_B.Gain_g[0] = gjwwzq_P.Gain_Gain_c * rtb_Abs1;
  gjwwzq_B.Gain_g[1] = gjwwzq_P.Gain_Gain_c * gjwwzq_B.Gain2;
  if (rtmIsMajorTimeStep(gjwwzq_M)) {
    /* Gain: '<S6>/Gain' */
    gjwwzq_B.Gain_j = gjwwzq_P.Gain_Gain_f * gjwwzq_B.Bias1;
  }
}

/* Model update function */
void gjwwzq_update(void)
{
  if (rtmIsMajorTimeStep(gjwwzq_M)) {
    rt_ertODEUpdateContinuousStates(&gjwwzq_M->solverInfo);
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
  if (!(++gjwwzq_M->Timing.clockTick0)) {
    ++gjwwzq_M->Timing.clockTickH0;
  }

  gjwwzq_M->Timing.t[0] = rtsiGetSolverStopTime(&gjwwzq_M->solverInfo);

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
    if (!(++gjwwzq_M->Timing.clockTick1)) {
      ++gjwwzq_M->Timing.clockTickH1;
    }

    gjwwzq_M->Timing.t[1] = gjwwzq_M->Timing.clockTick1 *
      gjwwzq_M->Timing.stepSize1 + gjwwzq_M->Timing.clockTickH1 *
      gjwwzq_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void gjwwzq_derivatives(void)
{
  XDot_gjwwzq_T *_rtXdot;
  _rtXdot = ((XDot_gjwwzq_T *) gjwwzq_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = gjwwzq_P.TransferFcn2_A *
    gjwwzq_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += gjwwzq_B.Gain2;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE = gjwwzq_P.TransferFcn3_A *
    gjwwzq_X.TransferFcn3_CSTATE;
  _rtXdot->TransferFcn3_CSTATE += gjwwzq_B.Bias1;
}

/* Model initialize function */
void gjwwzq_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: gjwwzq/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo3_usb", "0", &gjwwzq_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(gjwwzq_DW.HILInitialize_Card,
      "deadband_compensation=0.65;pwm_en=0;enc0_velocity=3.0;enc1_velocity=3.0;",
      73);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(gjwwzq_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
      return;
    }

    if ((gjwwzq_P.HILInitialize_AIPStart && !is_switching) ||
        (gjwwzq_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(gjwwzq_DW.HILInitialize_Card,
        &gjwwzq_P.HILInitialize_AIChannels, 1U,
        &gjwwzq_P.HILInitialize_AILow, &gjwwzq_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
        return;
      }
    }

    if ((gjwwzq_P.HILInitialize_AOPStart && !is_switching) ||
        (gjwwzq_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(gjwwzq_DW.HILInitialize_Card,
        &gjwwzq_P.HILInitialize_AOChannels, 1U,
        &gjwwzq_P.HILInitialize_AOLow, &gjwwzq_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
        return;
      }
    }

    if ((gjwwzq_P.HILInitialize_AOStart && !is_switching) ||
        (gjwwzq_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(gjwwzq_DW.HILInitialize_Card,
        &gjwwzq_P.HILInitialize_AOChannels, 1U,
        &gjwwzq_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
        return;
      }
    }

    if (gjwwzq_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (gjwwzq_DW.HILInitialize_Card, &gjwwzq_P.HILInitialize_AOChannels, 1U,
         &gjwwzq_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(gjwwzq_DW.HILInitialize_Card, NULL, 0U,
      &gjwwzq_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
      return;
    }

    if ((gjwwzq_P.HILInitialize_DOStart && !is_switching) ||
        (gjwwzq_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(gjwwzq_DW.HILInitialize_Card,
        &gjwwzq_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &gjwwzq_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
        return;
      }
    }

    if (gjwwzq_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (gjwwzq_DW.HILInitialize_Card, &gjwwzq_P.HILInitialize_DOChannels, 1U, (
          const t_digital_state *) &gjwwzq_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
        return;
      }
    }

    if ((gjwwzq_P.HILInitialize_EIPStart && !is_switching) ||
        (gjwwzq_P.HILInitialize_EIPEnter && is_switching)) {
      gjwwzq_DW.HILInitialize_QuadratureModes[0] =
        gjwwzq_P.HILInitialize_EIQuadrature;
      gjwwzq_DW.HILInitialize_QuadratureModes[1] =
        gjwwzq_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(gjwwzq_DW.HILInitialize_Card,
        gjwwzq_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &gjwwzq_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
        return;
      }
    }

    if ((gjwwzq_P.HILInitialize_EIStart && !is_switching) ||
        (gjwwzq_P.HILInitialize_EIEnter && is_switching)) {
      gjwwzq_DW.HILInitialize_InitialEICounts[0] =
        gjwwzq_P.HILInitialize_EIInitial;
      gjwwzq_DW.HILInitialize_InitialEICounts[1] =
        gjwwzq_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(gjwwzq_DW.HILInitialize_Card,
        gjwwzq_P.HILInitialize_EIChannels, 2U,
        &gjwwzq_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
        return;
      }
    }

    if ((gjwwzq_P.HILInitialize_OOStart && !is_switching) ||
        (gjwwzq_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(gjwwzq_DW.HILInitialize_Card,
        gjwwzq_P.HILInitialize_OOChannels, 3U, gjwwzq_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
        return;
      }
    }

    if (gjwwzq_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (gjwwzq_DW.HILInitialize_Card, gjwwzq_P.HILInitialize_OOChannels, 3U,
         gjwwzq_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: gjwwzq/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(gjwwzq_DW.HILInitialize_Card,
      gjwwzq_P.HILReadEncoderTimebase_SamplesI,
      gjwwzq_P.HILReadEncoderTimebase_Channels, 2,
      &gjwwzq_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (gjwwzq_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (gjwwzq_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  gjwwzq_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3' */
  gjwwzq_X.TransferFcn3_CSTATE = 0.0;
}

/* Model terminate function */
void gjwwzq_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: gjwwzq/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(gjwwzq_DW.HILInitialize_Card);
    hil_monitor_stop_all(gjwwzq_DW.HILInitialize_Card);
    is_switching = false;
    if ((gjwwzq_P.HILInitialize_AOTerminate && !is_switching) ||
        (gjwwzq_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((gjwwzq_P.HILInitialize_DOTerminate && !is_switching) ||
        (gjwwzq_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((gjwwzq_P.HILInitialize_OOTerminate && !is_switching) ||
        (gjwwzq_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(gjwwzq_DW.HILInitialize_Card
                         , &gjwwzq_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &gjwwzq_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , gjwwzq_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &gjwwzq_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &gjwwzq_P.HILInitialize_DOFinal
                         , gjwwzq_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(gjwwzq_DW.HILInitialize_Card,
            &gjwwzq_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &gjwwzq_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(gjwwzq_DW.HILInitialize_Card,
            &gjwwzq_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &gjwwzq_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(gjwwzq_DW.HILInitialize_Card,
            gjwwzq_P.HILInitialize_OOChannels, num_final_other_outputs,
            gjwwzq_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(gjwwzq_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(gjwwzq_DW.HILInitialize_Card);
    hil_monitor_delete_all(gjwwzq_DW.HILInitialize_Card);
    hil_close(gjwwzq_DW.HILInitialize_Card);
    gjwwzq_DW.HILInitialize_Card = NULL;
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
  gjwwzq_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  gjwwzq_update();
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
  gjwwzq_initialize();
}

void MdlTerminate(void)
{
  gjwwzq_terminate();
}

/* Registration function */
RT_MODEL_gjwwzq_T *gjwwzq(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)gjwwzq_M, 0,
                sizeof(RT_MODEL_gjwwzq_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&gjwwzq_M->solverInfo, &gjwwzq_M->Timing.simTimeStep);
    rtsiSetTPtr(&gjwwzq_M->solverInfo, &rtmGetTPtr(gjwwzq_M));
    rtsiSetStepSizePtr(&gjwwzq_M->solverInfo, &gjwwzq_M->Timing.stepSize0);
    rtsiSetdXPtr(&gjwwzq_M->solverInfo, &gjwwzq_M->derivs);
    rtsiSetContStatesPtr(&gjwwzq_M->solverInfo, (real_T **)
                         &gjwwzq_M->contStates);
    rtsiSetNumContStatesPtr(&gjwwzq_M->solverInfo,
      &gjwwzq_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&gjwwzq_M->solverInfo,
      &gjwwzq_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&gjwwzq_M->solverInfo,
      &gjwwzq_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&gjwwzq_M->solverInfo,
      &gjwwzq_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&gjwwzq_M->solverInfo, (&rtmGetErrorStatus(gjwwzq_M)));
    rtsiSetRTModelPtr(&gjwwzq_M->solverInfo, gjwwzq_M);
  }

  rtsiSetSimTimeStep(&gjwwzq_M->solverInfo, MAJOR_TIME_STEP);
  gjwwzq_M->intgData.y = gjwwzq_M->odeY;
  gjwwzq_M->intgData.f[0] = gjwwzq_M->odeF[0];
  gjwwzq_M->intgData.f[1] = gjwwzq_M->odeF[1];
  gjwwzq_M->intgData.f[2] = gjwwzq_M->odeF[2];
  gjwwzq_M->contStates = ((real_T *) &gjwwzq_X);
  rtsiSetSolverData(&gjwwzq_M->solverInfo, (void *)&gjwwzq_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&gjwwzq_M->solverInfo, false);
  rtsiSetSolverName(&gjwwzq_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = gjwwzq_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "gjwwzq_M points to
       static memory which is guaranteed to be non-NULL" */
    gjwwzq_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    gjwwzq_M->Timing.sampleTimes = (&gjwwzq_M->Timing.sampleTimesArray[0]);
    gjwwzq_M->Timing.offsetTimes = (&gjwwzq_M->Timing.offsetTimesArray[0]);

    /* task periods */
    gjwwzq_M->Timing.sampleTimes[0] = (0.0);
    gjwwzq_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    gjwwzq_M->Timing.offsetTimes[0] = (0.0);
    gjwwzq_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(gjwwzq_M, &gjwwzq_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = gjwwzq_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    gjwwzq_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(gjwwzq_M, -1);
  gjwwzq_M->Timing.stepSize0 = 0.002;
  gjwwzq_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  gjwwzq_M->Sizes.checksums[0] = (1488399248U);
  gjwwzq_M->Sizes.checksums[1] = (547557163U);
  gjwwzq_M->Sizes.checksums[2] = (627003977U);
  gjwwzq_M->Sizes.checksums[3] = (982540959U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    gjwwzq_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(gjwwzq_M->extModeInfo,
      &gjwwzq_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(gjwwzq_M->extModeInfo, gjwwzq_M->Sizes.checksums);
    rteiSetTPtr(gjwwzq_M->extModeInfo, rtmGetTPtr(gjwwzq_M));
  }

  gjwwzq_M->solverInfoPtr = (&gjwwzq_M->solverInfo);
  gjwwzq_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&gjwwzq_M->solverInfo, 0.002);
  rtsiSetSolverMode(&gjwwzq_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  gjwwzq_M->blockIO = ((void *) &gjwwzq_B);
  (void) memset(((void *) &gjwwzq_B), 0,
                sizeof(B_gjwwzq_T));

  /* parameters */
  gjwwzq_M->defaultParam = ((real_T *)&gjwwzq_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &gjwwzq_X;
    gjwwzq_M->contStates = (x);
    (void) memset((void *)&gjwwzq_X, 0,
                  sizeof(X_gjwwzq_T));
  }

  /* states (dwork) */
  gjwwzq_M->dwork = ((void *) &gjwwzq_DW);
  (void) memset((void *)&gjwwzq_DW, 0,
                sizeof(DW_gjwwzq_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    gjwwzq_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  gjwwzq_M->Sizes.numContStates = (2); /* Number of continuous states */
  gjwwzq_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  gjwwzq_M->Sizes.numY = (0);          /* Number of model outputs */
  gjwwzq_M->Sizes.numU = (0);          /* Number of model inputs */
  gjwwzq_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  gjwwzq_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  gjwwzq_M->Sizes.numBlocks = (29);    /* Number of blocks */
  gjwwzq_M->Sizes.numBlockIO = (7);    /* Number of block outputs */
  gjwwzq_M->Sizes.numBlockPrms = (113);/* Sum of parameter "widths" */
  return gjwwzq_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
