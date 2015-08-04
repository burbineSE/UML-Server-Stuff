// complex test file

#include <iostream>
#include <iomanip>
#include "Complex.h"
using namespace std;

int main()
{
  Complex complex;

  cout << "Enter complex number in the for of a +/- bi: " << endl;

  cin >> complex;
  cout << "Entered number was: " << endl;

  cout << complex << endl;

  return 0;
} 
