// Deck of Cards test file

#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include "DeckofCards.h"
using namespace std;

int main()
{
  DeckofCards deck1;
  Card temp( 0, 0 );

  deck1.shuffle();

  for( int i = 0; i < 52; i++ ){
    temp = deck1.dealCard();
    int face = temp.getFace();
    int suit = temp.getSuit();
    temp.toString( face, suit );
    if( deck1.moreCards() == false ){
      return 0;
    }
  }
  return 0;
}
