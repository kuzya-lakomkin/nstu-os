#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int type;

int main(void)
{
    size_t type_size = sizeof(type);
    size_t capacity = 4;
    size_t size = 0;
    void * arr = malloc(type_size * capacity);

    if (NULL == arr)
    {
        printf("Failed to allocate.");
    }

    for (size_t i = 0; i < capacity; ++i)
    {
        int new_elem = i * 2;
        void * new_elem_ptr = (void *)(&new_elem);
        printf("New element: %d\n", *(int *)new_elem_ptr);
        memcpy(arr + (size * type_size), new_elem_ptr, type_size);
        printf("Arr: %d\n", *(int *)(arr + i));
        printf("Pointer %p\n", arr + i);
        size++;
    }

    for (size_t i = 0; i < size; ++i)
    {
        void * curr = arr + (i * type_size);
        printf("Pointer %p", curr);
        printf("%lu: %d\n", i, *(int *)curr);
    }

    free(arr);
}
