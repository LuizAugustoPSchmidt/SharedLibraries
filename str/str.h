#define DEBUG

#include <assert.h>
#include <errors.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x) \
    do {               \
    } while (0)
#endif

#define STD_STRING_CAP 1024

typedef struct string {
    size_t length, capacity;
    char *str;
} string;

bool substrcontains(const char *base, const char *tar);
int purgechar(char *str, const size_t len, const char tar);
int streq(const char *str1, const char *str2);
int strpurge(char *str, const char *tar);
int strsubst(char *str, const char *oldsubstr, const char *newsubstr);
int countoccurs(char *base, const char *tar);

string StrNew(char *ptr);
string StrConcat(string a, string b);
string StrReplace(string base, const char *tar, const char *new);
