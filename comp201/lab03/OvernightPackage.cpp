// mem-func for overnight package

#include <iostream> 
#include <stdexcept>
#include "OvernightPackage.h"
using namespace std;

OvernightPackage::OvernightPackage( const string &Sname, const string &Rname, 
				    const string &Saddress, 
				    const string &Raddress, 
				    const string &Scity, const string &Rcity,
				    const string &Sstate,const string &Rstate,
				    int SZIP, int RZIP,
				    double packWeight, double costPO, 
				    double feePO ) : Package( Sname, Rname, 
							      Saddress, 
							      Raddress, Scity,
							      Rcity, Sstate, 
							      Rstate, SZIP, 
							      RZIP, packWeight,
							      costPO )
{
  setFeePerOz( feePO );
}

void OvernightPackage::setFeePerOz( double fee )
{
  if( fee > 0 )
    feePerOz = fee;
  else
    throw invalid_argument( "Fee per oz must be > than zero.\n");
}

double OvernightPackage::getFeePerOz() const
{
  return feePerOz;
}

double OvernightPackage::calculateCost() const
{
  return ( costPerOz + feePerOz ) * weightInOz;
}
