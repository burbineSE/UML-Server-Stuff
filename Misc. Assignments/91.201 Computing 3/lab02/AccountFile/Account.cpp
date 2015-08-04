// Account member-function def

#include <iostream>
#include "Account.h"
using namespace std;

// inits balance to zero
Account::Account()
{
  balance = 0;
}

// calls setBalance
Account::Account( int UserBalance )
{
  setBalance( UserBalance );
}

// sets balance to user input 
// if input is less than zero returns error message
void Account::setBalance( int UserBalance )
{
  if( UserBalance <= 0 ){
    cout << "\nBalance invaild" << endl;
    balance = 0;
  }
  else 
    balance = UserBalance;
}

// returns balance
int Account::getBalance()
{
  return balance;
}

// adds addedNum to current balance
int Account::credit( int addedNum )
{
  if( addedNum >= 0 )
    {
      balance = balance + addedNum;
      cout << "\nNew balance is\n$" 
	   << getBalance() << endl; 
    }
  return balance;
}

// subs subedNum from current balance
int Account::debit( int subedNum )
{
  if( subedNum > balance )
    cout << "\nInsufficient funds" << endl;
  else{
    balance = balance - subedNum;
    cout << "\nNew balance is\n$"
	 << getBalance() << endl;
  }
  return balance;
}

// adds amount of balances togther
int Account::addAccountBalance( int balance1, int balance2 )
{
  this-> balance = balance1 + balance2;

  cout << "\nTotal balance is\n$"
       << getBalance() << endl;

  return balance;
}
