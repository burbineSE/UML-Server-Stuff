// point test file

#include <iostream> 
#include <iomanip>
#include "Point.h"
using namespace std;

int main()
{
  Point point;
  cout << "Enter point in the form (a, b): " << endl;
  cin >> point;
  cout << "Entered number was: " << endl;
  cout << point << endl;
  return 0;
}
