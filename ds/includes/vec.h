#include <errors.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define VEC_CHUNK 64

typedef struct {
    bool has_return;
    void *area;
} _return_area_t;

typedef struct vector {
    size_t capacity;     // The total amount of space allocated
    size_t length;       // The amount of occupied space
    size_t element_size; // The size of the element type

    void *data; // The data itself, on the Heap
    _return_area_t _return_area;
} vector_t;

vector_t new_vec(size_t size);

vector_t vec_push(vector_t *vec, void *data);
void *vec_pop(vector_t *vec);

vector_t vec_prepend(vector_t *vec, void *data);
void *vec_popfront(vector_t *vec);
