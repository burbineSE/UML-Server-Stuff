/* 
 * File:   xmlElements.h
 * Author: Chris Burbine, christopher_burbine@student.uml.edu
 *
 * Created on September 18, 2012, 7:29 PM
 * Updated on October 15, 2012, 5:18 PM
 */

#ifndef XMLELEMENTS_H
#define	XMLELEMENTS_H

#include <string>
#include "Attribute.h"

using namespace std;

/**
 * xmlElements class holds most of the data for the code
 * used in both Assignments 1 & 2 for similar purposes 
 */
class xmlElements {
public:
    /** 
     * default constructor, initializes temporary data members as a placeholder
     */
    xmlElements(); 
    
    /**
     * five-parameter constructor 
     * @param int is the line that the element was found at
     * @param first string is the name of the element
     * @param second is the content, if there is any
     * @param the vector of xmlElements pointers holds the children of the xmlElement
     * @param the vector of Attribute pointers holds the attribute(s) of this xmlElement
     */
    xmlElements(int, string, string, vector< xmlElements* >, vector< Attribute* > ); 
    
    /**
     * xmlEle element name setter
     * @param name of the element found 
     */
    void setEle(string); 
    /**
     * xmlEle element name getter
     * @return name of the element found
     */
    string getEle() const; 
    
    /**
     * xmlEle line number setter
     * @param line number the element was found on
     */
    void setLine(int); 
    /**
     * xmlEle line number getter
     * @return line number the element was found on
     */
    int getLine() const; 
    
    /**
     * xmlEle content setter
     * @param content of the element found, if there is any
     */
    void setContent( string ); 
    /**
     * xmlEle content getter
     * @return content of the element found if there is any
     */
    string getContent() const; 
    
    /**
     * xmlElements vector return
     * @return vector of children of the current xmlElement
     */
    vector< xmlElements* >* getVectorEle();
    /**
     * xmlElements push function
     * @param pushes a pointer to an xmlEle onto the child vector
     */
    xmlElements pushEleVect( xmlElements* );
    
    /**
     * Attribute vector return
     * @return vector of Attributes of the current xmlElement
     */
    vector< Attribute* >* getVectorAttr();
    /**
     * Attribute push function
     * @param pushes a pointer to an Attr onto the Attr vector
     */
    Attribute pushAttrVect( Attribute* );
 
private:
    /** name of the extracted element*/
    string element; 
    /** line number of the extracted element*/
    int lineNum; 
    /** content of the extracted element, if there is any*/
    string content; 
    /** vector of children of the current element*/
    vector < xmlElements* > childVect;
    /** vector of Attributes of the current element*/
    vector < Attribute* > attrVect;
};

#endif	/* XMLELEMENTS_H */

