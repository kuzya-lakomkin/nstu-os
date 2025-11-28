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

size_t vector_length(
    Vector * v
);

size_t vector_type_size(
    Vector * v
);

void * vector_get_by_id(
    Vector * v,
    size_t id
);

int vector_set_by_id(
    Vector * v,
    void * val,
    size_t id
);

Vector create_vector(
    size_t type_size
);

Vector create_null_vector(
    size_t type_size
);

int copy_vector(
    Vector * dst,
    Vector * src
);

void destroy_vector(
    Vector * v
);

int push_vector(
    Vector * v,
    void * elem
);

void pop_vector(
    Vector * v
);

int is_vector_valid(
    Vector * v
);

void sort_vector(
    Vector * v, 
    size_t s, 
    size_t e, 
    int (*comp)(void *, void *)
);

int _swap(
    Vector * v, 
    size_t i, 
    size_t j
);

int is_vector_empty(
    Vector * v
);

int is_vector_null(
    Vector * v
);

#endif // __VECT)OR_H