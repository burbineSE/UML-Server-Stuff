// Fig. 3.12: GradeBook.cpp                                                    
// GradeBook member-function definitions. This file contains                   
// implementations of the member functions prototyped in GradeBook.h.         
// Modiyed by Chris Burbine                                                   

#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook                
using namespace std;

// constructor initializes courseName/instructorName                           
// with string supplied as argument                                           
GradeBook::GradeBook( string Cname, string Iname )
{
  setCourseName( Cname ); // call set function to initialize courseName        
  setInstructorName( Iname ); //call set function to init instructorName       
} // end GradeBook constructor                                        

// function to set the course name                                          
void GradeBook::setCourseName( string Cname )
{
  courseName = Cname; // store the course name in the object                   
} // end function setCourseName                                              

// function to set instructor name                                         
void GradeBook::setInstructorName( string Iname )
{
  instructorName = Iname;
}

// function to get the course name                                             
string GradeBook::getCourseName()
{
  return courseName; // return object's courseName                             
} // end function getCourseName                                                

// function to get instructor name                                             
string GradeBook::getInstructorName()
{
  return instructorName;
}

// display a welcome message to the GradeBook user                             
void GradeBook::displayMessage()
{
  // call getCourseName to get the courseName                                
  cout << "Welcome to the grade book for\n" << getCourseName() << endl
       << "This course is presented by\n" << getInstructorName()
       << "!" << endl;
} // end function displayMessage                                               
