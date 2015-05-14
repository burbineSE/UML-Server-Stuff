/* 
 * File:   main.cpp
 * Author: Chris Burbine christopher_burbine@student.uml.edu
 *
 * Created on September 18, 2012, 7:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "xmlMusicLibReader.h"

using namespace std;

/*
 */

void xmlFileSearch() {
    char pLine[ 256 ]; //array of chars where the lines of the xml file goes at first
    string sLine; // line then are stored into sLine so the can manipulated as strings 
    int iLineNum = 1; // Line counter
    int closeB = 0; // close bracket int holder 
    xmlMusicLibReader xmlMusicTemp;

    ifstream xmlSongLib("SongLib.xml"); // current working file opener
    
    // calls for the file opener member, currently not working 
    //string songLibFileName = string( "SongLib.xml");
    //ifstream xmlSongLib;
    //xmlMusicTemp.FileOpener( songLibFileName, xmlSongLib );

    vector< xmlElements* >* tempVect = xmlMusicTemp.getVector(); // set tempVect as a pointer to a vector of pointers, pointing at a pointer to xmlVect  

    if (xmlSongLib.is_open()) { // runs if file opens 
        while (xmlSongLib.getline(pLine, 256) != NULL) { //takes a line from the file until it reaches EOF
            sLine = pLine; // sets sLine to pLine
            int openB = sLine.find("<"); // sets openB to location of first <
            sLine.erase(0, openB + 1); // removes white space and first <

            closeB = sLine.find(">"); // sets closeB to first >
            sLine.erase(closeB); // removes > and everything else on line

            int spaceLocation = sLine.find(" "); //finds the location of a space if there is any
            if (spaceLocation > 0) { //function sets closeB to the space if there is any
                closeB = sLine.find(" ");
            }
            sLine = sLine.erase(closeB); //erases one final time to clear up the elements with a space in them

            if (sLine.find_first_of("?!/")) {
                // line instantiated a new xmlEle every time it was called
                xmlElements *xmlEle = new xmlElements( iLineNum, sLine );
                (*tempVect).push_back(xmlEle); // pushes new elements onto vector
            }
            ++iLineNum; // iterates for line count
        }
    } else { //else occurrence if file fails to open
        cout << "Cannot open file." << endl;
    }
    xmlMusicTemp.printXmlVect(); // calls print function
    xmlSongLib.close(); // closes file
}

//main file calls search function return 0 when done
int main(int argc, char** argv) {

    xmlFileSearch();

    return 0;
}
