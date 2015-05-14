// Pachage class def

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
using namespace std;

class Package
{
 public:
  Package( const string &, const string &, const string &, 
	   const string &, const string &, const string &, 
	   const string &, const string &, int = 0, int = 0, 
	   double = 0.0, double = 0.0 );

  void setNameSend( const string & );
  string getNameSend() const;

  void setNameRecip( const string & );
  string getNameRecip() const;

  void setAddressSend( const string & );
  string getAddressSend() const;

  void setAddressRecip( const string & );
  string getAddressRecip() const;

  void setCitySend( const string & );
  string getCitySend() const;

  void setCityRecip( const string & );
  string getCityRecip() const;

  void setStateSend( const string & );
  string getStateSend() const;

  void setStateRecip( const string & );
  string getStateRecip() const;

  void setZIPSend( int );
  int getZIPSend() const;

  void setZIPRecip( int );
  int getZIPRecip() const;

  void setWeight( double );
  double getWeight() const;

  void setCostPerOz( double );
  double getCostPerOz() const;

  virtual double calculateCost() const;

 protected:
  string nameSend;
  string nameRecip;
  string addressSend;
  string addressRecip;
  string citySend;
  string cityRecip;
  string stateSend;
  string stateRecip;
  int ZIPSend;
  int ZIPRecip;
  double weightInOz;
  double costPerOz;
};

#endif
