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

/**
 * @todo: test 
 */
int vector_set_by_id(Vector * v, void * val, size_t id)
{
    if ((NULL == v) || (NULL == v->_data) || (id >= v->_size))
    {
        return 1;
    }
    memcpy(v->_data + (id + v->_elem_size), val, v->_elem_size);
    
    return 0;
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

/**
 * @todo: TEST
 */
int _swap(Vector * v, size_t i, size_t j)
{
    if ((NULL == v) || (NULL == v->_data) || 
        (i > v->_size) || (j > v->_size)
    )
    {
        return 1;
    }
    
    void * tmp = malloc(v->_elem_size);
    if (NULL == tmp)
    {
        return 1;
    }

    void * i_elem = vector_get_by_id(v, i);
    memcpy(tmp, i_elem, v->_elem_size);
    if (vector_set_by_id(v, vector_get_by_id(v, j), i))
    {
        return 1;
    }

    return vector_set_by_id(v, tmp, j);
}

/**
 * @todo: test
 */
size_t _partition_vector(Vector * v, size_t s, size_t e, int (*comp)(void *, void *))
{
    void * pivot = vector_get_by_id(v, (s + e) / 2);
    size_t i = s, j = e;
    while (1)
    {
        while (comp(vector_get_by_id(v, i), pivot) > 0)
        {
            i++;
        }
        while (comp(vector_get_by_id(v, j), pivot) < 0)
        {
            j++;
        }
        if (i >= j)
        {
            return j;
        }
        _swap(v, i, j);
    }
}

/**
 * @todo: test
 */
void sort_vector(Vector * v, size_t s, size_t e, int (*comp)(void *, void *))
{
    if ((NULL == v) || (NULL == v->_data) || 
        (v->_size < 2) || (s >= v->_size) || 
        (e >= v->_size) || (s > e) || (e - s < 2)
    ) {
        return;
    }
    size_t p = _partition_vector(v, s, e, comp);
    sort_vector(v, s, p, comp);
    sort_vector(v, p + 1, e, comp);
}
