#include <iostream>
#include <string>
#include "GradeBook.h"
using namespace std;

int main()
{
  GradeBook GBtest( "History", "Dr. Prof. Patrick" );

  GBtest.displayMessage();
}
