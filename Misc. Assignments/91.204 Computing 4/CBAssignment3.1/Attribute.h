/* 
 * File:   Attribute.h
 * Author: Chris Burbine, christopher_burbine@student.uml.edu
 *
 * Created on October 13, 2012, 5:10 PM
 * Updated on October 15, 2012, 2:05 PM
 */

#ifndef ATTRIBUTE_H
#define	ATTRIBUTE_H

#include <string>

//#include "xmlElements.h"

using namespace std;

/** The Attribute class used to store attributes for the xml doc.
 * Used in Assignment 3 and stored in a Attribute vector in each
 * xmlElements.
 */
class Attribute {
public:
    /** 
     * default constructor, initializes temporary data members as a placeholder
     */
    Attribute();
    /** NetBeans-supplied constructor*/
    Attribute(const Attribute& orig);
    /** NetBeans-supplied destructor*/
    virtual ~Attribute();
    
    /**
     * three-parameter constructor
     * @param int is the line number the Attr was found on
     * @param first string is the Attr name
     * @param second is the Attr value
     */
    Attribute( int, string, string );
    
    /**
     * Attr name setter
     * @param string is stored into AttrName
     */
    void setAttrName( string );
    /**
     * Attr name getter
     * @return returns name of current Attr
     */
    string getAttrName() const;
    
    /**
     * Attr value setter
     * @param string is stored into AttrVal
     */
    void setAttrVal( string );
    /**
     * Attr value getter
     * @return returns value of current Attr
     */
    string getAttrVal() const;
    
    /**
     * Attr line number setter
     * @param int is stored into lineNum
     */
    void setAttrLineNum( int );
    /**
     * Attr line number getter
     * @return returns current line of current Attr
     */
    int getAttrLineNum() const;
    
    //Attribute AttrExtractor( string, int );
    
private:
    /** name if the Attribute extracted from the line*/
    string AttrName;
    /** value/content of the Attribute*/
    string AttrVal;
    /** number of the line it was found on*/
    int lineNum;

};

#endif	/* ATTRIBUTE_H */
