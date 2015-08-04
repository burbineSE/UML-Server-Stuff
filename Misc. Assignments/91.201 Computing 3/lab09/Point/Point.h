// point class def

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <iomanip>
using namespace std;

class Point
{
 public:
  Point();

  friend ostream &operator<<( ostream &out, const Point &c )
  {
    if( cin.fail() ){
      cout << "Input invaild." << endl;
      return out;
    }
    else{
      out << "Format correct: (" << c.x_coord << ", " << c.y_coord; 
      out << ")" << endl;
      return out;
    }
  }

  friend istream &operator>>( istream &in, Point &c )
  {
    int number;
    char x;

    in >> x;
    if( in.peek() == ',' ){
      c.x_coord = number;
      in >> x;
      if( in.peek() == ' ' ){
	in >> x;
	in >> x;
	if( in.peek() == ')' ){
	  c.y_coord = number;
	  in >> x;
	  if( in.peek() == '\n' ){
	    return in;
	  }
	}
      }
    }
    else{
      in.clear( ios::failbit );
      return in;
    }
    return in;
  }

 private:
  int x_coord;
  int y_coord;
};

#endif
