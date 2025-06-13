#include "../includes/vec.h"
#include <colors.h>
#include <stdbool.h>

[[nodiscard]] vector_t new_vec(size_t size) {
    vector_t vec;

    vec.capacity = 0;
    vec.length = 0;
    vec.element_size = size;

    vec._return_area.has_return = true;
    vec._return_area.area = calloc(1, vec.element_size);
    assert_valid_ptr(vec._return_area.area);

    vec.data = calloc(VEC_CHUNK, size);
    assert_valid_ptr(vec.data);

    return vec;
}

vector_t vec_push(vector_t *vec, void *data) {
    if (vec->capacity == 0) {
        void *tmp = realloc(vec->data, VEC_CHUNK * vec->element_size);
        assert_valid_ptr(tmp);

        vec->capacity = VEC_CHUNK;
        vec->data = tmp;
    }
    if (vec->length == vec->capacity) {
        void *tmp = realloc(vec->data, vec->capacity * vec->element_size * 2);
        assert_valid_ptr(tmp);

        vec->capacity *= 2;
        vec->data = tmp;
    }

    memcpy(vec->data + vec->length * vec->element_size, data,
           vec->element_size);

    vec->length++;

    return *vec;
}

void *vec_pop(vector_t *vec) {
    void *ret = vec->data + (vec->length - 1) * vec->element_size;
    vec->length--;
    return ret;
}

vector_t vec_prepend(vector_t *vec, void *data) {
    if (vec->capacity == 0) {
        void *tmp = realloc(vec->data, VEC_CHUNK * vec->element_size);
        assert_valid_ptr(tmp);
        vec->data = tmp;
    }
    if (vec->length == vec->capacity) {
        void *tmp = realloc(vec->data, vec->capacity * vec->element_size * 2);
        assert_valid_ptr(tmp);

        vec->capacity *= 2;
        vec->data = tmp;
    }

    memmove(vec->data + vec->element_size, vec->data,
            vec->length * vec->element_size);
    memcpy(vec->data, data, vec->element_size);
    return *vec;
}

void *vec_popfront(vector_t *vec) {
    char *ret = calloc(vec->element_size, 1); // MEMORY LEAK
    memcpy(ret, vec->data, vec->element_size);
    vec->length--;

    memmove(vec->data, vec->data + vec->element_size,
            vec->element_size * vec->length);
    return (void *)ret;
}
