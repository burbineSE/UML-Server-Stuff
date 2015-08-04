//Rational Num class def

#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <string>
#include <iostream>
using namespace std;

class RationalNumber
{
  friend ostream &operator<<( ostream &, const RationalNumber & );

 public:
  RationalNumber();
  RationalNumber( int, int );

  RationalNumber operator+( const RationalNumber & ) const;
  RationalNumber operator-( const RationalNumber & ) const;
  RationalNumber operator*( const RationalNumber & ) const;
  RationalNumber operator/( const RationalNumber & ) const;

  bool operator<( const RationalNumber &) const;
  bool operator>( const RationalNumber &) const;
  bool operator<=( const RationalNumber &) const;
  bool operator>=( const RationalNumber &) const;
  bool operator==( const RationalNumber &) const;
  bool operator!=( const RationalNumber &) const;


  void setNumerator( int );
  int getNumerator() const;

  void setDenominator( int );
  int getDenominator() const;

  int reduction( int, int ) const;
  int findLCM( int, int ) const;

 private: 
  int numerator;
  int denominator;
};

#endif
