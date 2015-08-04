// Card member-function def

#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

static const string Faces[13] = {"2", "3", "4", "5", "6", "7", "8", "9",
				 "10", "Jack",  "Queen", "King", "Ace" };
static const string Suits[4] = { "Spades", "Hearts", "Diamonds", "Clubs" };

Card::Card( int face, int suit )
{
  setFace( face );
  setSuit( suit );
}
void Card::setFace( int face )
{
  cardFace = face;
}

int Card::getFace() const
{
  return cardFace;
}

void Card::setSuit( int suit )
{
  cardSuit = suit;
}

int Card::getSuit() const
{
  return cardSuit;
}

void Card::toString( int face, int suit )
{
  cout << "The card it the " << Faces[ face ]<< endl;
  cout << " of " << Suits[ suit ] << endl;
}
