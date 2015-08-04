// class def for two day package

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include <string>
#include "Package.h"
using namespace std;

class TwoDayPackage : public Package
{
 public: 
  TwoDayPackage( const string &, const string &, const string &,
		 const string &, const string &, const string &,
		 const string &, const string &, int = 0, int = 0,
		 double = 0.0, double = 0.0, double = 0.0 );

  void setFlatFee( double );
  double getFlatFee() const;

  virtual double calculateCost() const;

 private:
  double flatFee;
};

#endif
