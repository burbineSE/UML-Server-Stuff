/* 
 * File:   Attribute.cpp
 * Author: Chris
 * 
 * Created on October 13, 2012, 5:10 PM
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iterator>

#include "Attribute.h"
#include "xmlElements.h"

using namespace std;

/** 
 * default constructor, initializes temporary data members as a placeholder
 */
Attribute::Attribute() {
}

/** NetBeans-supplied constructor*/
Attribute::Attribute(const Attribute& orig) {
}

/** NetBeans-supplied destructor*/
Attribute::~Attribute() {
}

/**
 * 3 parameter constructor
 * @param LineN line number of Attribute 
 * @param attN is set as name of the Attribute
 * @param attV is set as value of the Attribute
 */
Attribute::Attribute(int LineN, string attN, string attV) {
    setAttrName(attN);
    setAttrVal(attV);
    setAttrLineNum(LineN);
}

/**
 * Attr name setter
 * @param string is stored into AttrName
 */
void Attribute::setAttrName(string attN) {
    AttrName = attN;
}

/**
 * Attr name getter
 * @return returns name of current Attr
 */
string Attribute::getAttrName() const {
    return AttrName;
}

/**
 * Attr value setter
 * @param string is stored into AttrVal
 */
void Attribute::setAttrVal(string attV) {
    AttrVal = attV;
}

/**
 * Attr value getter
 * @return returns value of current Attr
 */
string Attribute::getAttrVal() const {
    return AttrVal;
}

/**
 * Attr line number setter
 * @param int is stored into lineNum
 */
void Attribute::setAttrLineNum(int LineN) {
    lineNum = LineN;
}

/**
 * Attr line number getter
 * @return returns current line of current Attr
 */
int Attribute::getAttrLineNum() const {
    return lineNum;
}

/*Attribute Attribute::AttrExtractor(string lineIn, int LineN) {

    //cout << "Attr Ex entered" << endl;
    int spaceOp;
    spaceOp = lineIn.find(" ");
    //cout << "Space found at " << spaceOp << endl;
    int EQSign;
    EQSign = lineIn.find_first_of("=");
    //cout << "Equals sign found at " << EQSign << endl;
    
    string attrName = lineIn.substr( (spaceOp + 1), (EQSign - spaceOp - 1) );
    //cout << "Attr Name " << attrName << endl;
    
    int openQ = ( EQSign + 2 );
    //cout << "Value start " << openQ << endl;
    int closeB = lineIn.find_first_of(">");
    int closeQ = (closeB - 1);
    //cout << "Value end " << closeQ << endl;
    
    string attrValue = lineIn.substr( openQ, closeQ - openQ );
    //cout << "Attr Value " << attrValue << endl;
    
    Attribute *attrTemp = new Attribute( LineN, attrName, attrValue );
    cout << attrTemp->getAttrName() << " " << attrTemp->getAttrVal() << endl;
    
    return *attrTemp;
}*/
