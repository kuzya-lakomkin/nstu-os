#ifndef __TASK_H
#define __TASK_H

#include "utils/vector/vector.h"

#include <inttypes.h>

struct Scheduler;
typedef struct Scheduler Scheduler;

struct Task
{
    Vector _data;
    Vector _result;
    Scheduler * _sched;
    void (*_callback)(Task *);
};

typedef struct Task Task;

int init_task(
    Task * task,
    Scheduler * sched,
    void (*task_callback)(Task *),
    void (*fill_policy)(Vector *)
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

#endif // __TASK_H