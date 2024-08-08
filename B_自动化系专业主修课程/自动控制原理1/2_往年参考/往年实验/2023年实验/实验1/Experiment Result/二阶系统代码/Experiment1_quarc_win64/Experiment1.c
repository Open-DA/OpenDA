/*
 * Experiment1.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Experiment1".
 *
 * Model version              : 15.1
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Mon Oct 16 17:47:50 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Experiment1.h"
#include "rtwtypes.h"
#include "Experiment1_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "Experiment1_dt.h"

/* Block signals (default storage) */
B_Experiment1_T Experiment1_B;

/* Block states (default storage) */
DW_Experiment1_T Experiment1_DW;

/* Real-time model */
static RT_MODEL_Experiment1_T Experiment1_M_;
RT_MODEL_Experiment1_T *const Experiment1_M = &Experiment1_M_;

/* Model output function */
void Experiment1_output(void)
{
  real_T rtb_HILReadEncoderTimebase;

  /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: Experiment1/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_read_encoder(Experiment1_DW.HILReadEncoderTimebase_Task, 1,
      &Experiment1_DW.HILReadEncoderTimebase_Buffer);
    if (result < 0) {
      rtb_HILReadEncoderTimebase = 0;
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Experiment1_M, _rt_error_message);
    } else {
      rtb_HILReadEncoderTimebase = Experiment1_DW.HILReadEncoderTimebase_Buffer;
    }
  }

  /* Gain: '<Root>/Gain' */
  Experiment1_B.Gain = Experiment1_P.Gain_Gain * rtb_HILReadEncoderTimebase;

  /* Step: '<Root>/Step' */
  if (Experiment1_M->Timing.t[0] < Experiment1_P.Step_Time) {
    rtb_HILReadEncoderTimebase = Experiment1_P.Step_Y0;
  } else {
    rtb_HILReadEncoderTimebase = Experiment1_P.Step_YFinal;
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Step: '<Root>/Step'
   *  Sum: '<Root>/Sum2'
   */
  rtb_HILReadEncoderTimebase = (rtb_HILReadEncoderTimebase - Experiment1_B.Gain)
    * Experiment1_P.Gain1_Gain;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_HILReadEncoderTimebase > Experiment1_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    Experiment1_B.Saturation = Experiment1_P.Saturation_UpperSat;
  } else if (rtb_HILReadEncoderTimebase < Experiment1_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    Experiment1_B.Saturation = Experiment1_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    Experiment1_B.Saturation = rtb_HILReadEncoderTimebase;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: Experiment1/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(Experiment1_DW.HILInitialize_Card,
      &Experiment1_P.HILWriteAnalog_channels, 1, &Experiment1_B.Saturation);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Experiment1_M, _rt_error_message);
    }
  }
}

/* Model update function */
void Experiment1_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Experiment1_M->Timing.clockTick0)) {
    ++Experiment1_M->Timing.clockTickH0;
  }

  Experiment1_M->Timing.t[0] = Experiment1_M->Timing.clockTick0 *
    Experiment1_M->Timing.stepSize0 + Experiment1_M->Timing.clockTickH0 *
    Experiment1_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++Experiment1_M->Timing.clockTick1)) {
      ++Experiment1_M->Timing.clockTickH1;
    }

    Experiment1_M->Timing.t[1] = Experiment1_M->Timing.clockTick1 *
      Experiment1_M->Timing.stepSize1 + Experiment1_M->Timing.clockTickH1 *
      Experiment1_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void Experiment1_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Experiment1/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo3_usb", "0", &Experiment1_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Experiment1_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Experiment1_DW.HILInitialize_Card,
      "deadband_compensation=0.65;pwm_en=0;enc0_velocity=3.0;enc1_velocity=3.0;",
      73);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Experiment1_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Experiment1_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Experiment1_M, _rt_error_message);
      return;
    }

    if ((Experiment1_P.HILInitialize_AIPStart && !is_switching) ||
        (Experiment1_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Experiment1_DW.HILInitialize_Card,
        &Experiment1_P.HILInitialize_AIChannels, 1U,
        &Experiment1_P.HILInitialize_AILow, &Experiment1_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment1_M, _rt_error_message);
        return;
      }
    }

    if ((Experiment1_P.HILInitialize_AOPStart && !is_switching) ||
        (Experiment1_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Experiment1_DW.HILInitialize_Card,
        &Experiment1_P.HILInitialize_AOChannels, 1U,
        &Experiment1_P.HILInitialize_AOLow, &Experiment1_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment1_M, _rt_error_message);
        return;
      }
    }

    if ((Experiment1_P.HILInitialize_AOStart && !is_switching) ||
        (Experiment1_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Experiment1_DW.HILInitialize_Card,
        &Experiment1_P.HILInitialize_AOChannels, 1U,
        &Experiment1_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment1_M, _rt_error_message);
        return;
      }
    }

    if (Experiment1_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Experiment1_DW.HILInitialize_Card,
         &Experiment1_P.HILInitialize_AOChannels, 1U,
         &Experiment1_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment1_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Experiment1_DW.HILInitialize_Card, NULL,
      0U, &Experiment1_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Experiment1_M, _rt_error_message);
      return;
    }

    if ((Experiment1_P.HILInitialize_DOStart && !is_switching) ||
        (Experiment1_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Experiment1_DW.HILInitialize_Card,
        &Experiment1_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Experiment1_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment1_M, _rt_error_message);
        return;
      }
    }

    if (Experiment1_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (Experiment1_DW.HILInitialize_Card,
         &Experiment1_P.HILInitialize_DOChannels, 1U, (const t_digital_state *)
         &Experiment1_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment1_M, _rt_error_message);
        return;
      }
    }

    if ((Experiment1_P.HILInitialize_EIPStart && !is_switching) ||
        (Experiment1_P.HILInitialize_EIPEnter && is_switching)) {
      Experiment1_DW.HILInitialize_QuadratureModes[0] =
        Experiment1_P.HILInitialize_EIQuadrature;
      Experiment1_DW.HILInitialize_QuadratureModes[1] =
        Experiment1_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(Experiment1_DW.HILInitialize_Card,
        Experiment1_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &Experiment1_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment1_M, _rt_error_message);
        return;
      }
    }

    if ((Experiment1_P.HILInitialize_EIStart && !is_switching) ||
        (Experiment1_P.HILInitialize_EIEnter && is_switching)) {
      Experiment1_DW.HILInitialize_InitialEICounts[0] =
        Experiment1_P.HILInitialize_EIInitial;
      Experiment1_DW.HILInitialize_InitialEICounts[1] =
        Experiment1_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Experiment1_DW.HILInitialize_Card,
        Experiment1_P.HILInitialize_EIChannels, 2U,
        &Experiment1_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment1_M, _rt_error_message);
        return;
      }
    }

    if ((Experiment1_P.HILInitialize_OOStart && !is_switching) ||
        (Experiment1_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(Experiment1_DW.HILInitialize_Card,
        Experiment1_P.HILInitialize_OOChannels, 3U,
        Experiment1_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment1_M, _rt_error_message);
        return;
      }
    }

    if (Experiment1_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (Experiment1_DW.HILInitialize_Card,
         Experiment1_P.HILInitialize_OOChannels, 3U,
         Experiment1_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Experiment1_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: Experiment1/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Experiment1_DW.HILInitialize_Card,
      Experiment1_P.HILReadEncoderTimebase_SamplesI,
      &Experiment1_P.HILReadEncoderTimebase_Channels, 1,
      &Experiment1_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (Experiment1_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (Experiment1_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Experiment1_M, _rt_error_message);
    }
  }
}

/* Model terminate function */
void Experiment1_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Experiment1/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Experiment1_DW.HILInitialize_Card);
    hil_monitor_stop_all(Experiment1_DW.HILInitialize_Card);
    is_switching = false;
    if ((Experiment1_P.HILInitialize_AOTerminate && !is_switching) ||
        (Experiment1_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Experiment1_P.HILInitialize_DOTerminate && !is_switching) ||
        (Experiment1_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Experiment1_P.HILInitialize_OOTerminate && !is_switching) ||
        (Experiment1_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(Experiment1_DW.HILInitialize_Card
                         , &Experiment1_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &Experiment1_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Experiment1_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &Experiment1_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &Experiment1_P.HILInitialize_DOFinal
                         , Experiment1_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Experiment1_DW.HILInitialize_Card,
            &Experiment1_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &Experiment1_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Experiment1_DW.HILInitialize_Card,
            &Experiment1_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Experiment1_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Experiment1_DW.HILInitialize_Card,
            Experiment1_P.HILInitialize_OOChannels, num_final_other_outputs,
            Experiment1_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Experiment1_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Experiment1_DW.HILInitialize_Card);
    hil_monitor_delete_all(Experiment1_DW.HILInitialize_Card);
    hil_close(Experiment1_DW.HILInitialize_Card);
    Experiment1_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Experiment1_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Experiment1_update();
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
  Experiment1_initialize();
}

void MdlTerminate(void)
{
  Experiment1_terminate();
}

/* Registration function */
RT_MODEL_Experiment1_T *Experiment1(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Experiment1_M, 0,
                sizeof(RT_MODEL_Experiment1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Experiment1_M->solverInfo,
                          &Experiment1_M->Timing.simTimeStep);
    rtsiSetTPtr(&Experiment1_M->solverInfo, &rtmGetTPtr(Experiment1_M));
    rtsiSetStepSizePtr(&Experiment1_M->solverInfo,
                       &Experiment1_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Experiment1_M->solverInfo, (&rtmGetErrorStatus
      (Experiment1_M)));
    rtsiSetRTModelPtr(&Experiment1_M->solverInfo, Experiment1_M);
  }

  rtsiSetSimTimeStep(&Experiment1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Experiment1_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Experiment1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Experiment1_M points to
       static memory which is guaranteed to be non-NULL" */
    Experiment1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Experiment1_M->Timing.sampleTimes = (&Experiment1_M->
      Timing.sampleTimesArray[0]);
    Experiment1_M->Timing.offsetTimes = (&Experiment1_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    Experiment1_M->Timing.sampleTimes[0] = (0.0);
    Experiment1_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    Experiment1_M->Timing.offsetTimes[0] = (0.0);
    Experiment1_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Experiment1_M, &Experiment1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Experiment1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Experiment1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Experiment1_M, -1);
  Experiment1_M->Timing.stepSize0 = 0.002;
  Experiment1_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  Experiment1_M->Sizes.checksums[0] = (428223462U);
  Experiment1_M->Sizes.checksums[1] = (3592752081U);
  Experiment1_M->Sizes.checksums[2] = (78083876U);
  Experiment1_M->Sizes.checksums[3] = (1658752963U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Experiment1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Experiment1_M->extModeInfo,
      &Experiment1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Experiment1_M->extModeInfo,
                        Experiment1_M->Sizes.checksums);
    rteiSetTPtr(Experiment1_M->extModeInfo, rtmGetTPtr(Experiment1_M));
  }

  Experiment1_M->solverInfoPtr = (&Experiment1_M->solverInfo);
  Experiment1_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Experiment1_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Experiment1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Experiment1_M->blockIO = ((void *) &Experiment1_B);
  (void) memset(((void *) &Experiment1_B), 0,
                sizeof(B_Experiment1_T));

  /* parameters */
  Experiment1_M->defaultParam = ((real_T *)&Experiment1_P);

  /* states (dwork) */
  Experiment1_M->dwork = ((void *) &Experiment1_DW);
  (void) memset((void *)&Experiment1_DW, 0,
                sizeof(DW_Experiment1_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Experiment1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Experiment1_M->Sizes.numContStates = (0);/* Number of continuous states */
  Experiment1_M->Sizes.numY = (0);     /* Number of model outputs */
  Experiment1_M->Sizes.numU = (0);     /* Number of model inputs */
  Experiment1_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Experiment1_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Experiment1_M->Sizes.numBlocks = (10);/* Number of blocks */
  Experiment1_M->Sizes.numBlockIO = (2);/* Number of block outputs */
  Experiment1_M->Sizes.numBlockPrms = (90);/* Sum of parameter "widths" */
  return Experiment1_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
