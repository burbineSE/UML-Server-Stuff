/* 
 * File:   xmlMusicLibReader.cpp
 * Author: Chris Burbine christopher_burbine@student.uml.edu
 * 
 * Created on September 18, 2012, 7:43 PM
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>

#include "xmlMusicLibReader.h"
#include "xmlElements.h"

vector< xmlElements* > xmlVect; //storage vector for the element name and 
                                //line numbers

using namespace std;

//default constructor given buy NetBeans, this member along with the copy 
//constructor and the destructor are empty 
xmlMusicLibReader::xmlMusicLibReader() {
}

//copy constructor given by NetBeans
xmlMusicLibReader::xmlMusicLibReader(const xmlMusicLibReader& orig) {
}

//destructor given by NetBeans
xmlMusicLibReader::~xmlMusicLibReader() {
}

// file opener function, attempted to get it working 
// currently does not open the file 
/*ifstream xmlMusicLibReader::FileOpener(string fileName, ifstream &IFStream) {
    // string constructor
    char* pcharFileName = new char[ fileName.size() + 1 ];
    strcpy( pcharFileName, fileName.c_str() );
    //ifstream ifmyStream(pcharFileName);

    //return ifmyStream;
    IFStream.open( pcharFileName );
}*/

// vector printing function
void xmlMusicLibReader::printXmlVect() {
    // creates a vector iterator iIter to go through xmlVect 
    for (vector< xmlElements* >::iterator iIter = xmlVect.begin(); iIter != xmlVect.end(); ++iIter) {
     //prints out the data in xmlVect line by line
        cout << "Element [" << (*iIter)->getEle() << "] found on line #" << (*iIter)->getLine() << "." << endl;
    }
}

/* return a pointer to the vector contained in this class
 * This method added by Prof. Heines in a help session.
 */
vector< xmlElements* >* xmlMusicLibReader::getVector() {
    return &xmlVect;
}
