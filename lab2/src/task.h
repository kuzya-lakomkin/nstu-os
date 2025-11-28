#ifndef __TASK_H
#define __TASK_H

#include "utils/vector/vector.h"

#include <stdlib.h>

struct Scheduler;
typedef struct Scheduler Scheduler;

struct Task;
typedef struct Task Task;

struct Task
{
    Vector _data, _result, _params;
    Scheduler * _sched;
    int (*_callback)(Task *);
};

int init_task(
    Task * task,
    Scheduler * sched,
    int (*task_callback)(Task *),
    size_t data_size
);

int set_task_params(
    Task * task,
    Vector * paraml
);

void deinit_task(
    Task * task
);

int run_task(
    Task * task
);

int get_task_result(
    const Task * task,
    Vector * result
);

int task_fn(
    Task * t
);

#endif // __TASK_H