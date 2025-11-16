#include "vector.h"

#include <string.h>

static const size_t INITIAL_CAPACITY = 4, EXPAND_COEF = 2;

int _expand(Vector * v)
{
    if (NULL == v || NULL == v->_data)
    {
        return 0;
    }

    void * new_data = realloc(v->_data, EXPAND_COEF * v->_capacity * v->_elem_size);
    if (NULL == new_data)
    {
        return 1;
    }

    v->_data = new_data;
    v->_capacity *= EXPAND_COEF;

    return 0;
}

Vector create_vector(size_t type_size)
{
    Vector new_vector;
    new_vector._data = malloc(INITIAL_CAPACITY * type_size);
    if (NULL == new_vector._data) 
    {
        return new_vector;
    }
    new_vector._capacity = INITIAL_CAPACITY;
    new_vector._size = 0;
    new_vector._elem_size = type_size;

    return new_vector;
}

void destroy_vector(Vector * v)
{
    if ((NULL == v) || (NULL == v->_data))
    {
        return;
    }

    free(v->_data);
    v->_size = 0;
    v->_capacity = 0;

    return;
}

size_t vector_length(Vector * v)
{
    if (NULL == v)
    {
        return 0;
    }

    return v->_size;
}

void * vector_get_by_id(Vector * v, size_t id)
{
    if ((NULL == v) || (v->_data == NULL) || (id >= v->_size))
    {
        return NULL;
    }

    return v->_data + (id * v->_elem_size);
}

int push_vector(Vector * v, void * elem)
{
    if (NULL == elem)
    {
        return 1;
    }

    if (v->_capacity == v->_size)
    {
        if (_expand(v))
        {
            return 1;
        }
    }

    memcpy(v->_data + (v->_size * v->_elem_size), elem, v->_elem_size);
    v->_size++;

    return 0;
}

void * pop_vector(Vector * v)
{
    if ((NULL == v) || (NULL == v->_data) || (0 == v->_size))
    {
        return NULL;
    }

    v->_size--;
    
    return v->_data + v->_size * v->_elem_size;
}

int is_vector_valid(Vector * v)
{
    return (NULL != v) && (NULL != v->_data);
}
