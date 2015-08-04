// BankAccount member-func def

#include <iostream>
#include <string>
#include <vector>
#include "BankAccount.h"
using namespace std;

BankAccount::BankAccount( double balance, int number, string type )
{
  vectorSet();
  setAccountType( type );
  setAccountNum( number );
  if( balance < 500 )
    cout << "Blance to low, must be at keast 500 USD." << endl;
  else
    setAccountBalance( balance );
}

void BankAccount::setAccountType( string type )
{
  AccountTypeName = type;
}

string BankAccount::getAccountType() const
{
  return AccountTypeName;
}

void BankAccount::setAccountNum( int num )
{
  AccountNumber = num;
}

int BankAccount::getAccountNum() const
{
  return AccountNumber;
}

void BankAccount::setAccountBalance( double balance )
{
  AccountBalance = balance;
}

double BankAccount::getAccountBalance() const
{
  return AccountBalance;
}

void BankAccount::toString( BankAccount acc )
{
  cout << "Account number: " << acc.getAccountNum() << endl;
  cout << "Account balance: " << acc.getAccountBalance() << endl;
  cout << "Account type: " << acc.getAccountType() << endl;
}
