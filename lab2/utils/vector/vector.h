#ifndef __VECTOR_H
#define __VECTOR_H

#include <stdlib.h>

struct Vector
{
    void * _data;
    size_t _size;
    size_t _capacity;
    size_t _elem_size;
};

typedef struct Vector Vector;

size_t vector_length(Vector * v);
void * vector_get_by_id(Vector * v, size_t id);

Vector create_vector(size_t type_size);
void destroy_vector(Vector * v);

int push_vector(Vector * v, void * elem);
void * pop_vector(Vector * v);

int is_vector_valid(Vector * v);

#endif // __VECTOR_H