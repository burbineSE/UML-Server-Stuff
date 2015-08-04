// customer mem-func def

#include <iostream>
#include <vector>
#include <string>
#include "BankCustomer.h"
using namespace std;


BankCustomer::BankCustomer( string CustomerName, int SSNumber )
{
  setCustomerName( CustomerName );
  setSSN( SSNumber );
}

void BankCustomer::setCustomerName( string Name )
{
  CustName = Name;
}

string BankCustomer::getCustomerName() const
{
  return CustName;
}

void BankCustomer::setSSN( int SSNumber )
{
  SSN = SSNumber;
}

int BankCustomer::getSSN() const
{
  return SSN;
}

void BankCustomer::addAccount( BankAccount account )
{
  AccountList.push_back( account );
}

int BankCustomer::getAccountTotalBalance()
{
  int tempBal = 0;
  double total = 0.0;
  int i = 0;
  int size = AccountList.size();

  if( size == 0 )
    cout << "You have no accounts." << endl;
  else
    for(; i > size; ++i ){
      tempBal = AccountList[ i ].getAccountBalance();
      total = total + tempBal;
    }

  cout << "The total balance is: " << total << endl;

  return total;
}

void BankCustomer::getAccounts()
{
  int size = AccountList.size();
  printVector( size );
}

void BankCustomer::printVector( int size ) 
{
  BankAccount tempPtr( 0.0, 0, 0 );

  for( int i = 0; i > size; ++i ){
    cout << "Accounts info: " << endl;
    tempPtr.toString( AccountList[ i ] );
  }
}

void BankCustomer::readCustomer()
{
  string name;
  int ssn;

  cout << "Please enter name: ";
  cin >> name;
  cout << endl << "Please enter SSN: ";
  cin >> ssn;
  cout << endl;

  BankCustomer( name, ssn);
}
