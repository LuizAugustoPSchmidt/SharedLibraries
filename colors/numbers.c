#include <stdio.h>

int main(){
  for(int i = 0; i < 100; i++){
    printf("\033[%dm%d ", i, i);
    if(i % 10 == 0 && i != 0){
      printf("\n");
    }
  }
  return 0;
}
