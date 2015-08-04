// mem-def for twodaypackage.h

#include <iostream>
#include <stdexcept>
#include "TwoDayPackage.h"
using namespace std;

TwoDayPackage::TwoDayPackage( const string &Sname, const string &Rname,
			      const string &Saddress, const string &Raddress,
			      const string &Scity, const string &Rcity, 
			      const string &Sstate, const string &Rstate, 
			      int SZIP, 
			      int RZIP, double packWeight, double costPO, 
			      double flatF ) : Package( Sname, Rname, Saddress,
							Raddress, Scity, Rcity,
							Sstate, Rstate, SZIP, 
							RZIP, packWeight, 
							costPO )
{
  setFlatFee( flatF );
}

void TwoDayPackage::setFlatFee( double fee )
{
  if( fee > 0 )
    flatFee = fee;
  else
    throw invalid_argument( "Flat fee must be > zero.\n");
}

double TwoDayPackage::getFlatFee() const
{
  return flatFee;
}

double TwoDayPackage::calculateCost() const
{
  return flatFee + ( weightInOz * costPerOz );
}
