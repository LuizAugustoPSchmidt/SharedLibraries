#include "str.h"

int strsubst(char* str, const char* oldsubstr, const char* newsubstr){
  // This function has a really clear problem: it may write to a forbidden address. Maybe I can fix it 
  // with a few 'if' statements
  char *aux;
  while((aux = strstr(str, oldsubstr)) != NULL){
    memmove(aux + strlen(newsubstr), aux + strlen(oldsubstr), strlen(aux + strlen(oldsubstr)));
  }
  return strlen(str);
}

int streq(const char* str1, const char* str2){
  return (strcmp(str1, str2) == 0);
}

int purgechar(char *str, const size_t len, const char tar){
  if(str == NULL || len <= 0 || tar == '\0'){
    return -1;
  }
  for(int i = 0; i <= strlen(str); i++){
    if(str[i] == tar){
      memcpy(str + i, str + i + 1, len - i);
    }
  }
  return 0;
}

// strpurge("Arara verde", "ra");
int strpurge(char *str, const char *tar){
  if(str == NULL || tar == NULL){
    return -1;
  }
  char *aux = NULL, *src = NULL;
  size_t tar_len = strlen(tar);
  if(tar_len == 0){
    return -1;
  }
  while((aux = strstr(str, tar)) != NULL){
    src = aux + tar_len;
    memmove(aux, src, strlen(src) + 1);
  }
  return 0;
}
