#include "task.h"

#include <stdlib.h>

Task create_task(uint64_t data_size)
{
    Task new_task;
    new_task._data = malloc((size_t)data_size * sizeof(size_t));
    if (NULL == new_task._data)
    {
        return new_task;
    }
    new_task._size = (uint64_t)data_size;

    return new_task;
}

void destroy_task(Task * task)
{
    if (NULL != task->_data)
    {
        free(task->_data);
        task->_data = NULL;
    }
    task->_size = 0;
}

