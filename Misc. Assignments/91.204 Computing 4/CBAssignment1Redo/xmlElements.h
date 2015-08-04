/* 
 * File:   xmlElements.h
 * Author: Chris Burbine christopher_burbine@student.uml.edu
 *
 * Created on September 18, 2012, 7:29 PM
 */

#ifndef XMLELEMENTS_H
#define	XMLELEMENTS_H

#include <string>

using namespace std;

class xmlElements {
public:
    xmlElements(); // empty constructor for out of file calls
    xmlElements(int, string); // constructor for xmlElements class
    
    void setEle(string); // sets element which is a string
    string getEle() const; // returns said string
    
    void setLine(int); // sets element which is a int
    int getLine() const; // returns said string
 
private:
    string element; // string for element name
    int lineNum; // int for line number
};

#endif	/* XMLELEMENTS_H */

