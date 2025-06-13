#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int makeJSON(void* object, const size_t size);
void* parseJSON(FILE* json);
