/****************************************************************************
 * gjwwzq_main.c
 *
 * This file was generated automatically by QUARC. It serves as the main
 * entry point for the real-time code.
 *
 * Date:           Thu Dec 28 16:53:31 2023
 * Model version:  15.5
 * Matlab version: 9.9 (R2023a) 19-Nov-2022
 ****************************************************************************/

#include <windows.h>
#include <mmsystem.h>
#include <direct.h>
#include <signal.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "rtwtypes.h"
#include "rtmodel.h"
#include "rt_sim.h"
#include "rt_nonfinite.h"
#include "ext_work.h"
#include "quanser_timer.h"
#include "quanser_semaphore.h"
#include "quanser_thread.h"
#include "quanser_signal.h"
#include "quanser_string.h"
#include "quanser_messages.h"

/*=========*
 * Defines *
 *=========*/
static const int_T exit_failure = 1;
static const int_T exit_success = 0;

#define STRINGIZE1(name)               #name
#define STRINGIZE(name)                STRINGIZE1(name)          /* need to expand name    */
#ifndef RT
# error "must define RT"
#endif

static const real_T RUN_FOREVER = -1.0;
typedef RT_MODEL_gjwwzq_T RT_MODEL;

/*====================*
 * External functions *
 *====================*/
EXTERN RT_MODEL * gjwwzq(void);

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
EXTERN void MdlInitializeSizes(void);
EXTERN void MdlInitializeSampleTimes(void);
EXTERN void MdlStart(void);
EXTERN void MdlOutputs(int_T tid);
EXTERN void MdlUpdate(int_T tid);
EXTERN void MdlTerminate(void);
static void initialize_sizes(RT_MODEL * S)
{
  MdlInitializeSizes();
}

static void initialize_sample_times(RT_MODEL * S)
{
  MdlInitializeSampleTimes();
}

static void start(RT_MODEL * S)
{
  MdlStart();
}

static void outputs(RT_MODEL * S, int_T tid)
{
  MdlOutputs(tid);
}

static void update(RT_MODEL * S, int_T tid)
{
  MdlUpdate(tid);
}

static void terminate(RT_MODEL * S)
{
  MdlTerminate();
}

EXTERN void rt_ODECreateIntegrationData(RTWSolverInfo *si);
EXTERN void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);
static void rt_CreateIntegrationData(RT_MODEL * S)
{
  rt_ODECreateIntegrationData(rtmGetRTWSolverInfo(S));
}

static void rt_UpdateContinuousStates(RT_MODEL * S)
{
  rt_ODEUpdateContinuousStates(rtmGetRTWSolverInfo(S));
}

/*==================================*
 * Global data local to this module *
 *==================================*/
static struct {
  int_T isrOverrun;
  boolean_T stopExecutionFlag;
  boolean_T startedFlag;
  char message[256];
  char submessage[192];
} GBLbuf;

EXTERN void rtExtModeStart(void);
EXTERN void rtExtModeQuarcCleanup(int_T numSampTimes);
EXTERN boolean_T rtExtModeQuarcStartup(RTWExtModeInfo *ei,
  int_T num_sample_times,
  boolean_T *stopReqPtr,
  int_T priority,
  int32_T stack_size,
  boolean_T enable_printing);
EXTERN void rtExtModeQuarcParseArgs(int_T argc,
  const char_T *argv[],
  const char_T *default_uri);
EXTERN void rtExtSetReturnStatus(const char * message);
static void rtExtModeSingleTaskUpload(RT_MODEL * S)
{
  int stIdx;
  rtExtModeUploadCheckTrigger(rtmGetNumSampleTimes(S));
  for (stIdx=0; stIdx < 2; stIdx++) {
    if (rtmIsSampleHit(S, stIdx, 0     /*unused*/
                       )) {
      rtExtModeUpload(stIdx, rtmGetTaskTime(S,stIdx));
    }
  }
}

EXTERN void
  _do_assertion(const char * expression, const char * file_name, int line_number)
{
  string_format(GBLbuf.message, sizeof(GBLbuf.message),
                "Assertion in %s at line %d: (%s) is false",
                file_name, line_number, expression);
  rtmSetErrorStatus(gjwwzq_M, GBLbuf.message);
}

/* Function: rtOneStep ========================================================
 *
 * Abstract:
 *      Perform one step of the model.
 */
static void rt_OneStep(RT_MODEL *S)
{
  real_T tnext;

  /***********************************************
   * Check and see if error status has been set  *
   ***********************************************/
  if (rtmGetErrorStatus(S) != NULL) {
    GBLbuf.stopExecutionFlag = 1;
    return;
  }

  /* enable interrupts here */
  tnext = rt_SimGetNextSampleHit();
  rtsiSetSolverStopTime(rtmGetRTWSolverInfo(S),tnext);
  outputs(S, 0);
  rtExtModeSingleTaskUpload(S);
  update(S, 0);
  rt_SimUpdateDiscreteTaskSampleHits(rtmGetNumSampleTimes(S),
    rtmGetTimingData(S),
    rtmGetSampleHitPtr(S),
    rtmGetTPtr(S));
  if (rtmGetSampleTime(S,0) == CONTINUOUS_SAMPLE_TIME) {
    rt_UpdateContinuousStates(S);
  }

  rtExtModeCheckEndTrigger();
}                                      /* end rtOneStep */

static void
  cleanup_sleep_mode(void * argument)
{
  qsched_set_sleep_mode(SLEEP_MODE_ENABLED);
}

static void
  control_c_handler(int signal_number)
{
  /*
     Set a global flag to stop model execution and
     terminate cleanly. Signal the start semaphore
     to make the model exit if it is waiting for
     a start signal from the host.
   */
  GBLbuf.stopExecutionFlag = 1;
  rtExtModeStart();
  hil_task_stop(gjwwzq_DW.HILReadEncoderTimebase_Task)
    ;
}

int
  main(int argc, char * argv[])
{
  RT_MODEL * S;
  const char * status;
  int_T count;
  int exit_code = exit_success;
  boolean_T parseError = false;
  real_T final_time = -2;              /* Let model select final time */
  real_T delay_time = 0;              /* No delay before model is initialized */
  int scheduling_priority;
  struct qsched_param scheduling;
  t_error result;

  /*
   * Make controller threads higher priority than external mode threads:
   *   ext_priority = priority of lowest priority external mode thread
   *   min_priority = minimum allowable priority of lowest priority model task
   *   max_priority = maximum allowable priority of lowest priority model task
   */
  int ext_priority = qsched_get_priority_min(QSCHED_FIFO);
  int min_priority = ext_priority + 2;
  int max_priority = qsched_get_priority_max(QSCHED_FIFO) - 0;
  qsigset_t signal_set;
  qsigaction_t action;
  int_T stack_size = 0;                /* default stack size */
  (void) ssPrintf("Entered main(argc=%d, argv=%p)\n", argc, argv);
  for (count = 0; count < argc; count++) {
    (void) ssPrintf("  argv[%d] = %s\n", count, argv[count]);
  }

  scheduling_priority = 2;             /* default priority */
  if (scheduling_priority < min_priority) {
    scheduling_priority = min_priority;
  } else if (scheduling_priority > max_priority) {
    scheduling_priority = max_priority;
  }

  /*
   * Parse the standard RTW parameters.  Let all unrecognized parameters
   * pass through to external mode for parsing.  NULL out all args handled
   * so that the external mode parsing can ignore them.
   */
  for (count = 1; count < argc; ) {
    const char *option = argv[count++];
    char extraneous_characters[2];
    if ((strcmp(option, "-tf") == 0) && (count != argc)) {/* final time */
      const char * tf_argument = argv[count++];
      double time_value;
      /* use a double for the sscanf since real_T may be a float or a double depending on the platform */
      argv[count-2] = NULL;
      argv[count-1] = NULL;
      if (strcmp(tf_argument, "inf") == 0) {
        time_value = RUN_FOREVER;
      } else {
        int items = sscanf(tf_argument, "%lf%1s", &time_value,
                           extraneous_characters);
        if ((items != 1) || (time_value < 0.0) ) {
          (void) fprintf(stderr,
                         "Final time must be a positive, real value or inf.\n");
          parseError = true;
          break;
        }
      }

      final_time = (real_T) time_value;
    } else if ((strcmp(option, "-td") == 0) && (count != argc)) {
                               /* delay time (delays initialization of model) */
      const char * td_argument = argv[count++];
      double time_value;
      /* use a double for the sscanf since real_T may be a float or a double depending on the platform */
      int items;
      argv[count-2] = NULL;
      argv[count-1] = NULL;
      items = sscanf(td_argument, "%lf%1s", &time_value, extraneous_characters);
      if ((items != 1) || (time_value < 0.0) ) {
        (void) fprintf(stderr, "Delay time must be a positive, real value.\n");
        parseError = true;
        break;
      }

      delay_time = (real_T) time_value;
    } else if ((strcmp(option, "-pri") == 0) && (count != argc)) {/* base priority */
      const char * pri_argument = argv[count++];
      int priority;
      /* use an int for the sscanf since int_T may be the wrong size depending on the platform */
      int items;
      argv[count-2] = NULL;
      argv[count-1] = NULL;
      items = sscanf(pri_argument, "%d%1s", &priority, extraneous_characters);
      if ((items != 1) || (priority < min_priority) ) {
        (void) fprintf(stderr,
                       "Priority must be a greater than or equal to %d.\n",
                       min_priority);
        parseError = true;
        break;
      }

      if (priority > max_priority) {
        (void) fprintf(stderr, "Priority must be less than or equal to %d.\n",
                       max_priority);
        parseError = true;
        break;
      }

      scheduling_priority = priority;
    } else if ((strcmp(option, "-ss") == 0) && (count != argc)) {/* stack size */
      const char * stack_argument = argv[count++];
      int stack;
      /* use an int for the sscanf since int_T may be the wrong size depending on the platform */
      int items;
      argv[count-2] = NULL;
      argv[count-1] = NULL;
      items = sscanf(stack_argument, "%d%1s", &stack, extraneous_characters);
      if ((items != 1) || (stack < QTHREAD_STACK_MIN) ) {
        (void) fprintf(stderr,
                       "Stack size must be a integral value greater than or equal to %d.\n",
                       QTHREAD_STACK_MIN);
        parseError = true;
        break;
      }

      stack_size = (int_T)stack;
    } else if ((strcmp(option, "-d") == 0) && (count != argc)) {/* current directory */
      const char * path_name = argv[count++];
      _chdir(path_name);
      argv[count-2] = NULL;
      argv[count-1] = NULL;
    }
  }

  rtExtModeQuarcParseArgs(argc, (const char **) argv, "shmem://gjwwzq:1");

  /*
   * Check for unprocessed ("unhandled") args.
   */
  for (count = 1; count < argc; count++) {
    if (argv[count] != NULL) {
      (void) fprintf(stderr, "Unexpected command line argument: \"%s\".\n",
                     argv[count]);
      parseError = true;
    }
  }

  if (parseError) {
    (void) fprintf(stderr,
                   "\nUsage: gjwwzq -option1 val1 -option2 val2 -option3 ...\n\n");
    (void) fprintf(stderr,
                   "\t-tf  20               - sets final time to 20 seconds\n");
    (void) fprintf(stderr,
                   "\t-td  5                - sets delay time to 5 seconds\n");
    (void) fprintf(stderr,
                   "\t-d   C:\\data          - sets current directory to C:\\data\n");
    (void) fprintf(stderr,
                   "\t-pri 5                - sets the minimum thread priority\n");
    (void) fprintf(stderr,
                   "\t-ss  65536            - sets the stack size for model threads\n");
    (void) fprintf(stderr,
                   "\t-w                    - wait for host to connect before starting\n");
    (void) fprintf(stderr,
                   "\t-uri shmem://mymodel  - set external mode URL to \"shmem://mymodel\"\n");
    (void) fprintf(stderr, "\n");
    return (exit_failure);
  }

  /****************************
   * Initialize global memory *
   ****************************/
  (void)memset(&GBLbuf, 0, sizeof(GBLbuf));

  /* Implement a delay before starting the model */
  if (delay_time > 0) {
    t_timeout sleep_interval;
    sleep_interval.seconds = (t_long) delay_time;
    sleep_interval.nanoseconds = (t_int) (delay_time - sleep_interval.seconds) *
      1000000000L;
    sleep_interval.is_absolute = false;
    qtimer_sleep(&sleep_interval);
  }

  /************************
   * Initialize the model *
   ************************/
  S = gjwwzq();
  if (rtmGetErrorStatus(S) != NULL) {
    (void) fprintf(stderr, "Error during model registration: %s\n",
                   rtmGetErrorStatus(S));
    return (exit_failure);
  }

  if (final_time >= 0.0 || final_time == RUN_FOREVER) {
    rtmSetTFinal(S,final_time);
  } else {
    rtmSetTFinal(S,rtInf);
  }

  action.sa_handler = control_c_handler;
  action.sa_flags = 0;
  qsigemptyset(&action.sa_mask);
  qsigaction(SIGINT, &action, NULL);
  qsigaction(SIGBREAK, &action, NULL);
  qsigemptyset(&signal_set);
  qsigaddset(&signal_set, SIGINT);
  qsigaddset(&signal_set, SIGBREAK);
  qthread_sigmask(QSIG_UNBLOCK, &signal_set, NULL);
  initialize_sizes(S);
  initialize_sample_times(S);
  status = rt_SimInitTimingEngine(rtmGetNumSampleTimes(S),
    rtmGetStepSize(S),
    rtmGetSampleTimePtr(S),
    rtmGetOffsetTimePtr(S),
    rtmGetSampleHitPtr(S),
    rtmGetSampleTimeTaskIDPtr(S),
    rtmGetTStart(S),
    &rtmGetSimTimeStep(S),
    &rtmGetTimingData(S));
  if (status != NULL) {
    (void) fprintf(stderr, "Failed to initialize sample time engine: %s\n",
                   status);
    return (exit_failure);
  }

  qsched_set_sleep_mode(SLEEP_MODE_DISABLED);
  qthread_cleanup_push(cleanup_sleep_mode, NULL);
  rt_CreateIntegrationData(S);
  fflush(stdout);
  if (rtExtModeQuarcStartup(rtmGetRTWExtModeInfo(S),
       rtmGetNumSampleTimes(S),
       &rtmGetStopRequested(S),
       ext_priority,                   /* external mode thread priority */
       stack_size,
       SS_HAVESTDIO)) {
    (void) ssPrintf("\n** starting the model **\n");
    start(S);
    if (rtmGetErrorStatus(S) == NULL) {
      /*************************************************************************
       * Execute the model.
       *************************************************************************/
      if (rtmGetTFinal(S) == RUN_FOREVER) {
        (void) ssPrintf("\n**May run forever. Model stop time set to infinity.**\n");
      }

      /* Perform task-specific initialization */
      scheduling.sched_priority = scheduling_priority;
      qthread_setschedparam(qthread_self(), QSCHED_FIFO, &scheduling);
      (void) ssPrintf("Creating main thread with priority %d and period %g...\n",
                      scheduling_priority, rtmGetStepSize(S));
      fflush(stdout);
      result = hil_task_start(gjwwzq_DW.HILReadEncoderTimebase_Task, (t_clock)
        gjwwzq_P.HILReadEncoderTimebase_Clock, 500.0, -1)
        ;
      if (result == 0) {
        /* Enter the periodic loop */
        while (true) {
          if (GBLbuf.stopExecutionFlag || rtmGetStopRequested(S)) {
            break;
          }

          if (rtmGetTFinal(S) != RUN_FOREVER && rtmGetTFinal(S) - rtmGetT(S) <=
              rtmGetT(S)*DBL_EPSILON) {
            break;
          }

          rt_OneStep(S);
        }

        if (rtmGetStopRequested(S) == false && rtmGetErrorStatus(S) == NULL) {
          /* Execute model last time step if final time expired */
          rt_OneStep(S);
        }

        /* disarm the timebase */
        hil_task_stop(gjwwzq_DW.HILReadEncoderTimebase_Task)
          ;
        (void) ssPrintf("Main thread exited\n");
      } else {
        msg_get_error_messageA(NULL, result, GBLbuf.submessage, sizeof
          (GBLbuf.submessage));
        string_format(GBLbuf.message, sizeof(GBLbuf.message),
                      "Unable to start timebase. %s", GBLbuf.submessage);
        rtmSetErrorStatus(S, GBLbuf.message);
      }

      GBLbuf.stopExecutionFlag = 1;

      /* Perform task-specific cleanup */
    }
  } else {
    rtmSetErrorStatus(S, "Unable to initialize external mode.");
  }

  rtExtSetReturnStatus(rtmGetErrorStatus(S));
  rtExtModeQuarcCleanup(rtmGetNumSampleTimes(S));

  /********************
   * Cleanup and exit *
   ********************/
  if (rtmGetErrorStatus(S) != NULL) {
    (void) fprintf(stderr, "%s\n", rtmGetErrorStatus(S));
    exit_code = exit_failure;
  }

  (void) ssPrintf("Invoking model termination function...\n");
  terminate(S);
  qthread_cleanup_pop(1);
  (void) ssPrintf("Exiting real-time code\n");
  return (exit_code);
}
