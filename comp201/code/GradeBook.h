// GradeBook class definition. This file presents GradeBook's public 
// interface without revealing the implementations of GradeBook's member
// functions, which are defined in GradeBook.cpp.

#include <string> // class GradeBook uses C++ standard string class
using namespace std;

// GradeBook class definition
class GradeBook
{
 public:
  GradeBook( string ); // constructor that initializes courseName
  void setCourseName( string ); // function that sets the course name
  string getCourseName(); // function that gets the course name
  void displayMessage(); // function that displays a welcome message
 private:
  string courseName; // course name for this GradeBook
}; // end class GradeBook  
