#ifndef __TASK_LIST_H
#define __TASK_LIST_H


#include "utils/vector/vector.h"

struct TaskList
{
    Vector _storage;
};

TaskList init_task_list();
void destroy_stask_list();



#endif // __TASK_LIST_H
