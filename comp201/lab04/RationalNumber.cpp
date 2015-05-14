// Rational Number member-function def

#include <iostream>
#include <cctype>
#include "RationalNumber.h"
using namespace std;

RationalNumber::RationalNumber()
{
  numerator = 1;
  denominator = 1;
}

RationalNumber::RationalNumber( int num, int den )
{
  if( den > 0 ){
    int gcd = reduction( num, den );
    num /= gcd;
    den /= gcd;
    setNumerator( num );
    setDenominator( den );
  }
  else 
    cout << "Denominator must be greater than zero." << endl;
}

RationalNumber RationalNumber::operator+( const RationalNumber &frac2 ) const
{
  RationalNumber temp = *this; 

  if( temp.denominator != frac2.denominator ){
    int lcm = findLCM( temp.denominator, frac2.denominator); 

    temp.numerator *= lcm / temp.denominator;
    temp.denominator = lcm;
    temp.numerator += frac2.numerator * lcm / frac2.denominator;
  }
  else
    temp.numerator += frac2.numerator;

  int gcd = reduction( temp.numerator, temp.denominator );
  temp.numerator /= gcd;
  temp.denominator /= gcd;

  return temp;
}

RationalNumber RationalNumber::operator-( const RationalNumber &frac2 ) const
{
  RationalNumber temp = *this;

  if(temp.denominator != frac2.denominator ){
    int lcm = findLCM( temp.denominator, frac2.denominator );

    temp.numerator *= lcm / temp.denominator;
    temp.denominator = lcm;
    if( temp.numerator >= frac2.numerator * lcm )
      temp.numerator -= frac2.numerator * lcm / temp.denominator;
    else
      temp.numerator = (frac2.numerator * lcm 
			/ temp.denominator) - temp.numerator;
  }
  else{
    if( temp.numerator >= frac2.numerator )
      temp.numerator -= frac2.numerator;
    else
      temp.numerator = frac2.numerator - temp.numerator;
  }

    int gcd = reduction( temp.numerator, temp.denominator );
    temp.numerator /= gcd;
    temp.denominator /= gcd;

    return temp;
}  

RationalNumber RationalNumber::operator*( const RationalNumber &frac2 ) const
{

  RationalNumber temp = *this;

  temp.numerator *= frac2.numerator;
  temp.denominator *= frac2.denominator;

  int gcd = reduction( temp.numerator, temp.denominator );
  temp.numerator /= gcd;
  temp.denominator /= gcd;

  return temp;
}

RationalNumber RationalNumber::operator/( const RationalNumber &frac2 ) const
{
  RationalNumber temp = *this;
  RationalNumber temp2 = *this;
  int fracNumN = 0;
  int fracNumD = 0;

  fracNumN = frac2.numerator;
  fracNumD = frac2.denominator;
  temp.numerator = fracNumD;
  temp.denominator = fracNumN;

  temp2.numerator *= temp.numerator;
  temp2.denominator *= temp.denominator;

  int gcd = reduction( temp2.numerator, temp2.denominator );
  temp2.numerator /= gcd;
  temp2.denominator /= gcd;

  return temp2;
}

void RationalNumber::setNumerator( int num )
{
  numerator = num;
}

int RationalNumber::getNumerator() const
{
  return numerator;
}

void RationalNumber::setDenominator( int den )
{
  denominator = den;
}

int RationalNumber::getDenominator() const
{
  return denominator;
}

int RationalNumber::reduction( int num, int den ) const
{
  int temp;
  while( den != 0 ){
    temp = num % den;
    num = den;
    den = temp;
  }

  return num;
}

int RationalNumber::findLCM( int den1, int den2 ) const
{
  return ((den1 * den2) / reduction(den1, den2));
}

bool RationalNumber::operator<( const RationalNumber &right ) const
{
  RationalNumber temp = *this;
  int lcm = findLCM( temp.denominator, right.denominator );

  temp.numerator *= lcm / temp.denominator;
  temp.denominator = lcm;
 
  return (temp.numerator < (right.numerator * lcm / right.denominator));
}
bool RationalNumber::operator>( const RationalNumber &right ) const
{
  return(!(*this < right) && !(*this == right));
}

bool RationalNumber::operator<=( const RationalNumber &right ) const
{
  return((*this < right) || (*this == right));
}

bool RationalNumber::operator>=( const RationalNumber &right ) const
{
  return((*this > right) || (*this == right));
}

bool RationalNumber::operator==( const RationalNumber &right ) const
{
  return( numerator == right.numerator && denominator == right.denominator );
}

bool RationalNumber::operator!=( const RationalNumber &right ) const
{
  return !(*this == right);
}

ostream &operator<<( ostream &outObj, const RationalNumber &right )
{
  outObj << right.numerator << "/" << right.denominator;
  return outObj;
}

