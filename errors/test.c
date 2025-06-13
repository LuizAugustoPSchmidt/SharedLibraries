#include "errors.h"

void foo() {
  void *ptr = NULL;
  assert_valid_ptr(ptr);
}

void bar() { printf("bar() executed\n"); }

int main() {
  foo();
  bar();
  printf("Before returning from main\n");
  return 0;
}
