#include "task.h"

#include <time.h>
#include <stdlib.h>

typedef int TaskDataElem;

static int random_task_vector(
    Vector * v
)
{
    if (NULL == v)
    {
        return 1;
    }

    srand(time(NULL));
    for (size_t i = 0; i < vector_length(v); ++i)
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
    void (*task_callback)(Task *),
    void (*fill_policy)(Vector *)
)
{
    if ((NULL == task) || (NULL == sched) || 
        (NULL == task_callback) || (NULL == fill_policy))
    {
        return 1;
    }

    task->_sched = sched;
    task->_callback = task_callback;
    
    task->_data = create_vector(sizeof(TaskDataElem));
    return !is_vector_valid(&(task->_data));
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
    destroy_vector(&(task->_result));

    task->_sched = NULL;
    task->_callback = NULL;
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

    return 1;
}