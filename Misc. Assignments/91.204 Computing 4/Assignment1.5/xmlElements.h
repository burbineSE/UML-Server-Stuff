/* 
 * File:   xmlElements.h
 * Author: Chris
 *
 * Created on September 12, 2012, 3:51 PM
 */

#ifndef XMLELEMENTS_H
#define	XMLELEMENTS_H

#include <string>
#include <fstream>
using namespace std;

class xmlElements
{
public:
  xmlElements( int, string );
  void setEle( string );
  string getEle() const;
  void setLine( int );
  int getLine() const;
  ifstream FileOpener( string );
  void xmlFileSearch();
  void printXmlVect();
private:
  string element;
  int lineNum;
};

#endif
