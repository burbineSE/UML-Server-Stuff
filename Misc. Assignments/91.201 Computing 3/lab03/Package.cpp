// member-func for package.h

#include <iostream>
#include <stdexcept>
#include "Package.h"
using namespace std;

Package::Package( const string &Sname, const string &Rname,
		  const string &Saddress, const string &Raddress,
		  const string &Scity, const string &Rcity,
		  const string &Sstate, const string &Rstate,
		  int SZIP, int RZIP, double packWeight, 
		  double costPO )
{
  setNameSend( Sname );
  setNameRecip( Rname );
  setAddressSend( Saddress );
  setAddressRecip( Raddress );
  setCitySend( Scity );
  setCityRecip( Rcity );
  setStateSend( Sstate );
  setStateRecip( Rstate );
  setZIPSend( SZIP );
  setZIPRecip( RZIP );
  setWeight( packWeight );
  setCostPerOz( costPO );
}

void Package::setNameSend( const string &nameS )
{
  nameSend = nameS;
}

string Package::getNameSend() const
{
  return nameSend;
}

void Package::setNameRecip( const string &nameR )
{
  nameRecip = nameR;
}

string Package::getNameRecip() const
{
  return nameRecip;
}

void Package::setAddressSend( const string &addressS )
{
  addressSend = addressS;
}

string Package::getAddressSend() const
{
  return addressSend;
}

void Package::setAddressRecip( const string &addressR )
{
  addressRecip = addressR;
}

string Package::getAddressRecip() const
{
  return addressRecip;
}

void Package::setCitySend( const string &cityS )
{
  citySend = cityS;
}

string Package::getCitySend() const
{
  return citySend;
}

void Package::setCityRecip( const string &cityR )
{
  cityRecip = cityR;
}

string Package::getCityRecip() const
{
  return cityRecip;
}

void Package::setStateSend( const string &stateS )
{
  stateSend = stateS;
}

string Package::getStateSend() const
{
  return stateSend;
}

void Package::setStateRecip( const string &stateR )
{
  stateRecip = stateR;
}

string Package::getStateRecip() const
{
  return stateRecip;
}

void Package::setZIPSend( int ZIPS )
{
  ZIPSend = ZIPS;
}

int Package::getZIPSend() const
{
  return ZIPSend;
}

void Package::setZIPRecip( int ZIPR )
{
  ZIPRecip = ZIPR;
}

int Package::getZIPRecip() const
{
  return ZIPRecip;
}

void Package::setWeight( double weight )
{
  if( weight > 0 )
    weightInOz = weight;
  else
    throw invalid_argument( "Weight must be > zero.\n" );
}

double Package::getWeight() const
{
  return weightInOz;
}

void Package::setCostPerOz( double cost )
{
  costPerOz = cost;
}

double Package::getCostPerOz() const
{
  return costPerOz;
}

double Package::calculateCost() const
{
  return weightInOz * costPerOz;
}
