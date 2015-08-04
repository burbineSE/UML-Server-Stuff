#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string ints[ 10 ] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
string charsCap[ 26 ] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
			  'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 
			  'U', 'V', 'W', 'X', 'Y', 'Z' };
string charsNorm[ 26 ] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
			   'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
			   'u', 'v', 'w', 'x', 'y', 'z' };
string operators[ 4 ] = { '*', '+', '-', '/' };
string delimiters[ 5 ] = { '.', '(', ')', ',' , ':' };
string blank[ 1 ] = { ' ' };
string endofline[ 1 ] = { '#' };
 
int main( int argc, char *argv[] )
{
  char array[ 80 ];
