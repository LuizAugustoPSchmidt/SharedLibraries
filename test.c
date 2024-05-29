#include <str.h>
// #include <stdio.h>

int main(int argc, char **argv){
  char* str = argv[1], *tar = argv[2];
  // char *str = "Arara Verde", *tar = "ra";
  printf("%s\n", str);
  strpurge(str, tar);
  // purgechar(str, strlen(str), 'r');
  printf("%s\n", str);
  // printf("str: %p\ntar: %p\n", str, strstr(str,tar));
  return 0;
}
