/* 
 * File:   xmlMusicLibReader.cpp
 * Author: Chris Burbine, christopher_burbine@student.uml.edu
 * 
 * Created on September 30, 2012, 8:36 PM
 * Updated on October 15, 2012, 2:25 PM
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
#include "Attribute.h"

//vector< xmlElements* > xmlVect; //storage vector for the element name and line numbers, Not used in this build
/** storage vector used like a stack
 *@since Assignment 2  
 */
vector< xmlElements* > xmlEleStack; 
/** xmlElments vector used to initialize the root*/
vector< xmlElements* > newXML;
/** Attribute vector used to initialize the root*/
vector< Attribute* > newAttr;
/** global root xmlEle, where the tree is stored after the xml file is parsed*/
xmlElements root(0, "name", "content", newXML, newAttr); 
/** global placeholder for xmlElements*/
xmlElements xmlTemp; 
/** global bool used to check weather a line contained an Attribute*/
bool attrCheck;
/** global level indicator for the tree traversal*/
int treeLevel = 1;

/** enum contains various parser states*/
enum ParserState {
    UNKNOWN, STARTING_DOC, DIRECTIVE,
    ELEMENT_OPENING_TAG, ELEMENT_CONTENT, ELEMENT_NAME_AND_CONTENT,
    ELEMENT_CLOSING_TAG, SELF_CLOSING_TAG, STARTING_COMMENT,
    IN_COMMENT, ENDING_COMMENT, ONE_LINE_COMMENT, ERROR
};

using namespace std;

/** 
 * default constructor, initializes temporary data members as a placeholder
 */
xmlMusicLibReader::xmlMusicLibReader() {
}

/** NetBeans-supplied constructor*/
xmlMusicLibReader::xmlMusicLibReader(const xmlMusicLibReader& orig) {
}

/** NetBeans-supplied destructor*/
xmlMusicLibReader::~xmlMusicLibReader() {
}

/** file opening function created for Assignment 1, not used in Assignment 3*/
/*ifstream xmlMusicLibReader::FileOpener(string fileName, ifstream &IFStream) {
    // string constructor
    char* pcharFileName = new char[ fileName.size() + 1 ];
    strcpy( pcharFileName, fileName.c_str() );
    //ifstream ifmyStream(pcharFileName);

    //return ifmyStream;
    IFStream.open( pcharFileName );
}*/

/** vector printing function created in Assignment 1, not used in Assignment 3*/
/*void xmlMusicLibReader::printXmlVect() {
    // creates a vector iterator iIter to go through xmlVect 
    for (vector< xmlElements* >::iterator iIter = xmlEleStack.begin(); iIter != xmlEleStack.end(); ++iIter) {
        //prints out the data in xmlVect line by line
        cout << "Element [" << (*iIter)->getEle() << "] found on line #" << (*iIter)->getLine() << "." << endl;
    }
}*/

/** returns a pointer to the element stack used in Assignment 1, not used in assignment 3
 This method added by Prof. Heines in a help session.*/
/*vector< xmlElements* >* xmlMusicLibReader::getVector() {
    return &xmlEleStack;
}*/

/**
 * Parser state debugging function, Function provided by Prof. Heines
 * @param pstate current state of the parser
 */
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
        case ERROR: cout << "ERROR"; // shows when the parser finds and error
            break;
        default: cout << "UNKNOWN"; // shows in unknown state
            break;
    }
    cout << endl;
}

/** early attempts as an attribute extractor, model used later*/
/*Attribute AttrExtractor(string lineIn, int LineN) {

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

/**
 * xml tree dump, prints out tree structure 
 * @param xmlRoot takes in the xml root
 * @return zero when the the end of the vector has been reached
 */
int xmlTreeDump(xmlElements xmlRoot) {
    
    // temp pointers to the Attr and xmlEle vectors of the current element
    vector< xmlElements* >* tempVectEleRoot = xmlRoot.getVectorEle();
    vector< Attribute* >* tempVectAttrRoot = xmlRoot.getVectorAttr();

    //prints out the element name, line number and content 
    cout << right << setw(treeLevel) << setfill('.') << " "
            << "Element: " << xmlRoot.getEle() << ";"
            << " found on line: #" << xmlRoot.getLine() << ";"
            << " with content: " << xmlRoot.getContent() << "." << endl;

    //prints out the Attribute name and value if is any
    if (!(tempVectAttrRoot->empty())) {
        for (int iterAttrVect = 0; iterAttrVect < tempVectAttrRoot->size(); ++iterAttrVect) {
            Attribute *tempAttrVect = tempVectAttrRoot->back();
            cout << right << setw((treeLevel + 1)) << setfill('.') << " " 
                    << "(Attribute of " << xmlRoot.getEle() << " found; attribute name: " << tempAttrVect->getAttrName() << ";"
                    << " attribute value: " << tempAttrVect->getAttrVal() << ".)" << endl;
            tempVectAttrRoot->pop_back();
        }
    }
    
    //checks to see of the vector of the current element id empty
    if( tempVectEleRoot->empty()){
        //cout << "Empty Called" << endl << endl;
        --treeLevel;
        return 0;
    }
    //while it's not empty the tree dump function is called 
    while(!(tempVectEleRoot->empty())){
        xmlElements *xmlTreeTemp = tempVectEleRoot->front();
        //cout << xmlTreeTemp->getContent() << " " << (*xmlTreeTemp).getContent() << endl;
        ++treeLevel;
        xmlTreeDump( *xmlTreeTemp );
        
        //bit of cheaty way of getting the tree to print as I wanted, could not find a better method
        string rootEle = "metadata";
        string checkEle = xmlTreeTemp->getEle();
                
        if( rootEle == checkEle ){
            treeLevel = 1;
        }
        tempVectEleRoot->erase( tempVectEleRoot->begin() );
    }
}

/**
 * function show the contents of the vector (stack) that holds the element names
 * general function outline taken from Deitel text p868-869
 * @param vect vector to be printed
 */
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

/**
 * parser for a xml file
 * @param strLine line to be looked at
 * @param strEleName line name to be set
 * @param strCont line content to be set
 * @param nStart line staring position 
 * @param nEnd line ending position
 * @param CurrentState line current state
 * @return parser state of the line in
 */
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
                    attrCheck = true;
                    firstCloseB = strLine.find(" ");
                    strEleName = strLine.substr(firstOpenB + 1, (firstCloseB - firstOpenB - 1));
                    //cout << "New Element name: " << strEleName << endl;
                    xmlTemp.setEle(strEleName);
                } else {
                    attrCheck = false;
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

/**
 * Trims leading and tailing white space and tab from string passed
 * Function written by Prof. Heines, taken from class notes Sept. 18, 2012
 * @param str xml file line in
 * @return trimmed line to be used in the parse
 */
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

/**
 * bulk of the file, looks at the state of each line in the xml file
 * @param strFileName name of the xml file to be parsed
 * @return zero at end of parse of is the file could not be opened
 */
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
            //cout << iLineNum << ": " << sLine << endl;
            int begin = sLine[0]; //sets begin to the beginning of sLine
            int end = (sLine.length() - 1); //sets end to end of sLine
            //calls GetXML to which finds the state the parser is in and sets 
            //the content and element name if there is any
            xmlState = GetXML(sLine, currEle, cont, begin, end, xmlState);

            switch (xmlState) {
                case UNKNOWN: // triggers in unknown state
                    //cout << "*** Parser state unknown." << endl << endl;
                    break;
                case DIRECTIVE: // triggers in directive state
                    //cout << "*** Directive: " << xmlTemp.getContent() << endl << endl;
                    break;
                case STARTING_COMMENT: // triggers in comment starting state
                    //cout << "*** Starting Comment." << endl << endl;
                    break;
                case IN_COMMENT: // triggers when inside a comment 
                    //cout << "*** Comment Line." << endl << endl;
                    break;
                case ENDING_COMMENT: // triggers when a comment ends
                    //cout << "*** Ending Comment." << endl << endl;
                    break;
                case ONE_LINE_COMMENT: // triggers when we hit a one line comment 
                    //cout << "*** One Line Comment: " << xmlTemp.getContent() << endl << endl;
                    break;
                case ELEMENT_OPENING_TAG: // triggers when we find an element opening tag
                    currEle = xmlTemp.getEle();
                    //cout << "*** Element Opened: " << currEle << endl;
                    cont = "{EMPTY}";
                    xmlElements *xmlEle = new xmlElements(iLineNum, currEle,
                            cont, newXML, newAttr); // creates new xmlElements
                    
                    //temp xmlElements and Attribute vectors to hold the current element vectors
                    vector< xmlElements* >* tempVectEle = xmlEle->getVectorEle();
                    vector< Attribute* >* tempVectAttr = xmlEle->getVectorAttr();
                    
                    //extracts Attributes if there are any, method seen above
                    if (attrCheck == true) { 
                        //cout << "Attr Ex entered" << endl;
                        int spaceOp;
                        spaceOp = sLine.find(" ");
                        //cout << "Space found at " << spaceOp << endl;
                        int EQSign;
                        EQSign = sLine.find_first_of("=");
                        //cout << "Equals sign found at " << EQSign << endl;

                        string attrName = sLine.substr((spaceOp + 1), (EQSign - spaceOp - 1));
                        //cout << "Attr Name " << attrName << endl;

                        int openQ = (EQSign + 2);
                        //cout << "Value start " << openQ << endl;
                        int closeB = sLine.find_first_of(">");
                        int closeQ = (closeB - 1);
                        //cout << "Value end " << closeQ << endl;

                        string attrValue = sLine.substr(openQ, closeQ - openQ);
                        //cout << "Attr Value " << attrValue << endl;

                        Attribute *attrTemp = new Attribute(iLineNum, attrName, attrValue);
                        //cout << "Name: " << attrTemp->getAttrName() << " Value: " << attrTemp->getAttrVal() << endl;
                        (*tempVectAttr).push_back(attrTemp);
                        //cout << "Attr Vector size: " << tempVectAttr->size() << endl;
                    }
                    // only occurs in the case of the root, all it does is push the element onto the stack
                    if (xmlEleStack.empty()) {
                        xmlEleStack.push_back(xmlEle);
                        //occurs in every other case, not only pushes the element onto the stack but also onto the vector of the element before it
                    } else {
                        xmlElements *tempEleOpenTag = xmlEleStack.back();
                        //cout << "Back of stack ele: " << tempEleOpenTag->getEle() << " Back of stack cont: " << tempEleOpenTag->getContent() << endl;
                        //tempEleOpenTag->setContent("Testing, is this thing on?");
                        //cout << "Back of stack ele: " << tempEleOpenTag2->getEle() << " Back of stack cont: " << tempEleOpenTag2->getContent() << endl;
                        vector< xmlElements* >* tempVectEleBackOT = tempEleOpenTag->getVectorEle();

                        (*tempVectEleBackOT).push_back(xmlEle);

                        //cout << "!!! Ele parent: " << tempEleOpenTag->getEle() << endl;
                        //cout << "!!! XmlEle back Vector size: " << tempVectEleBackOT->size() << endl;

                        xmlEleStack.push_back(xmlEle);
                    }
                    //xmlEleStack.push_back(xmlEle); // pushes new xmlElements onto stack
                    //showVectorStack(xmlEleStack); // prints stack
                    //cout << endl;
                    break;
                    // triggers when we find an element opening and closing tag on the same line
                    // does the same thing at the else case in the element opening tag case
                case ELEMENT_NAME_AND_CONTENT: 
                    //cout << "*** Complete element found:" << endl;
                    //cout << "***  Element Name: " << xmlTemp.getEle() << endl;
                    //cout << "***  Element Content: " << xmlTemp.getContent() << endl;
                    //cout << "*** Vector (stack) is unchanged." << endl;

                    xmlElements *xmlEleNAC = new xmlElements(iLineNum, currEle,
                            cont, newXML, newAttr); // creates new xmlElements

                    xmlElements *tempEleNameAndCont = xmlEleStack.back();
                    vector< xmlElements* >* tempVectEleBackNAC = tempEleNameAndCont->getVectorEle();

                    (*tempVectEleBackNAC).push_back(xmlEleNAC);

                    //cout << "!!! Ele parent: " << tempEleNameAndCont->getEle() << endl;
                    //cout << "!!! XmlEle back Vector size: " << tempVectEleBackNAC->size() << endl;

                    //cout << endl;
                    break;
                case SELF_CLOSING_TAG: // triggers when we find a self closing tag
                    //cout << "*** Self-closing element found: " << endl;
                    //cout << "***  Element Name: " << xmlTemp.getEle() << endl;
                    //cout << "***  Element Content: {EMPTY}" << endl;
                    break;
                case ELEMENT_CLOSING_TAG: // triggers when we find a element closing tag
                    // stores the last element on the stack into the global root if we hit the end of the file
                    if (xmlEleStack.size() == 1) {
                        xmlElements *tempEleCloseTag = xmlEleStack.back();
                        //root = tempEleCloseTag;
                        //root = xmlEleStack.back();
                        //cout << "%%%%%Root name: " << tempEleCloseTag->getEle() << " Root cont: " << root->getContent() << endl;
                        //cout << "%%%%%Root name: " << root->getEle() << " Root cont: " << root->getContent() << endl;

                        root.setEle(tempEleCloseTag->getEle());
                        root.setContent(tempEleCloseTag->getContent());
                        root.setLine(tempEleCloseTag->getLine());

                        vector< xmlElements* >* tempVectEleBackCT = tempEleCloseTag->getVectorEle();
                        vector< xmlElements* >* tempVectRoot = root.getVectorEle();

                        tempVectRoot->insert(tempVectRoot->end(), tempVectEleBackCT->begin(), tempVectEleBackCT->end());
                    }
                    //xmlElements *tempEle = xmlEleStack.back();
                    //cout << "*** Element Closed: " << tempEle->getEle() << endl;
                    xmlEleStack.pop_back();
                    //showVectorStack(xmlEleStack);
                    //vector < xmlElements* >* xmlTestVect = root.getVectorEle();
                    //cout << "%%%%%Root name: " << root.getEle() << " Root cont: " << root.getContent() << endl;
                    //cout << "%%%%%Line number: " << root.getLine() << " Size of xmlEle vector: " << xmlTestVect->size() << endl;
                    //cout << endl;
            }
            ++iLineNum;
        }
    } else { //else occurrence if file fails to open
        cout << "Cannot open file." << endl;
    }
    xmlTreeDump(root);
    xmlSongLib.close(); // closes file
    return 0;
}

/**
 * Standard C++ main function
 * @param argc number of command line arguments 
 * @param argv array of pointers to command line arguments
 * @return zero upon the file ending
 */
int main(int argc, char** argv) {

    GetXMLData("SongLib.xml");

    return 0;
}
