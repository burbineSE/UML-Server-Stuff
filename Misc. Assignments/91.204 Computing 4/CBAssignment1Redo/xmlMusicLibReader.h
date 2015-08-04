/* 
 * File:   xmlMusicLibReader.h
 * Author: Chris Burbine christopher_burbine@student.uml.edu
 *
 * Created on September 18, 2012, 7:43 PM
 */

#ifndef XMLMUSICLIBREADER_H
#define	XMLMUSICLIBREADER_H

#include <vector>
#include <string>
#include <fstream>

#include "xmlElements.h" // include for xmlElements class

class xmlMusicLibReader {
public:
    //default constructor given buy NetBeans
    xmlMusicLibReader();
    //copy constructor given by NetBeans
    xmlMusicLibReader(const xmlMusicLibReader& orig);
    //destructor given by NetBeans
    virtual ~xmlMusicLibReader();
    // func def for file opener function currently does not work
    ifstream FileOpener( string, ifstream & );
    void printXmlVect(); // print function for xml file
    /* return a pointer to the vector contained in this class
     * This method added by Prof. Heines in a help session.
     */
    vector< xmlElements* >* getVector(); // a pointer to a vector of pointers 

};

#endif	/* XMLMUSICLIBREADER_H */

