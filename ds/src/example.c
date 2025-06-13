#include "../includes/vec.h"

int main() {
    vector_t vec = new_vec(sizeof(int));
    int test = 0xffff;

    vec = vec_push(&vec, &test);
    printf("%d\n", *(int *)vec_pop(&vec));
    return 0;
}
