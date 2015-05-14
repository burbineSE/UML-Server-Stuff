#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[]){
  int i;
  char *CLarg;
    
  for(i = 1; i < argc; i++){
    CLarg = argv[i];
        
    if (CLarg == ">"){
      printf("> case\n");
    }
  }
  return 0;
}
