#ifndef __TASK_H
#define __TASK_H

#include <inttypes.h>

struct Task
{
    int * _data;
    uint32_t _data_slice;
    uint64_t _size;

    struct Task (*create_task)(uint64_t, uint16_t);
    void (*start_task)(Task * task);
    void (*stop_task)(Task * task);
    void (*destroy_task)(struct Task *);
};

typedef struct Task Task;

#endif // __TASK_H