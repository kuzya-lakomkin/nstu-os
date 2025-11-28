#include "vector.h"

#include <stdio.h>

int comp(void * a, void * b)
{
    return *(int *)a - *(int *)b;
}

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

    for (size_t i = 0; i < v2._size; ++i)
    {
        size_t val = *(int *)vector_get_by_id(&v2, i);
    }

    for (size_t i = 0; i < 3; ++i)
    {
        pop_vector(&v2);
    }

    printf("\n");

    for (size_t i = 0; i < v2._size; ++i)
    {
        size_t val = *(int *)vector_get_by_id(&v2, i);
        printf("%lu ", val);
    }

    int a1 = 2020, a2 = 3030;
    
    destroy_vector(&v2);

    Vector v3 = create_vector(sizeof(int));

    int val = 60;
    push_vector(&v3, (void *)&val);
    val = 5;
    push_vector(&v3, (void *)&val);
    val = 7;
    push_vector(&v3, (void *)&val);
    val = 43;
    push_vector(&v3, (void *)&val);
    val = 51;
    push_vector(&v3, (void *)&val);
    val = 152;
    push_vector(&v3, (void *)&val);
    val = -3;
    push_vector(&v3, (void *)&val);
    val = 11;
    push_vector(&v3, (void *)&val);
    
    printf("\n");
    for (size_t i = 0; i < v3._size; ++i)
    {
        int val = *(int *)vector_get_by_id(&v3, i);
        printf("%d ", val);
    }
    
    printf("v_size: %lu\n", v._size);
    sort_vector(&v3, 0, v3._size - 1, comp);
    for (size_t i = 0; i < v3._size; ++i)
    {
        int val = *(int *)vector_get_by_id(&v3, i);
        printf("%d ", val);
    }

    destroy_vector(&v3);

    Vector v4 = create_vector(sizeof(int));
    for (int i = 0; i < 10; ++i)
    {
        push_vector(&v4, &i);
    }

    Vector v5;
    copy_vector(&v5, &v4);

    for (size_t i = 0; i < 10; ++i)
    {
        printf("%d %d\n", *(int *)vector_get_by_id(&v4, i), *(int *)vector_get_by_id(&v5, i));
    }
}
