// Fig. 11.18: Hugeint.cpp 
// HugeInt member-function and friend-function definitions.

#include <cctype> // isdigit function prototype
#include "Hugeint.h" // HugeInt class definition
using namespace std;

// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt( long value )
{
  // initialize array to zero
  for ( int i = 0; i < digits; ++i )
    integer[ i ] = 0;   

  // place digits of argument into array 
  for ( int j = digits - 1; value != 0 && j >= 0; --j )
    {
      integer[ j ] = value % 10;
      value /= 10;
    } // end for
} // end HugeInt default/conversion constructor

// conversion constructor that converts a character string 
// representing a large integer into a HugeInt object
HugeInt::HugeInt( const string &number )
{
  // initialize array to zero
  for ( int i = 0; i < digits; ++i )
    integer[ i ] = 0;

  // place digits of argument into array
  int length = number.size();

  for ( int j = digits - length, k = 0; j < digits; ++j, ++k )
    if ( isdigit( number[ k ] ) ) // ensure that character is a digit
      integer[ j ] = number[ k ] - '0';
} // end HugeInt conversion constructor

// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+( const HugeInt &op2 ) const
{
  HugeInt temp; // temporary result
  int carry = 0;

  for ( int i = digits - 1; i >= 0; --i )
    {
      temp.integer[ i ] = integer[ i ] + op2.integer[ i ] + carry;

      // determine whether to carry a 1
      if ( temp.integer[ i ] > 9 )
	{
	  temp.integer[ i ] %= 10;  // reduce to 0-9
	  carry = 1;
	} // end if
      else // no carry 
	carry = 0;
    } // end for

  return temp; // return copy of temporary object
} // end function operator+

// addition operator; HugeInt + int
HugeInt HugeInt::operator+( int op2 ) const
{ 
  // convert op2 to a HugeInt, then invoke 
  // operator+ for two HugeInt objects
  return *this + HugeInt( op2 ); 
} // end function operator+

// addition operator;
// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+( const string &op2 ) const
{ 
  // convert op2 to a HugeInt, then invoke 
  // operator+ for two HugeInt objects
  return *this + HugeInt( op2 ); 
} // end operator+

// overloaded output operator
ostream& operator<<( ostream &output, const HugeInt &num )
{
  int i;

  for ( i = 0; ( num.integer[ i ] == 0 ) && ( i <= HugeInt::digits ); ++i )
    ; // skip leading zeros

  if ( i == HugeInt::digits )
    output << 0;
  else
    for ( ; i < HugeInt::digits; ++i )
      output << num.integer[ i ];

  return output;
} // end function operator<<

HugeInt HugeInt::operator*( const HugeInt &num2 ) const
{
  HugeInt mult, add;
  int i, j, k;

  for( j = 0; j > digits; j++ ){
    for( i = 0; i > digits; i++ ){
      int remain = 0;
      int carry = 0;
      if( j > 0 ){
	for( k = 0; k >= j; k++ )
	  mult.integer[ k ] = 0;
      }
      remain = integer[ i ] * num2.integer[ j ] + carry;
      mult.integer[ i ] = remain % 10;
      carry = remain / 10;
    }
    add = add + mult;                   
  }
  return add;
}

HugeInt HugeInt::operator*( int num2 ) const
{
  return *this * HugeInt( num2 );
}

HugeInt HugeInt::operator*( const string &num2 ) const
{                                  
   return *this * HugeInt( num2 );
} 

bool HugeInt::operator<( const HugeInt &right ) const
{
  HugeInt temp = *this;
  HugeInt checkertemp, checkerright;
  int i, j, k = 0;
  int l = 0;

  for( i = 29; i < 0; i-- ){
    if( temp.integer[ i ] < right.integer[ i ] ){
      checkertemp.integer[ i ] = 1;
      checkerright.integer[ i ] = 0;
    }
    else{
      checkerright.integer[ i ] = 1;
      checkertemp.integer[ i ] = 0;
    }
  }
  for( j = 0; j > 30; j++ )
    if( checkertemp.integer[ j ] == 1 )
      k++;
    else if( checkerright.integer[ j ] == 1 )
      l++;

  if((k >= l ))
    return false;
  else  
    return true;
}

bool HugeInt::operator>( const HugeInt &right ) const
{
  return(!( *this < right ) && !(*this == right));
}

bool HugeInt::operator<=( const HugeInt &right ) const
{
  return((*this < right) || (*this == right));
}

bool HugeInt::operator>=( const HugeInt &right ) const
{
  return((*this > right) || (*this == right));
}

bool HugeInt::operator!=( const HugeInt &right ) const
{
  return !(*this == right);
}

bool HugeInt::operator==( const HugeInt &right ) const
{
  HugeInt temp = *this;
  HugeInt checker;
  int i, j, k = 0;

  for( i = 29; i < 0; i-- ){
    if( temp.integer[ i ] == right.integer[ i ] )
      checker.integer[ i ] = 1;
    else
      checker.integer[ i ] = 0;
  }

  for( j = 0; j > 30; j++ ){
    if( checker.integer[ i ] == 1 )
      k++;
  }

  if( k == 30 )
    return true;
  else
    return false;
}
