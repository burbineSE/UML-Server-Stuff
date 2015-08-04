/* 
 * File:   xmlMusicLibReader.h
 * Author: Chris Burbine, christopher_burbine@student.uml.edu
 *
 * Created on September 17, 2012, 2:05 PM
 * Updated on October 15, 2012, 5:18 PM
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>

#include "xmlElements.h"

using namespace std;

/** 
 * default constructor, initializes temporary data members as a placeholder
 */
xmlElements::xmlElements() {
}

/**
 * five-parameter constructor
 * @param lineNumber is the line that the element was found at
 * @param eleName is set as the name of the element
 * @param textCont is set as the content of the element, if there is any
 * @param EleVector the vector of xmlElements pointers holds the children of the xmlElement
 * @param AttrVector the vector of Attribute pointers holds the attribute(s) of this xmlElement
 */
xmlElements::xmlElements(int lineNumber, string eleName, string textCont,
        vector< xmlElements* > EleVector, vector< Attribute* > AttrVector) {
    setEle(eleName);
    setLine(lineNumber);
    setContent(textCont);
    EleVector.clear();
    AttrVector.clear();
}

/**
 * xmlEle element name setter
 * @param name of the element found 
 */
void xmlElements::setEle(string eleName) {
    element = eleName;
}

/**
 * xmlEle element name getter
 * @return name of the element found
 */
string xmlElements::getEle() const {
    return element;
}

/**
 * xmlEle line number setter
 * @param line number the element was found on
 */
void xmlElements::setLine(int lineNumber) {
    lineNum = lineNumber;
}

/**
 * xmlEle line number getter
 * @return line number the element was found on
 */
int xmlElements::getLine() const {
    return lineNum;
}

/**
 * xmlEle content setter
 * @param content of the element found, if there is any
 */
void xmlElements::setContent(string Cont) {
    content = Cont;
}

/**
 * xmlEle content getter
 * @return content of the element found if there is any
 */
string xmlElements::getContent() const {
    return content;
}

/**
 * xmlElements vector return
 * @return vector of children of the current xmlElement
 */
vector< xmlElements* >* xmlElements::getVectorEle() {
    return &childVect;
}

/**
 * xmlElements push function
 * @param pushes a pointer to an xmlEle onto the child vector
 */
xmlElements xmlElements::pushEleVect(xmlElements* ele) {
    childVect.push_back(ele);
}

/**
 * Attribute vector return
 * @return vector of Attributes of the current xmlElement
 */
vector< Attribute* >* xmlElements::getVectorAttr() {
    return &attrVect;
}

/**
 * Attribute push function
 * @param pushes a pointer to an Attr onto the Attr vector
 */
Attribute xmlElements::pushAttrVect(Attribute* attr) {
    attrVect.push_back(attr);
}
