// Bank cust test file

#include <iostream>
#include "BankCustomer.h"
using namespace std;

int main()
{
  BankCustomer cust1( 'Moe',   12345 );
  BankCustomer cust2( 'Larry', 84562 );
  BankCustomer cust2( 'Curly', 74519 );

  BankAccount acc1M( 5824.36,   4856254,  'Checking' );
  BankAccount acc2M( 875.65,    7845965,  'Saving' );
  BankAccount acc3M( 874562.65, 8741247,  'Deposit' );

  BankAccount acc1L( 541.25,    7846515,  'Checking' );
  BankAccount acc2L( 878451.50, 5541122,  'Saving' );
  BankAccount acc3L( 877.05,    8845122,  'Deposit' );
 
  BankAccount acc1C( 8746.24,   8754213,  'Checking' );
  BankAccount acc2C( 985.45,    7745412,  'Saving' );
  BankAccount acc3C( 1452.36,   8741119,  'Deposit' );


  addAccount( cust1, acc1M );
  addAccount( cust1, acc2M );
  addAccount( cust1, acc3M );

  addAccount( cust2, acc1L );
  addAccount( cust2, acc2L );
  addAccount( cust2, acc3L );

  addAccount( cust3, acc1C );
  addAccount( cust3, acc2C );
  addAccount( cust3, acc3C );

  getAccountTotalBalance( cust1 );
  getAccountTotalBalance( cust2 );
  getAccountTotalBalance( cust3 );

  getAccounts( cust1 );
  getAccounts( cust2 );
  getAccounts( cust3 );

  return 0;
}

