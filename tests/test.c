#include <str.h>
#include <stdio.h>

int main(){
  char *str;
  strcpy(str, "Arara Verde");
  printf("%s\n", str);
  strsubst(str, "ra", "lfa");
  printf("%s\n", str);
  return 0;
}
