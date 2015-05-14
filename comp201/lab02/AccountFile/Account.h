// Account class definition

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account
{
 public:
  Account(); // initializes balance to zero
  Account( int ); // init balance to user input
  void setBalance( int ); // sets balance to user input
  int getBalance(); // returns balance
  int credit( int ); // adds user amount to current balance
  int debit( int ); // subs user amount from current balace
  int addAccountBalance( int, int ); // adds balaneces together and returns
 private:                            // total
  int balance;
};

#endif
