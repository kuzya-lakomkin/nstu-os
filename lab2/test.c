#include "src/task.h"
#include "src/scheduler.h"

#include <dlfcn.h>
#include <stdio.h>

int main(void)
{
    const char dlname[30] = "range_task.so", callback_name[30] = "task_fn";

    void * dl = dlopen("./range_task.so", RTLD_LAZY);
    if (NULL == dl)
    {
        fprintf(stderr, "Failed to load the shared object: %s.\n%s\n", dlname, dlerror());
        return 1;
    }

    int (*callback)(Task *) = dlsym(dl, callback_name);
    if (NULL == callback)
    {
        fprintf(stderr, "Failed to a symbol: %s.\n", callback_name);
        return 1;
    }

    Task t;
    Scheduler s;
    init_task(&t, &s, callback, 200);

    Vector params = create_vector(sizeof(int));
    int d1 = 1, d2 = 300;
    push_vector(&params, &d1);
    push_vector(&params, &d2);
    set_task_params(&t, &params);
    destroy_vector(&params);

    printf("STOP %lu\n", t._data._size);

    run_task(&t);

    Vector res;
    if(get_task_result(&t, &res))
    {
        fprintf(stderr, "Failed to get the task result.\n");
    }

    for (size_t i = 0; i < vector_length(&res); ++i)
    {
        int val = *(int *)vector_get_by_id(&res, i);
        printf("%d ", val);
    }
    printf("\n");

    deinit_task(&t);
}
