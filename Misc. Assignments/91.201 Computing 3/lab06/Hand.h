// Hand class def

#ifndef HAND_H
#define HAND_H

#include <string>
#include <iostream>
#include <vector>
#include "Card.h"
#include "DeckofCards.h"

using namespace std;

class Hand
{
 public:
  Hand( int );

  void setHandSize( int );
  int getHandSize() const;

  void addCard( Card );
  void print() const;
  bool pair() const;
  bool twoPair() const;
  bool threeOfAKind() const;
  bool fourOfAKind() const;
  bool flush() const;
  bool straight() const;

 private:
  int handsize;
  vector< Card > hand;
};

#endif
