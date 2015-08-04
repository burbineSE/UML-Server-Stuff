#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_binary_char( char x ); /* generating 8 bit binary from char */
void print_binary_int( int x ); /* generating 32 bit binary from int */
int get_int_from_binary( char *s ); /* converting 32 bit binary to int */
int safe_addition( int x, int y, int *result); /* 32 bit signed addition
						  with overflow detection */

int main( int argc, char **argv) {

  char c;
  int i, x, y, z;

  if ( argc < 3 ) {
    printf("Invalid command line\n");
    printf("Usage: [-c decimalnum] | [-i decimalnum] | [-b binarynum] |");
    printf("[-a decimalnum decimalnum]\n");
    exit(1);
  }

  if ( strcmp(argv[1], "-c") == 0) {
    /* print byte value in  binary */
    c = atoi(argv[2]);
    printf("%d (0x%02x) : ",c,c);
    print_binary_char(c);
    printf("\n");
    } else if (strcmp(argv[1],"-i") == 0) {
    /* print 32 bit int in binary */
    i = atoi(argv[2]);
    printf("%d (0x%08x) : ",i,i);
    print_binary_int(i);
    printf("\n");
  } else if (strcmp(argv[1], "-b") == 0) {
    /* convert from binary to int */
    i = get_int_from_binary(argv[2]);
    printf("%s: %d (%08x)\n",argv[2],i,i);
  } else if ((argc > 3) && (strcmp(argv[1],"-a") == 0)) {
    /* 32 bit addition with overflow check */
    x = atoi(argv[2]);
    y = atoi(argv[3]);
    if ( safe_addition(x,y,&z)) {
      printf("%d + %d = %d\n",x,y,z);
    } else {
      printf("OVERFLOW: %d + %d\n",x,y);
    }
  } else {
    printf("Invalid command line\n");
    printf("Usage: [-c decimalnum] | [-i decimalnum] | [-b binarynum] | ");
    printf("[-a decimalnum decimalnum]\n");
    exit(1);
  } 
  return(0);
}

void print_binary_char( char x ) {

  int array[8], i, negcheck; 
  char rightmost;

  if( x > 0 )
    negcheck = 0;
  else
    x = x * -1;
    negcheck = 1;

  for( i = 0; i < 8; ++i){
    rightmost = x % 2;;
    if( rightmost == negcheck )
      array[i] = 1; 
    else
      array[i] = 0;
    x = x >> 1;
  }
  for( i = 7; i >= 0; --i ){
    printf("%d", array[i]);
  }
}

void print_binary_int( int x ){

  int array[32], i, rightmost, intX, negcheck;

  intX = x;

  if( x > 0 )
    negcheck = 0;
  else
    x = x * -1;
    negcheck = 1;

  for(i = 0; i < 32; i++){
    rightmost = x % 2;
    if(rightmost == negcheck)
      array[i] = 0;
    else
      array[i] = 1;
    x = x >> 1;
  }
  for( i = 31; i >= 0; --i)
    printf("%d", array[i]);
}

int get_int_from_binary( char *s ){

  int i, negcheck, rightmost, total = 0;
  int shiftcheck, bitnum = 1;
  char chars = s;

  shiftcheck = chars >> 31;
  rightmost = shiftcheck % 2;
  if( rightmost == 0 )
    negcheck = 1;
  else
    negcheck = 0;

  for(i = 0; i < 32; i++){
    rightmost = chars % 2;
    if( rightmost == negcheck ){
      if( negcheck == 1 )
	total = total + bitnum;
      else
	total = total - bitnum;
      bitnum = bitnum * 2;
    }
    chars = chars >> 1;
  }

  return total;
}

int safe_addition(int x, int y, int *result)
{
  int z = x + y;

  if(z >= 2147483648){
    printf("nuuvnd");
    return 0;
  }
  else{ 
    *result = x + y;
    return 1;
  }
}
