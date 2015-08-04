// Deck of Cards class def

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <string>
#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

class DeckofCards
{
 public:
  DeckofCards();

  void setcurrentCard( Card );
  Card getcurrentCard() const;

  void shuffle();
  Card dealCard();
  bool moreCards();

 private:
  vector< Card > deck;
  Card currentCard;
};

#endif
