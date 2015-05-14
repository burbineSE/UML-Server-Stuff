#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char *argv[]){

  int i, j, linecount, charcheck;  
  char dashO[] = "-o";
  int dashOcheck = 0;
  FILE *inputFILE;
  char holdstring[100];
  char breakcheck[] = "4096 x";

  for(i = 1; i < argc; i++){
    /* printf("%s", argv[i]); */

    if(strcmp(dashO, argv[i]) == 0){
      dashOcheck = 1;
    } else {
      printf("else case reached --> %d\n", i); 
      inputFILE = fopen(argv[i], "r");
      linecount = 0;
      charcheck = fgetc(inputFILE);
      while( charcheck != EOF ){
	/* printf("%d", charcheck ); */
	if( charcheck == '\n' ) linecount++;
	charcheck = fgetc(inputFILE);
      }
      fclose(inputFILE);
      inputFILE = fopen(argv[i], "r");
      /*printf("%d\n", linecount);*/
      for(j = 0; j < linecount; j++){
	fgets(holdstring, 100, inputFILE);
	if(strcmp(breakcheck, holdstring) == 0){
	  /* printf("4096 x hit\n"); */
	}
	printf("%s", holdstring);

	for(j = 0; j < 100; j++){ 
	  /*if( holdstring[j] != '\0' ) printf("%c", holdstring[j]);*/
	}
      }
    }
  }

  fclose(inputFILE);
  return 0;
}
