// bank customer class def

#ifndef BANKCUSTOMER_H
#define BANKCUSTOMER_H

#include <vector>
#include <string>
#include "BankAccount.h"
using namespace std;

class BankCustomer
{
 public:
  BankCustomer( string, int );

  void setCustomerName( string );
  string getCustomerName() const;

  void setSSN( int );
  int getSSN() const;

  void addAccount( BankAccount );
  int getAccountTotalBalance();
  void getAccounts();

  void printVector( int );
  
  void readCustomer();

 private:
  vector< BankAccount > AccountList;
  string CustName;
  int SSN;
};

#endif
