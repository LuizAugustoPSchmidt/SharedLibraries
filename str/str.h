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
    char* str;
} string;

string StrNew(char* ptr);
string StrConcat(string a, string b);
string StrReplace(string base, const char* tar, const char* new);

bool StrEq(const string a, const string b);
