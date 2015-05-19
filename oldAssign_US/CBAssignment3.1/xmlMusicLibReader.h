/* 
 * File:   xmlMusicLibReader.h
 * Author: Chris Burbine, christopher_burbine@student.uml.edu
 *
 * Created on September 30, 2012, 8:36 PM
 */

#ifndef XMLMUSICLIBREADER_H
#define	XMLMUSICLIBREADER_H

#include <vector>
#include <string>
#include <fstream>

#include "xmlElements.h" 

class xmlMusicLibReader {
public:
    /** 
     * default constructor, initializes temporary data members as a placeholder
     */
    xmlMusicLibReader();
    /** NetBeans-supplied constructor*/
    xmlMusicLibReader(const xmlMusicLibReader& orig);
    /** NetBeans-supplied destructor*/
    virtual ~xmlMusicLibReader();

    /** file opener function not used in Assignment 3*/
    ifstream FileOpener(string, ifstream &);
    /** Xml vector printing function, not used in Assignment 3*/
    void printXmlVect(); // print function for xml file
    /**
     * xmlElements vector return, not used in Assignment 3
     * @return vector of children of the current xmlElement
     */
    vector< xmlElements* >* getVector(); // a pointer to a vector of pointers 
};

#endif	/* XMLMUSICLIBREADER_H */

