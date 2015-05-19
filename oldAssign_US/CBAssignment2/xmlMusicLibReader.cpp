/* 
 * File:   xmlMusicLibReader.cpp
 * Author: Chris Burbine christopher_burbine@student.uml.edu
 * 
 * Created on September 30, 2012, 8:36 PM
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iterator>

#include "xmlMusicLibReader.h"
#include "xmlElements.h"

//vector< xmlElements* > xmlVect; //storage vector for the element name and line numbers, Not used in this build
vector< xmlElements* > xmlEleStack; // storage "stack" for the element content
//xmlElements root; // global root Element, had some issues implementing it, not used in this build
xmlElements xmlTemp; // global temp to hold data

// various parser states

enum ParserState {
    UNKNOWN, STARTING_DOC, DIRECTIVE,
    ELEMENT_OPENING_TAG, ELEMENT_CONTENT, ELEMENT_NAME_AND_CONTENT,
    ELEMENT_CLOSING_TAG, SELF_CLOSING_TAG, STARTING_COMMENT,
    IN_COMMENT, ENDING_COMMENT, ONE_LINE_COMMENT, ERROR
};

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
// Not used in this build
/*void xmlMusicLibReader::printXmlVect() {
    // creates a vector iterator iIter to go through xmlVect 
    for (vector< xmlElements* >::iterator iIter = xmlEleStack.begin(); iIter != xmlEleStack.end(); ++iIter) {
        //prints out the data in xmlVect line by line
        cout << "Element [" << (*iIter)->getEle() << "] found on line #" << (*iIter)->getLine() << "." << endl;
    }
}*/

/* return a pointer to the vector contained in this class
 * This method added by Prof. Heines in a help session.
 */
// not used in this build
/*vector< xmlElements* >* xmlMusicLibReader::getVector() {
    return &xmlEleStack;
}*/

// Parser State debugging function
// Used to show what state the parser is in
// Function provided by Prof. Heines

void ShowParserState(ParserState pstate) {
    cout << "ParserState = ";
    switch (pstate) {
        case STARTING_DOC: cout << "STARTING_DOCUMENT"; // shows when document is started
            break;
        case DIRECTIVE: cout << "DIRECTIVE"; // shows when directive is found
            break;
        case ELEMENT_OPENING_TAG: cout << "ELEMENT_OPENING_TAG"; // shows when the parser hits an opening tag
            break;
        case ELEMENT_CONTENT: cout << "ELEMENT_CONTENT"; // shows when the parser is in the content of an element
            break;
        case ELEMENT_NAME_AND_CONTENT: cout << "ELEMENT_NAME_AND_CONTENT"; // shows when the parser finds the opening and closing tags on the same line
            break;
        case ELEMENT_CLOSING_TAG: cout << "ELEMENT_CLOSING_TAG"; // shows when the parser finds a closing tag
            break;
        case SELF_CLOSING_TAG: cout << "SELF_CLOSING_TAG"; // shows when the parser finds a self closing tag
            break;
        case STARTING_COMMENT: cout << "STARTING_COMMENT"; // shows when the parser finds the start of a comment
            break;
        case IN_COMMENT: cout << "IN_COMMENT"; // shows when the parser is inside a comment
            break;
        case ENDING_COMMENT: cout << "ENDING_COMMENT"; // shows when the parser finds th end of a comment
            break;
        case ONE_LINE_COMMENT: cout << "ONE_LINE_COMMENT"; // shows when the parser finds a one line comment
            break;
        case ERROR: cout << "ERROR"; // // shows when the parser finds and error
            break;
        default: cout << "UNKNOWN"; // shows in unknown state
            break;
    }
    cout << endl;
}

//function show the contents of the vector (stack) that holds the element names
//general function outline taken from Deitel text p868-869

void showVectorStack(vector< xmlElements* > vect) {
    //sets stopping point for for loop 
    vector< xmlElements* >::size_type sz = vect.size();

    cout << "*** The Vector (stack) now contains: ";
    if (vect.empty()) { // if the vector is empty
        cout << "{EMPTY}";
    } else {
        // for lop iterates through stack and prints the element name
        for (int iter = 0; iter < sz; iter++) {
            xmlElements *xmlPlaceHolder = vect[ iter ];
            cout << xmlPlaceHolder->getEle() << " ";
        }
    }
    cout << endl;
}

// This Function parses a line from a XML file and returns data about that line

ParserState GetXML(string strLine, string& strEleName, string& strCont,
        int nStart, int& nEnd, ParserState CurrentState) {

    // firstOpenB and firstCloseB store the spot at which the opening and
    // closing brackets are on the line
    int firstOpenB = strLine.find_first_of("<");
    int firstCloseB = strLine.find_first_of(">");

    if (firstCloseB < 0) { // begins by checking if a closing tag was found
        if (firstOpenB < 0) { //if not we are in a comment 
            xmlTemp.setContent(strLine); // sets global temp to content of the comment
            CurrentState = IN_COMMENT;
            return CurrentState;
        }
        if (strLine[firstOpenB + 1] == '!') { // if the comment is just staring
            CurrentState = STARTING_COMMENT;
            return CurrentState;
        } else {
            xmlTemp.setContent(strLine); // if the state is unknown
            CurrentState = UNKNOWN;
            return CurrentState;
        }
    } else if (firstOpenB < 0 && strLine[firstCloseB - 1] == '-') { // if the comment is ending
        CurrentState = ENDING_COMMENT;
        return CurrentState;
    } else if (strLine[ firstOpenB + 1] == '?') { // if we find the directive
        strCont = strLine;
        strCont.erase(0, firstOpenB + 2);
        strCont.erase(firstCloseB - 2);
        xmlTemp.setContent(strCont); // sets global temp to content of the directive
        CurrentState = DIRECTIVE;
        return CurrentState;
    } else if (strLine[ firstOpenB + 1] == '!') { // if we find a one line comment
        strCont = strLine;
        strCont.erase(0, firstOpenB + 4);
        strCont.erase(firstCloseB - 6);
        xmlTemp.setContent(strCont); // sets global temp to content of the comment
        CurrentState = ONE_LINE_COMMENT;
        return CurrentState;
    } else if (strLine[ firstOpenB + 1] == '/') { // if we find a closing tag
        CurrentState = ELEMENT_CLOSING_TAG;
        //ShowParserState(CurrentState);
        return CurrentState;
    } else {
        //takes the element name from the line 
        strEleName = strLine.substr(firstOpenB + 1, (firstCloseB - firstOpenB - 1));
        xmlTemp.setEle(strEleName);

        // finds the last opening bracket and closing bracket even of they are the same as the first two 
        int lastOpenB = strLine.find_last_of("<");
        int lastCloseB = strLine.find_last_of(">");
        if (firstOpenB == lastOpenB && firstCloseB == lastCloseB) { // checks to see if the position of the brackets match
            // at this point we have narrowed down the possible states 
            // either: an opening tag, a one line element and content tag, 
            // or a self closing tag

            if (strLine[ lastCloseB - 2] == '/') { // brackets match; checks if the line is self closing
                strCont = "{EMPTY}";
                xmlTemp.setContent(strCont);
                CurrentState = SELF_CLOSING_TAG;
                //ShowParserState(CurrentState);
                return CurrentState;
            } else { // else it's a opening tag
                int spaceLocation = strLine.find(" "); //finds the location of a space if there is any
                if (spaceLocation > 0) { //function tests for spaces for the element opening tags with content within them 
                    //cout << "Space found: " << spaceLocation << endl;
                    firstCloseB = strLine.find(" ");
                    strEleName = strLine.substr(firstOpenB + 1, (firstCloseB - firstOpenB - 1));
                    //cout << "New Element name: " << strEleName << endl;
                    xmlTemp.setEle(strEleName);
                }
                xmlTemp.setContent("{EMPTY}");
                //cout << xmlTemp.getContent() << endl;
                CurrentState = ELEMENT_OPENING_TAG;
                //ShowParserState(CurrentState);
                return CurrentState;
            }
        } else { // if the brackets are not the same  its the opening and closing tags on the same line
            strCont = strLine.substr(firstCloseB + 1, (lastOpenB - firstCloseB - 1));
            //cout << "strCont: " << strCont << endl;
            xmlTemp.setContent(strCont);
            //cout << "Content: " << xmlTemp.getContent() << endl;
            CurrentState = ELEMENT_NAME_AND_CONTENT;
            //ShowParserState(CurrentState);
            return CurrentState;
        }
    }
}
// Trims leading and tailing white space and tab from string passed
// Function written by Prof. Heines, taken from class notes Sept. 18, 2012

string trim(string& str) {
    //cout << "Trimming |" << str << "|" << endl;
    while (str[0] == ' ' || str[0] == '\t') {
        str.erase(str.begin());
        //cout << "Front trimmed |" << str << "|" << endl;
    }
    while (str [ str.length() - 1] == ' ' || str [ str.length() - 1] == '\t') {
        str.erase(str.end() - 1);
        //cout << "Back Trimmed |" << str << "|" << endl;
    }
    //cout << "Trimmed |" << str << "|" << endl;
    return str;
}

int GetXMLData(string strFileName) {

    char pLine[ 256 ]; //array of chars where the lines of the xml file goes at first
    string sLine; // line then are stored into sLine so the can manipulated as strings 
    int iLineNum = 1; // Line counter
    ParserState xmlState = STARTING_DOC; // sets parser state to starting doc
    //ShowParserState(xmlState); // show starting cod state
    //xmlElements *PtrcurrEle = NULL;
    string currEle; // string place-holder for elements names
    string cont = "{EMPTY}"; // string place-holder for element content
    ifstream xmlSongLib((strFileName).c_str());

    if (xmlSongLib.is_open()) { // runs if file opens 
        while (xmlSongLib.getline(pLine, 256) != NULL) { //takes a line from the file until it reaches EOF
            sLine = pLine; // sets sLine to pLine
            sLine = trim(sLine); //trims string of leading/tailing white space
            cout << iLineNum << ": " << sLine << endl;
            int begin = sLine[0]; //sets begin to the beginning of sLine
            int end = (sLine.length() - 1); //sets end to end of sLine
            //calls GetXML to which finds the state the parser is in and sets 
            //the content and element name if there is any
            xmlState = GetXML(sLine, currEle, cont, begin, end, xmlState);

            //cout << "*** ";
            switch (xmlState) {
                case UNKNOWN: // triggers in unknown state
                    cout << "*** Parser state unknown." << endl << endl;
                    break;
                case DIRECTIVE: // triggers in directive state
                    cout << "*** Directive: " << xmlTemp.getContent() << endl << endl;
                    break;
                case STARTING_COMMENT: // triggers in comment starting state
                    cout << "*** Starting Comment." << endl << endl;
                    break;
                case IN_COMMENT: // triggers when inside a comment 
                    cout << "*** Comment Line." << endl << endl;
                    break;
                case ENDING_COMMENT: // triggers when a comment ends
                    cout << "*** Ending Comment." << endl << endl;
                    break;
                case ONE_LINE_COMMENT: // triggers when we hit a one line comment 
                    cout << "*** One Line Comment: " << xmlTemp.getContent() << endl << endl;
                    break;
                case ELEMENT_OPENING_TAG: // triggers when we find an element opening tag
                    currEle = xmlTemp.getEle();
                    cout << "*** Element Opened: " << currEle << endl;
                    xmlElements *xmlEle = new xmlElements(iLineNum,
                            currEle, cont); // creates new xmlElements
                    xmlEleStack.push_back(xmlEle); // pushes new xmlElements onto stack
                    showVectorStack(xmlEleStack); // prints stack
                    cout << endl;
                    break;
                case ELEMENT_NAME_AND_CONTENT: // triggers when we find an element opening and closing tag on the same line
                    cout << "*** Complete element found:" << endl;
                    cout << "***  Element Name: " << xmlTemp.getEle() << endl;
                    cout << "***  Element Content: " << xmlTemp.getContent() << endl;
                    cout << "*** Vector (stack) is unchanged." << endl << endl;
                    break;
                case SELF_CLOSING_TAG: // triggers when we find a self closing tag
                    cout << "*** Self-closing element found: " << endl;
                    cout << "***  Element Name: " << xmlTemp.getEle() << endl;
                    cout << "***  Element Content: {EMPTY}" << endl;
                    break;
                case ELEMENT_CLOSING_TAG: // triggers when we find a element closing tag
                    xmlElements *tempEle = xmlEleStack.back();
                    cout << "*** Element Closed: " << tempEle->getEle() << endl;
                    xmlEleStack.pop_back();
                    showVectorStack(xmlEleStack);
                    cout << endl;
            }
            ++iLineNum;
        }
    } else { //else occurrence if file fails to open
        cout << "Cannot open file." << endl;
    }
    xmlSongLib.close(); // closes file
    return 0;
}

// mani function, only calls GetXMLData and return 0 when it is finished

int main(int argc, char** argv) {

    GetXMLData("SongLib.xml");

    return 0;
}
