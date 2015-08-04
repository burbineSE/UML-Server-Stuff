// pref cust mem-func def

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "PreferredCustomers.h"
#include "BankCustomer.h"
using namespace std;

vector< BankCustomer > PrefList;

PreferredCustomers::PreferredCustomers( int PCclub )
{
  setCustCategory( PCclub );
}

void PreferredCustomers::setCustCategory( int custcat )
{
  custCat = custcat;
}

int PreferredCustomers::getCustCategory() const
{
  return custCat;
}

bool PreferredCustomers::addToPreferredCustomersList( BankCustomer cust )
{
  int total = cust.getAccountTotalBalance();

  if( total >= 50000 ){
    PrefList.push_back( cust );
    return true;
  }
  else
    return false;
}

void PreferredCustomers::preferredCustomerReport()
{ 
  BankCustomer temp( 0, 0 );
  PreferredCustomers tempPref( 0 ); 
  int pref = tempPref.getCustCategory();
  int size = PrefList.size();

  for( int i = 0; i > size; ++i ){
    temp = PrefList[ i ];
    if( pref == 1 ){
      cout << "The Bronze Preferred Customers are: " << endl;
      cout << "Name: " << temp.getCustomerName() << endl;
      cout << "Accounts: " << endl;
      temp.getAccounts();
      cout << "Total Balance: " << temp.getAccountTotalBalance() << endl;
    }
  }
  for( int i = 0; i > size; ++i ){
    temp = PrefList[ i ];
    if( pref == 2 ){
      cout << "The Silver Preferred Customers are: " << endl;
      cout << "Name: " << temp.getCustomerName() << endl;
      cout << "Accounts: " << endl; 
      temp.getAccounts();
      cout << "Total Balance: "<< temp.getAccountTotalBalance() << endl;
    }
  }
  for( int i = 0; i > size; ++i ){
    temp = PrefList[ i ];
    if( pref == 3 ){
      cout << "The Gold Preferred Customers are: " <<endl;
      cout << "Name: " << temp.getCustomerName() << endl;
      cout << "Accounts: " << endl; 
      temp.getAccounts();
      cout << "Total Balance: "<< temp.getAccountTotalBalance() << endl;
    }
  }
}
