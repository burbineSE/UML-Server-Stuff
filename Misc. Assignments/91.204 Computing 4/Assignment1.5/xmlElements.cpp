#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "xmlElements.h"
using namespace std;

vector< xmlElements* > xmlVect;

xmlElements::xmlElements( int lineNumber, string eleName )
{
    setEle( eleName );
    setLine( lineNumber );
}

void xmlElements::setEle( string eleName )
{
    element = eleName;
}

string xmlElements::getEle() const
{
    return element;
}

void xmlElements::setLine( int lineNumber )
{
    lineNum = lineNumber;
}

int xmlElements::getLine() const
{
    return lineNum;
}

//ifstream xmlElements::FileOpener( string fileName )
//{
 // char* pcharFileName = new char[ fileName.size() + 1 ];
 // strcpy( pcharFileName, fileName.c_str() );
 // ifstream ifmyStream( pcharFileName );

 // return ifmyStream;
//}

void xmlElements::xmlFileSearch()
{
  char pLine[ 256 ];
  string sLine;
  int iLineNum = 1;
  int closeB;
  //ifstream xmlSongLib = FileOpener( "SongLib.xml" );
  ifstream xmlSongLib( "SongLib.xml");

  if( xmlSongLib.is_open() )
    {
      while( xmlSongLib.getline( pLine, 256 ) != NULL )
	{
	  sLine = pLine;
	  int openB = sLine.find( "<" );
	  if( sLine.find_first_of( "=" ) == true )
	    {
	      sLine.erase( 0, openB );
	      closeB = sLine.find( " " );
	    }
	  else{
	    closeB = sLine.find( ">" );
	  }
          
	  string temp = sLine.substr( openB, ( closeB - openB ));

	  if( temp.find_first_of( "?!/" ) == true ) {}
          else{
	    xmlElements xmlEle( iLineNum, temp );
	    xmlVect.push_back( &xmlEle );
	  }
	  ++iLineNum;
        }
      xmlSongLib.close();
    }

  else cout << "Cannot open file." << endl;
  
  printXmlVect();
}

void xmlElements::printXmlVect()
{
    string sPart;
    int iPart;
    
    for( vector< xmlElements* >::iterator iIter = xmlVect.begin(); iIter != xmlVect.end(); ++iIter)
    {
    cout << (*iIter)->getLine() << " " << (*iIter)->getEle() << endl;    
    }
}
