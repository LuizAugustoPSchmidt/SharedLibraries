#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef enum __attribute__((__packed__)){
  UNDERSCORE = 4,
  BLACK = 30,
  RED = 31,
  GREEN,
  YELLOW,
  BLUE,
  PINK,
  INDIGO,
  WHITE,
  BACK_BLACK = 40,
  BACK_RED,
  BACK_GREEN,
  BACK_YELLOW,
  BACK_BLUE,
  BACK_PINK,
  BACK_INDIGO,
  BACK_WHITE,
}COLOR;

int termcolor(COLOR color);
int cprintf(COLOR color, const char* fmt, ...);
int cperror(COLOR color, const char* fmt);
