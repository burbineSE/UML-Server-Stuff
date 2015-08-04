#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int fileT;
  int lineT;
  char bitsT[20];
  char nameT[20];
} TOPstr;

typedef struct {
  int fileB;
  char nameB[20];
  int lineB;
} BOTstr;

int main ( int argc, char *argv[]){

  int i, j, k, l, n, o, p, linecount, charcheck;
  int m = 0;
  int a = 0;
  char dashO[] = "-o";
  char NL[] = "\n";
  char tempstr[100];
  int dashOcheck = 0;
  FILE *inputFILE;
  char holdstring[100];
  int breakcheck = 0;
  char intswap;
  int TL = 0;
  int TLB = 0;
  TOPstr topstrAr[200];
  BOTstr botstrAr[100];
  int secCount = 0;
  int secCountB = 0;
  int converAr;
  int holdarray[100];
  char singlechar;
  int multer;
  int sum = 0;
  int holdsum = 0;
  int holdsumB = 0;
  int totalsum = 0;
  int filenum = 0;
  int SAC = 0;
  int breakstart = 0;

  for(i = 1; i < argc; i++){
    /*printf("%s", argv[i]); */

    if(strcmp(dashO, argv[i]) == 0){ /* checks for -o string */
      dashOcheck = 1;
    } else {
      ++filenum;
      /*printf("\n!!!else case reached --> %d!!!\n", filenum);*/
      inputFILE = fopen(argv[i], "r");
      linecount = 0; /* linecount keeps track of current file's number of lines */
      charcheck = fgetc(inputFILE); /* charcheck looks at file char by char looking for /n chars */

      while( charcheck != EOF ){ /* line number finder */
        /*printf("%d", charcheck );*/ 
        if( charcheck == '\n' ) linecount++;
	/*intswap = (char)charcheck;*/
	/*printf("%c", intswap);*/
        charcheck = fgetc(inputFILE); /*gets next char */
      }
      /*printf("linecount = %d\n", linecount);*/ 

      fclose(inputFILE);
      inputFILE = fopen(argv[i], "r");

      for(j = 0; j < linecount; j++){ /* break line function */
	fgets(holdstring, 100, inputFILE);
	/*printf("%s", holdstring);*/
	if(breakcheck == 0){
	  if(holdstring[2] == '4' && holdstring[3] == '0' && holdstring[4] == '9' && holdstring[5] == '6'){
	    /*printf("hit\n");*/
	    breakcheck = j; 
	    /*printf("4096 x found on line %d\n", breakcheck);*/
	  } /* end of 4096 x case */
	} /* end of breakcheck if */
      }/* end of break for loop */

      fclose(inputFILE);
      inputFILE = fopen(argv[i], "r");

      for( k = 0; k < linecount; k++ ){
	/*fgets(holdstring, 100, inputFILE);
	  printf("%s", holdstring);*/
	/*if(holdstring[1] == '4' && holdstring[2] == '0' && holdstring[3] == '9' && holdstring[4] == '6'){
	  printf("hit\n");
	    
	  }*/
	if( k < breakcheck ){
	  charcheck = fgetc(inputFILE);
	  for( l = 0; l < 100; l++){ /*while( charcheck != EOF ){*/
	    tempstr = holdstring[l];
	    /*printf("top\n");*/
	    if( holdstring[l] == '\n' ){ /*if(strcmp(NL, holdstring[l]) == 0){*/
	      printf("hit\n");
	      topstrAr[ TL ].fileT = filenum;
	      /*printf("fileT = %d\n", topstrAr[ TL ].fileT);*/
	      botstrAr[ TL ].fileB = filenum;
	      /*printf("fileB = %d\n", botstrAr[ TL ].fileB);*/
	      /*printf("TL = %d\n", TL);*/
	      /*topstrAr[ TL ].lineT = (holdsum + totalsum);*/
	      /*printf("lineT = %d\n\n", topstrAr[TL].lineT);*/
	      ++TL;
	      break;
	    }
	    if( holdstring[l] == ' ' ){
	      while( holdstring[l] == ' '){
		++l;
	      }
	      /*printf("before: %c\n", holdstring[l]);*/
	      --l; 
	      /*printf("after: %c\n\n", holdstring[l]);*/
	      ++secCount;
	      /*printf("secCount = %d\n", secCount);*/
	    }
	    if ( holdstring[l] != ' ' ){
	      /*printf("not sapce entered\n");*/
	      if(secCount == 1){
		/*printf("secCount == 1\n");*/
		while(holdstring[l] != ' '){
		  converAr = holdstring[l];
		  converAr = converAr - 48;
		  /*printf("TOP int = %d\n", converAr);*/
		  n = converAr;
		  if( sum == 0 && n == 0 ){
		    sum = sum + n;
		    /*printf("line num = 0 sum = %d\n", sum);*/
		  } else if( sum == 0 && n > 0 ){
		    sum = sum + n;
		    /*printf("line num != 0 sum = %d\n", sum);*/
		  } else if( sum > 0 && n >= 0 ){
		    sum = sum * 10;
		    sum = sum + n;
		    /*printf("line num > 9 sum = %d\n", sum);*/
		  }
		  ++a;
		  ++l;
		}
		topstrAr[ TL ].lineT = (sum + totalsum);
		holdsum = sum;
		/*printf("sum: %d\n", sum);
		  printf("TL: %d\n\n", TL);*/
		--l;
		m = 0;
		sum = 0;
	      }
	      if(secCount == 2){
 		while(holdstring[l] != ' '){
		  topstrAr[TL].bitsT[SAC] = holdstring[l];
		  /*printf("%c", topstrAr[TL].bitsT[SAC]);*/
		  ++SAC;
		  ++l;
		}
		/*printf("\nstring type: %s\n",  topstrAr[TL].bitsT);*/
		--l;
		SAC = 0;
	      }
	      if(secCount == 3){
		while(holdstring[l] != ' '){
		  topstrAr[TL].nameT[SAC] = holdstring[l];
		  /*printf("%c", topstrAr[TL].nameT[SAC]);*/
		  ++SAC;
		  ++l;
		}
		/*printf("\nstring type: %s\n",  topstrAr[TL].nameT);*/
		--l;
		SAC = 0;
	      }
	    }
	  }
	} else if(k > breakcheck && k < linecount){
	  /*printf("%s\n", holdstring);*/
	  for( l = 0; l < 100; l++){
	    if( holdstring[l] == '\n' ){
	      /*printf("hit\n");*/
	      /*printf("TLB = %d\n", TLB);*/
              ++TLB;
              break;
	    }
	    if( holdstring[l] == ' ' ){
              while( holdstring[l] == ' '){
                ++l;
              }
              /*printf("before: %c\n", holdstring[l]);*/
              --l;
              /*printf("after: %c\n\n", holdstring[l]);*/
              ++secCountB;
              /*printf("secCountB = %d\n", secCountB);*/
            }
	    if ( holdstring[l] != ' ' ){
	      /*printf("non space\n");*/
	      if(secCountB == 1){
                /*printf("secCount == 1\n");*/
                while(holdstring[l] != ' '){
		  botstrAr[TLB].nameB[SAC] = holdstring[l];
		  /*printf("%c", botstrAr[TLB].nameB[SAC]);*/
		  ++SAC;
		  ++l;
		}
		/*printf("string type: %s\n",  botstrAr[TLB].nameB);*/
		--l;
		SAC = 0;
	      }
	      if(secCountB == 2){
		while(holdstring[l] != ' '){
		  converAr = holdstring[l];
                  converAr = converAr - 48;
                  /*printf("BOT int = %d\n", converAr);*/
                  n = converAr;
                  if( sum == 0 && n == 0 ){
                    sum = sum + n;
		    o = 0;
                    /*printf("line num = 0 sum = %d\n", sum);*/
                  } else if( sum == 0 && n > 0 ){
                    sum = sum + n;
		    o = 1;
                    /*printf("line num != 0 sum = %d\n", sum);*/
                  } else if( sum > 0 && n >= 0 ){
                    sum = sum * 10;
                    sum = sum + n;
		    o = 2;
                    /*printf("line num > 9 sum = %d\n", sum);*/
                  }
                  ++a;
                  ++l;
		}
		if(o == 0) sum = 0;
		/*printf("sum: %d\n", sum);*/
		sum = sum + totalsum;
		botstrAr[TLB].lineB = sum;
		/*printf("shifted sum = %d\n", botstrAr[TLB].lineB);*/
                /*printf("sum: %d\n", sum);
                  printf("TL: %d\n\n", TL);*/
                --l;
                m = 0;
                sum = 0;
	      }
	    }
	  }	  
	}
	secCount = 0;
	secCountB = 0; 
      }
      totalsum = totalsum + holdsum + 1;
      /*printf("total sum: %d\n\n", totalsum);*/
      breakcheck = 0;
    }
    /*printf("TL = %d; TLB = %d\n", TL, TLB);*/
  }
  if(dashOcheck == 1){
    for(p = 0; p < TL; ++p){
      /*printf("sizeof P = %d\n", p);*/
      printf(" %d %s", topstrAr[ p ].lineT, topstrAr[p].bitsT);
      if(topstrAr[p].nameT != NULL){
	printf(" %s\n", topstrAr[p].nameT);
      } else printf("\n");
    }
    printf("4096 x\n");
    for(p = 0; p < TLB; ++p){
      printf(" %s     %d\n", botstrAr[p].nameB, botstrAr[p].lineB);
    }
  }
  return 0;
}
