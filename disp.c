
#include "conf.h"

U8 task_disp_main_func(void)
{
    // do someting
    info_log("== task_disp_main_func");
    info_log("==> Send a task req to A");
    disp_task_request(taskA);

    // stay in RUNNING list
    return RUNNINNG;
}

U8 task_disp_request_func(void)
{
    // dp someting
    info_log("== task_disp_request_func");
    return 0;
}

void task_disp_init_func(Task *task)
{
    strncpy(task->taskName, "DISP", sizeof("DISP") - 1);
    task->taskID = DISP;
    task->state = SLEEPING;
    task->request_func = task_disp_request_func;
    task->main_func = task_disp_main_func;
}

void disp_task_request(U8 taskID)
{
    // search taskID table
    switch (taskID)
    {
    case DISP:
        task_disp_request_func();
        break;
    case taskA:
        task_A_request_func();
        break;
    case taskB:
        task_B_request_func();
        break;
    case taskC:
        task_C_request_func();
        break;
        /* newtask */

    default:
        break;
    }
}