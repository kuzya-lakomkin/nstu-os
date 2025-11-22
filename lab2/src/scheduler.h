#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include "task.h"
#include "vector/vector.h"

struct Scheduler
{
    Vector _task_list;

};

typedef struct Scheduler Scheduler;

Scheduler create_sched(void);
void destroy_sched(Scheduler * sched);

void sched_add_task(Scheduler *, Task * task);

void sched_start(Scheduler * sched);


#endif // __SCHEDULER_H