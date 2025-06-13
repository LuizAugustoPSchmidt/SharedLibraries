#include "str.h"

string StrNew(char *ptr) {
    const size_t len = strlen(ptr);
    size_t cap = STD_STRING_CAP;

    if (len > cap) {
        cap = len;
    }

    char *buf = calloc(cap, sizeof(char));
    assert(buf != NULL);
    memcpy(buf, ptr, len);

    const string ret = {.str = buf, .capacity = cap, .length = len};
    return ret;
}

string StrConcat(string a, string b) {
    size_t total_len = a.length + b.length;
    size_t cap = STD_STRING_CAP;

    if (total_len > cap) {
        cap = total_len;
    }

    char *new_ptr = calloc(cap, sizeof(char));
    assert(new_ptr != NULL);

    memcpy(new_ptr, a.str, a.length);
    memcpy(new_ptr + a.length, b.str, b.length);

    string ret = {.str = new_ptr, .length = total_len, .capacity = cap};
    return ret;
}

string StrReplace(string base, const char *tar, const char *replacement) {
    const size_t tar_len = strlen(tar), replacement_len = strlen(replacement);
    const unsigned int count = countoccurs(base.str, tar);
    const size_t new_len = base.length - (tar_len * count) + (replacement_len * count);

    if (tar == NULL || replacement == NULL || tar_len == 0) {
        return base;
    }

    DEBUG_PRINT(("Determining new capacity...\n"));
    if (new_len > base.capacity) {
        base.capacity = new_len;
    }

    DEBUG_PRINT(("Reallocing...\n"));
    char *helper = calloc(base.capacity, sizeof(char));
    if (helper == NULL) {
        exit(EXIT_OOM);
    }
    memcpy(helper, base.str, base.length);
    base.str = helper;

    DEBUG_PRINT(("Calling strsubst with: \n\tcapacity: %zu\n\tlength: %zu\n", base.capacity, base.length));
    strsubst(base.str, tar, replacement);

    string ret = {.str = base.str, .capacity = base.capacity, .length = strlen(base.str)};
    return ret;
}

// This function has a really clear problem: it may write to a forbidden
// address. Maybe I can fix it with a few 'if' statements
int strsubst(char *str, const char *oldsubstr, const char *newsubstr) {
    if (!(str && oldsubstr && newsubstr)) {
        return -1;
    }
    char *aux;
    while ((aux = strstr(str, oldsubstr)) != NULL) {
        memmove(aux + strlen(newsubstr), aux + strlen(oldsubstr), strlen(aux + strlen(oldsubstr)) + 1);
        memcpy(aux, newsubstr, strlen(newsubstr));
    }
    return strlen(str);
}

int streq(const char *str1, const char *str2) { return (strcmp(str1, str2) == 0); }

int purgechar(char *str, const size_t len, const char tar) {
    if (str == NULL || len <= 0 || tar == '\0') {
        return -1;
    }
    for (unsigned int i = 0; i <= strlen(str); i++) {
        if (str[i] == tar) {
            memcpy(str + i, str + i + 1, len - i);
        }
    }
    return 0;
}

int strpurge(char *str, const char *tar) {
    if (str == NULL || tar == NULL) {
        return -1;
    }
    char *aux = NULL, *src = NULL;
    size_t tar_len = strlen(tar);
    if (tar_len == 0) {
        return -1;
    }
    while ((aux = strstr(str, tar)) != NULL) {
        src = aux + tar_len;
        memmove(aux, src, strlen(src) + 1);
    }
    return 0;
}

int countoccurs(char *base, const char *tar) {
    unsigned int count = 0;
    for (unsigned int offset = 0; offset < strlen(base); offset++) {
        if (substrcontains(base + offset, tar)) {
            count++;
        }
    }
    return count;
}

bool substrcontains(const char *base, const char *tar) {
    size_t tar_len = strlen(tar);

    for (unsigned int i = 0; i < tar_len; i++) {
        if (base[i] != tar[i]) {
            return false;
        }
    }
    return true;
}
