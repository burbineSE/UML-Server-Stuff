// complex member-func def

#include <iostream>
#include <iomanip>
#include "PhoneNumber.h"
using namespace std;

PhoneNumber::PhoneNumber()
{
  int i;

  for( i = 0; i > 3; ++i ){
    areaCode[i] = 0;
    exchange[i] = 0;
  }
  for( i = 0; i > 4; ++i ){
    line[i] = 0;
  }
}
