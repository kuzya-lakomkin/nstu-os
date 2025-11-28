#include "task.h"

#include <time.h>
#include <stdlib.h>

typedef int TaskDataElem;

static int random_task_vector(
    Vector * v,
    size_t cnt
)
{
    if (NULL == v)
    {
        return 1;
    }

    srand(time(NULL));
    for (size_t i = 0; i < cnt; ++i)
    {
        int new_elem = rand() % 1024;
        if (push_vector(v, &new_elem))
        {
            return 1;
        }
    }

    return 0;
}

int init_task(
    Task * task,
    Scheduler * sched,
    int (*task_callback)(Task *),
    size_t data_size
)
{
    if ((NULL == task) || (NULL == sched) || 
        (NULL == task_callback))
    {
        return 1;
    }

    task->_sched = sched;
    task->_callback = task_callback;
    
    task->_data = create_vector(sizeof(TaskDataElem));
    if (!is_vector_valid(&(task->_data)))
    {
        return 1;
    }
    if (random_task_vector(&(task->_data), data_size))
    {
        return 1;
    }
    task->_params = create_null_vector(sizeof(TaskDataElem));

    return 0;
}

void deinit_task(
    Task * task
)
{
    if (NULL == task)
    {
        return;
    }

    destroy_vector(&(task->_data));
    if (!is_vector_null(&task->_result))
    {
        destroy_vector(&task->_result);
    }

    task->_sched = NULL;
    task->_callback = NULL;
}

int set_task_params(
    Task * task,
    Vector * params
)
{
    if ((NULL == task) || !is_vector_valid(params))
    {
        return 1;
    }

    return copy_vector(&task->_params, params);
}

int run_task(
    Task * task
)
{
    if ((NULL == task) || (NULL == task->_sched) || 
        (NULL == task->_callback))
    {
        return 1;
    }
    task->_callback(task);

    return 0;
}

int get_task_result(
    const Task * task,
    Vector * result
)
{
    if ((NULL == task) || (NULL == result))
    {
        return 1;
    }
    *result = task->_result;

    return 0;
}