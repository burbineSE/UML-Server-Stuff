// class def for overnightPackage

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include <string>
#include "Package.h"
using namespace std;

class OvernightPackage : public Package
{
 public:
  OvernightPackage( const string &, const string &, const string &,
		    const string &, const string &, const string &,
		    const string &, const string &, int = 0, int = 0,
		    double = 0.0, double = 0.0, double = 0.0 );

  void setFeePerOz( double );
  double getFeePerOz() const;

  virtual double calculateCost() const;

 private:
  double feePerOz;
};

#endif
