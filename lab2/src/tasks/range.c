#include "utils/vector/vector.h"
#include "src/task.h"

#include <stdio.h>

int find_by_range(Task * t);

int task_fn(Task * t)
{
    return find_by_range(t);
}

int find_by_range(Task * t)
{
    if ((vector_length(&(t->_params)) != 2) || 
        (vector_type_size(&(t->_params)) != sizeof(int)))
    {
        return 1;
    }

    printf("started!\n");

    Vector * arr = &(t->_data);
    is_vector_valid(arr);
    int d1 = *(int *)vector_get_by_id(&t->_params, 0);
    int d2 = *(int *)vector_get_by_id(&t->_params, 1);
    int min = (d1 < d2) ? d1 : d2;
    int max = d1 + d2 - min;
    Vector res = create_vector(sizeof(int));
    if (!is_vector_valid(&res))
    {
        return 1;
    }
    printf("lol %lu\n", vector_length(arr));
    for (size_t i = 0; i < vector_length(arr); ++i)
    {
        int curr = *(int *)vector_get_by_id(arr, i);
        if ((min <= curr) && (curr <= max))
        {
            if (1 == push_vector(&res, (void *)&curr))
            {
                return 1;
            }
        }
    }
    t->_result = res;

    return 0;
}
