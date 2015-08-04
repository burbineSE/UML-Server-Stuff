// Deck of cards member-function def

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Card.h"
#include "DeckofCards.h"
using namespace std;

DeckofCards::DeckofCards(): currentCard(0,0)
{
  int suit = 0;
  int face = 0;
  deck.reserve( 52 );

  for(; suit < 3; suit++ ){
    for(; face < 12; face++ ){
      Card card( face, suit );
      deck.push_back( card );
    }
  }
  setcurrentCard( deck[ 51 ] );
}

void DeckofCards::setcurrentCard( Card topCard )
{
  currentCard = topCard;
}

Card DeckofCards::getcurrentCard() const
{
  return currentCard;
}

void DeckofCards::shuffle( vector< Card > &Deck )
{
  Card temp( 0, 0 );
  int randNum = 0;

  for( int i = 0; i < 52; i++ ){
    srand( time( NULL ));
    randNum = rand() % 52;
    temp = Deck[ i ];
    Deck[ i ] = Deck[ randNum ];
    Deck[ randNum ] = temp;
  }
}

Card DeckofCards::dealCard( vector< Card > &Deck )
{
  Card temp( 0, 0 );
  temp = Deck[ Deck.size() - 1 ];

  Deck.pop_back();

  setcurrentCard( Deck[ Deck.size() - 1 ] );

  return temp;
}

bool DeckofCards::moreCards( vector< Card > &Deck )
{
  if( Deck.size() <= 0 )
    return false;
  else
    return true;
}