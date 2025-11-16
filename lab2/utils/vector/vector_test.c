#include "vector.h"

#include <stdio.h>

int main(void)
{
    Vector v = create_vector(sizeof(int));
    printf("Vector length: %lu\n", vector_length(&v));

    int value = 1;
    push_vector(&v, (void *)&value);
    printf("Vector length: %lu\n", vector_length(&v));
    printf("vector val: %d\n", *(int *)vector_get_by_id(&v, 0));

    destroy_vector(&v);

    size_t count = 10;
    Vector v2 = create_vector(sizeof(size_t));
    for (size_t i = 0; i < count; ++i)
    {
        push_vector(&v2, &i);
    }

    for (size_t i = 0; i < count; ++i)
    {
        size_t val = *(int *)vector_get_by_id(&v2, i);
        printf("%lu ", val);
    }

    destroy_vector(&v2);
}