// Rational NUmber test file

#include <iostream>
#include <iomanip>
#include "RationalNumber.h"
using namespace std;

int main()
{
  RationalNumber frac1( 2, 7 );
  cout << "First fraction: " << frac1 << endl;

  RationalNumber frac2( 4, 14 );
  cout << "Second fraction: " << frac2;

  RationalNumber frac3;

  cout << "\nAdd: ";
  frac3 = frac1 + frac2;
  cout << frac1 << " + " << frac2 << " = " << frac3;

  cout << "\nSubtract: ";
  frac3 = frac1 - frac2;
  cout << frac1 << " - " << frac2 << " = " << frac3;

  cout << "\nDivide: ";
  cout << frac1 << " / " << frac2 << " = " << ( frac1 / frac2 );

  cout <<"\nMultiply: ";
  cout << frac1 << " * " << frac2 << " = " << ( frac1 * frac2 ) << endl; 

  cout << frac1 << " is: " << endl;
  if( frac1 > frac2 )
    cout << " > " << frac2 << " according to the overload > operator\n";
  else
    cout << " <= " << frac2 << " according to the overload > operator\n";
  if( frac1 < frac2 )
    cout << " < " << frac2 << " according to the overload < operator\n";
  else 
    cout << " >= " << frac2 << " according to the overload < operator\n";
  if( frac1 >= frac2 )
    cout << " >= " << frac2 << " according to the overload >= operator\n";
  else
    cout << " < " << frac2 << " according to the overload >= operator\n";
  if( frac1 <= frac2 )
    cout << " <= " << frac2 << " according to the overload <= operator\n";
  else 
    cout << " > " << frac2 << " according to the overload <= operator\n";
  if( frac1 == frac2 )
    cout << " == " << frac2 << " according to the overload == operator\n";
  else
    cout << " != " << frac2 << " according to the overload == operator\n";
  if( frac1 != frac2 )
    cout << " != " << frac2 << " according to the overload != operator\n";
  else 
    cout << " == " << frac2 << " according to the overload != operator\n";

  return 0;
} 
