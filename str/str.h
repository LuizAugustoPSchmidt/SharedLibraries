#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int purgechar(char *str, const size_t len, const char tar);
int streq(const char* str1, const char* str2);
int strpurge(char* str, const char* tar);
int strsubst(char* str, const char* oldsubstr, const char* newsubstr);
