// test program for package

#include <iostream>
#include <iomanip>
#include <string>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
using namespace std;

static void printPackageCost( string className, const Package &pkg );

int main()
{
  Package package1( "Bob", "Fill", "34 Main St.", "74 Lake Road",
		    "New York", "L.A.", "NY", "CA", 15475, 04452, 
		    15, 2 );

  TwoDayPackage package2( "Tom", "Jill", "8 River Road", "45 Spec Lane",
			  "Smalltown", "Pearson", "FL", "MI", 45621, 23516,
			  15, 2, 16 );

  OvernightPackage package3( "Rick", "Mary", "54 Rocky Lane", "5 Dog St.",
			     "Hilltown", "Passton", "AZ", "MA", 01454, 75412,
			     15, 2, 4 );

  cout << fixed << setprecision( 2 );

  printPackageCost( "Package", package1 );
  printPackageCost( "Two Day Package", package2 );
  printPackageCost( "Overnight Package", package3 );
}

void printPackageCost( string className, const Package &pkg )
{
  const Package *packagePtr = 0;

  cout << "\nSender info: \n"
       << "     Name: " << pkg.getNameSend() << endl
       << "     Address: " << pkg.getAddressSend() << endl
       << "     City: " << pkg.getCitySend() << endl
       << "     State: " << pkg.getStateSend() << endl
       << "     ZIP: " << pkg.getZIPSend() << endl
       << "Recipient info: \n"
       << "    Name: " << pkg.getNameRecip() << endl
       << "    Address: " << pkg.getAddressRecip() << endl
       << "    City: " << pkg.getCityRecip() << endl
       << "    State: " << pkg.getStateRecip() << endl
       << "    ZIP: " << pkg.getZIPRecip() << endl
       << "Package info: \n"
       << "    Weight: " << pkg.getWeight() << endl
       << "    Cost per oz: " << pkg.getCostPerOz() << endl;

  if( className == "Package" )
    packagePtr = &pkg;
  else if( className == "Two Day Package" )
    packagePtr = &pkg;
  else if( className == "Overnight Package" ){
    packagePtr = &pkg;
  }
  cout << "Cost for " << className << ": "
       << packagePtr->calculateCost()
       << endl;
}
