/* 
 * File:   xmlMusicLibReader.h
 * Author: Chris Burbine christopher_burbine@student.uml.edu
 *
 * Created on September 17, 2012, 2:05 PM
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>

#include "xmlElements.h"

using namespace std;

//default constructor for xmlElements
xmlElements::xmlElements() {
    // do nothing
}

// constructor for xmlElements class sets element name and line number
xmlElements::xmlElements(int lineNumber, string eleName, string textCont) {
    setEle(eleName);
    setLine(lineNumber);
    setContent(textCont);
}

// sets element name

void xmlElements::setEle(string eleName) {
    element = eleName;
}

// returns element name

string xmlElements::getEle() const {
    return element;
}

// sets line number

void xmlElements::setLine(int lineNumber) {
    lineNum = lineNumber;
}

// returns line number

int xmlElements::getLine() const {
    return lineNum;
}

// sets content string
void xmlElements::setContent( string Cont ){
    content = Cont;
}

// return content string
string xmlElements::getContent() const {
    return content;
}
