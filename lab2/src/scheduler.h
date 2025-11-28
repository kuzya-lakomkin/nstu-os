#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include "task.h"
#include "utils/vector/vector.h"

struct Scheduler
{
    int a;
};

typedef struct Scheduler Scheduler;

Scheduler create_sched(void);
void destroy_sched(Scheduler * sched);

void sched_add_task(Scheduler *, Task * task);

void sched_start(Scheduler * sched);


#endif // __SCHEDULER_H