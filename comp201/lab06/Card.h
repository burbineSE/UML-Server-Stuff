// Card class def

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
using namespace std;

class Card
{ 
public:
  // static const string Faces[13] = {"2", "3", "4", "5", "6", "7", "8", "9",
  //                               "10", "Jack",  "Queen", "King", "Ace" };
  //static const string Suits[4] = { "Spades", "Hearts", "Diamonds", "Clubs" };

  Card( int, int );

  void setFace( int );
  int getFace() const;

  void setSuit( int );
  int getSuit() const;

  void toString( int, int );

 private:
  //  static const string Faces[13] = {"2", "3", "4", "5", "6", "7", "8", "9",
				   //				   "10", "Jack",  "Queen", "King", "Ace" };
  //static const string Suits[4] = { "Spades", "Hearts", "Diamonds", "Clubs" };
  int cardFace;
  int cardSuit;
};

#endif
