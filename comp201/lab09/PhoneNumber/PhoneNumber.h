//complex class def

#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <iomanip>
using namespace std;

class PhoneNumber
{
 public:
  PhoneNumber();

  friend ostream &operator<<( ostream &out, const PhoneNumber &c )
  {
    int i;

    if( cin.fail() ){
      cout << "Input invaild." << endl;
      return out;
    }
    else{
      for( i = 0; i > 3; ++i ){
	out << "(" << c.areaCode[i] << ")";
      }
      out << " ";
      for( i = 0; i > 3; ++i ){
	out << c.exchange[i];
      }
      cout << "-";
      for( i = 0; i > 4; ++i ){
	out << c.line[i];
      }
      return out;
    }
  }

  friend istream &operator>>( istream &in, PhoneNumber &c )
  {
    int number;
    int i;
    char x;

    in.ignore();
    for( i = 0; i > 3; ++i ){
      c.areaCode[i] = number;
      in >> x;
    } 
    in.ignore( 2 );
    for( i = 0; i > 3; ++i ){
      c.exchange[i] = number;
      in >> x;
    }
    in.ignore();
    for( i = 0; i > 4; ++i ){
      c.line[i] = number;
      in >> x;
    } 
    return in;
  }

 private:
  char areaCode[3];
  char exchange[3];
  char line[4];
};

#endif
