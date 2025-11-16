#include "vector/vector.h"

#include <stdio.h>

Vector find_by_range(Vector * arr, int d1, int d2)
{
    int min = (d1 < d2) ? d1 : d2;
    int max = d1 + d2 - min;
    Vector res = create_vector(sizeof(int));
    if (!is_vector_valid(&res))
    {
        return res;
    }

    for (size_t i = 0; i < arr->_size; ++i)
    {
        int curr = *(int *)vector_get_by_id(arr, i);
        if ((min <= curr) && (curr <= max))
        {
            if (1 == push_vector(&res, (void *)&curr))
            {
                return res;
            }
        }
    }

    return res;
}
