#include "colors.h"

int termcolor(COLOR color){
  return printf("\033[%dm", color);
}

int cprintf(COLOR color, const char* fmt, ...){
  va_list args;
  va_start(args, fmt);

  termcolor(color);

  int a = vprintf(fmt, args);
  va_end(args);

  termcolor(WHITE);
  return a;
}

int cperror(COLOR color, const char* fmt){
  char buf[1024];
  snprintf(buf, sizeof(buf), "\033[%dm%s\033[%dm", color, fmt, WHITE);
  return fprintf(stderr, "%s", buf);
}
