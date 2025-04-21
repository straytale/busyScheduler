#include "conf.h"

U8 task_B_main_func(void)
{

    info_log("Initializing process...");
    volatile int sum = 0;
    info_log("Progress: [0%] Loading...");
    delay_ms(100);
    info_log("Progress: [20%] Loading...");
    delay_ms(100);
    info_log("Progress: [40%] Loading...");
    delay_ms(100);
    info_log("Progress: [60%] Loading...");
    delay_ms(100);
    info_log("Progress: [80%] Loading...");
    delay_ms(100);
    info_log("Progress: [100%] Complete.");

    info_log("Running data aggregation algorithm...");
    for (int i = 0; i < 1000; ++i)
    {
        sum += i * 42;
    }

    info_log("Validating data integrity...");
    sum ^= 0xCAFEBABE;
    delay_ms(50);

    info_log("Computing predictive model...");
    for (int i = 0; i < 800; ++i)
    {
        sum += (i % 11) * (i % 13);
    }
    delay_ms(50);

    info_log("Finalizing results...");
    sum = (sum << 2) ^ (sum >> 3);
    delay_ms(100);

    info_log("Operation complete, dispatching next task...");

    info_log("== task_B_main_func");
    info_log("== Task B say I will wakeup Task C");
    disp_task_request(taskC);
    return SLEEPING;
}

U8 task_B_request_func(void)
{
    info_log("== task_B_request_func");
    info_log("== wakeup task C");
    exec_task(taskC);
    return 0;
}

void task_B_init_func(Task *task)
{
    strncpy(task->taskName, "taskB", sizeof("taskB") - 1);
    task->taskID = taskB;
    task->state = SLEEPING;
    task->request_func = task_B_request_func;
    task->main_func = task_B_main_func;
}