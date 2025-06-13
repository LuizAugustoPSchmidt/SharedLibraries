#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define assert_valid_ptr(ptr)                                                  \
  if (ptr == NULL) {                                                           \
    fprintf(stderr, "[%s: nullptr] %s\n", __func__, strerror(errno));          \
    exit(-1);                                                                  \
  }
#define assert_success_sys(sys)                                                \
  if (sys < 0) {                                                               \
    fprintf(stderr, "[%s: syscall] %s\n", __func__, strerror(errno));          \
    exit(-1);                                                                  \
  }

#define EXIT_OOM 129
