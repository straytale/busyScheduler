#ifndef CONF_H
#define CONF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "list.h"
#include "common.h"

// task's name
#define DISP (0)
#define taskA (1)
#define taskB (2)
#define taskC (3)
#define NUM_OF_TASK (4)

// task's state
#define SLEEPING (0)
#define RUNNINNG (1)
#define WAITING (2)
#define NUM_OF_STATE (3)

typedef struct
{
    char taskName[10];
    U8 taskID;
    U8 state;
    U8 (*request_func)(void);
    U8 (*main_func)(void);
} Task;

typedef struct
{
} Dispatcher;

typedef struct
{
    Task tasks[NUM_OF_TASK];
    List lists[NUM_OF_STATE];
    U32 start_timer;
} Scheduler;

static inline U32 current_time(void)
{
    return time(NULL);
}

static inline void delay_ms(int ms)
{
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000;
    nanosleep(&ts, NULL);
}

static inline void info_log(char *msg)
{
    struct tm *tm_info;
    char buffer[20];

    U32 timestamp = current_time();
    tm_info = localtime((time_t *)&timestamp);

    strftime(buffer, sizeof(buffer), "20%y-%m-%d %H:%M.%S", tm_info);
    printf("[%s] %s\n", buffer, msg);
}

// task's init func
void task_disp_init_func(Task *task);
void task_A_init_func(Task *task);
void task_B_init_func(Task *task);
void task_C_init_func(Task *task);
/* newtask */

// task's req func
U8 task_A_request_func(void);
U8 task_B_request_func(void);
U8 task_C_request_func(void);
/* newtask */

// disp's req func: TODO job
void disp_task_request(U8 taskID);

// scheduler
void exec_task(U8 taskID);

#endif