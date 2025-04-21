
#include "conf.h"

Scheduler sche;

void exec_task(U8 taskID)
{
    if (search_list(&sche.lists[SLEEPING], taskID))
    {
        remove_list(&sche.lists[SLEEPING], taskID);
        push_list(&sche.lists[RUNNINNG], taskID);
    }
}

void run(void)
{
    sche.start_timer = current_time();
    info_log(">> Scheduler start");

    // init all the lists
    info_log(">> Init SLEEPING, RUNNING, WAITING list");
    init_list(&sche.lists[SLEEPING], "SLEEPING LIST");
    init_list(&sche.lists[RUNNINNG], "RUNNINNG LIST");
    init_list(&sche.lists[WAITING], "WAITING LIST");

    // init all the tasks
    info_log(">> Init All tasks");
    task_disp_init_func(&sche.tasks[DISP]);
    task_A_init_func(&sche.tasks[taskA]);
    task_B_init_func(&sche.tasks[taskB]);
    task_C_init_func(&sche.tasks[taskC]);
    /* newtask */
    push_list(&sche.lists[RUNNINNG], DISP);
    push_list(&sche.lists[RUNNINNG], taskA);
    push_list(&sche.lists[RUNNINNG], taskB);
    push_list(&sche.lists[RUNNINNG], taskC);
    /* newtask */

    // exec the disp task
    exec_task(DISP);

    // while(TRUE)
    for (int i = 0; i < 100; i++)
    {
        // pick a task from RUNNING list
        U8 taskID = pop_list(&sche.lists[RUNNINNG]);
        if (taskID == NOTHING)
        {
            continue;
        };
        char buffer[50];
        snprintf(buffer, sizeof(buffer), ">> Executing %s", sche.tasks[taskID].taskName);
        info_log(buffer);

        // run the task
        U8 result = sche.tasks[taskID].main_func();
        push_list(&sche.lists[result], taskID);
    }
    info_log(" MISSION COMPLETE!");
}

int main(void)
{
    run();
}