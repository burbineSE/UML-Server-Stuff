// complex class def

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <iomanip>
using namespace std;

class Complex
{
 public:
  Complex();

  friend ostream &operator<<( ostream &out, const Complex &c )
  {
    if( cin.fail() ){
      cout << "Input invaild." << endl;
      return out;
    }
    else{
      out << "Format correct: " << c.real << " +/- "; 
      out << c.imag << "i" << endl;
      return out;
    }
  }
  
  friend istream &operator>>( istream &in, Complex &c )
  {
    int number;
    char x;

    if( in.peek() == ' ' ){ // case a +/- bi
      c.real = number;
      in >> x;
      if( in.peek() == ( '+' || '-' ) ){
	in >> x;
	if( in.peek() == ' ' ){
	  in >> x;
	  in >> x;
	  if ( in.peek() == 'i' ){
	    c.imag = number;
	    in >> x;
	    if( in.peek() == '\n' ){
	      return in;
	    }
	  }
	}
      }
    }
    else if( in.peek() == 'i' ){ // case bi
      c.imag = number;
      in >> x;
      if( in.peek() == '\n' ){
	c.real = 0;
	return in;
      }
    }
    else if( in.peek() == '\n' ){ // case a
      c.real = number;
      c.imag = 0;
      return in;
    }
    else{
      in.clear( ios::failbit );
      return in;
    }
    return in;
  }
  
 private: 
  int real;
  int imag;
};

#endif
