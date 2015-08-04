// Hend member-function def

#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"
#include "Card.h"
#include "DeckofCards.h"
using namespace std;

Hand::Hand( int handP )
{
  setHandSize( handP );
  int handS = getHandSize();

  for( int i = 0; i < handS; i++ ){
    hand.push_back( deck[ deck.size() -1 ] );
    deck.pop_back();
  }
  setcurrentCard( deck[ deck.size() - 1 ] );
}

void Hand::setHandSize( int handS )
{
  handsize = handS;
}

int Hand::getHandSize() const
{
  return handsize;
}

void Hand::addCard( Card addcard )
{
  int handSize = hand.size();
  if( handSize == handsize )
    cout << "Hand is full." << endl;
  else
    hand.push_back( addcard );
}

void Hand::print() const
{
  Card card( 0, 0 );
  int face, suit;
  int handSize = hand.size();
  cout << "Your hand contains: " << endl;

  for( int i = 0; i < handSize; i++ ){
    card = hand[ i ];
    face = card.getFace();
    suit = card.getSuit();
    cout << "A " << face << " of " << suit << ", "<< endl;
  }
}

bool Hand::pair() const
{
  int firstcard;
  int secondcard;
  Card card1( 0, 0 );
  Card card2( 0, 0 );
  for( int i = 0; i < handsize; i++ ){
    card1 = hand[ i ];
    for( int j = i + 1; j < handsize; j++ ){
      card2 = hand[ j ];
      if ( j > handsize )
	return false;
      else{
	firstcard = card1.getFace(); 
	secondcard = card2.getFace();
	if( firstcard == secondcard )
	  return true;
      }
    }
  }
  return false;
}

bool Hand::twoPair() const
{
  int k = 0;

  int firstcard;
  int secondcard;
  Card card1( 0, 0 );
  Card card2( 0, 0 );
  for( int i = 0; i < handsize; i++ ){
    card1 = hand[ i ];
    for( int j = i + 1; j < handsize; j++ ){
      card2 = hand[ j ];
      if ( j > handsize )
        return false;
      else{
        firstcard = card1.getFace();
        secondcard = card2.getFace();
        if( firstcard == secondcard )
          k++;
	if( k == 2 )
	  return true;
      }
    }
  }
  return false;
}


bool Hand::threeOfAKind() const
{
  int k = 0;

  int firstcard;
  int secondcard;
  Card card1( 0, 0 );
  Card card2( 0, 0 );
  for( int i = 0; i < handsize; i++ ){
    card1 = hand[ i ];
    for( int j = i + 1; j < handsize; j++ ){
      card2 = hand[ j ];
      if ( j > handsize )
        return false;
      else{
        firstcard = card1.getFace();
        secondcard = card2.getFace();
        if( firstcard == secondcard )
          k++;
        if( k == 3 )
          return true;
      }
    }
  }
  return false;
}

bool Hand::fourOfAKind() const
{
  int k = 0;

  int firstcard;
  int secondcard;
  Card card1( 0, 0 );
  Card card2( 0, 0 );
  for( int i = 0; i < handsize; i++ ){
    card1 = hand[ i ];
    for( int j = i + 1; j < handsize; j++ ){
      card2 = hand[ j ];
      if ( j > handsize )
        return false;
      else{
        firstcard = card1.getFace();
        secondcard = card2.getFace();
        if( firstcard == secondcard )
          k++;
        if( k == 4 )
          return true;
      }
    }
  }
  return false;
}

bool Hand::flush() const
{
  int k = 0;

  int firstcard;
  int secondcard;
  Card card1( 0, 0 );
  Card card2( 0, 0 );
  for( int i = 0; i < handsize; i++ ){
    card1 = hand[ i ];
    for( int j = i + 1; j < handsize; j++ ){
      card2 = hand[ j ];
      if ( j > handsize )
        return false;
      else{
        firstcard = card1.getSuit();
        secondcard = card2.getSuit();
        if( firstcard == secondcard )
          k++;
        if( k == 5 )
          return true;
      }
    }
  }
  return false;
}

bool Hand::straight() const
{
  int k = 0;

  int firstcard, secondcard, thridcard, fourthcard, fithcard;
  Card card1( 0, 0 );
  Card card2( 0, 0 );
  Card card3( 0, 0 );
  Card card4( 0, 0 );
  Card card5( 0, 0 );
  
  firstcard = card1.getFace();
  secondcard = card2.getFace();
  thridcard = card3.getFace();
  fourthcard = card4.getFace();
  fithcard = card5.getFace();

  if(       
