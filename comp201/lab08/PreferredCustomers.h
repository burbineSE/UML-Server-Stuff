// preferred cust member def

#ifndef PREFERREDCUSTOMERS_H
#define PREFERREDCUSTOMERS_H

#include <list>
#include <string>
#include <vector>
#include "BankCustomer.h"
using namespace std;

class PreferredCustomers
{
 public:
  PreferredCustomers( int );

  void setCustCategory( int );
  int getCustCategory() const;

  bool addToPreferredCustomersList( BankCustomer );

  void preferredCustomerReport();

 private:
  int custCat;
  vector< int > AccountsTotals;
};

#endif
