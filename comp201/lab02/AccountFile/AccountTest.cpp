// test file for Account

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

int main()
{

  Account balance1( 1000 );
  cout << "Balance if account one: $" 
       << balance1.getBalance() << endl;

  Account balance2( 0 );
  cout << "Balance of account two: $" 
       << balance2.getBalance() << endl;

  // used to keep track or account numbers
  int accountHolder1, accountHolder2;

  accountHolder1 = balance1.debit( 400 );
  accountHolder2 = balance2.debit( 100 );

  //creates new balnaces from the holders
  Account new_balance1( accountHolder1 );
  Account new_balance2( accountHolder2 );

  accountHolder1 = new_balance1.credit( 200 );
  accountHolder2 = new_balance2.credit( 300 );

  balance1.addAccountBalance( accountHolder1, accountHolder2 );

  return 0;
}
