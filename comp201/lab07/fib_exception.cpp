// A program to compare exception-handling versus normal return. 
//Mark A. Sheldon, UMass Lowell, Fall 2011
//Thank you Mark!

#include <iostream>
#include <string>
using namespace std;

int fib(int n, bool throwIt);

int i = 0;

int fibHelp(int n, bool throwIt)
{
  if ((n == 0) || (n == 1)) return 1;

  int result = fib(n - 1, throwIt) + fib(n - 2, throwIt);

  if (throwIt) 
    throw result;
 
  return result;
}

int fib(int n, bool throwIt)
{
  try {
    return fibHelp(n, throwIt);
  }
  catch (int &result) {
    ++i;
    return result;
  }
}

int promptAndReadN()
{
  int n;

  cout << "Enter a value for n (-1 to quit):  " << flush;
  cin >> n;

  return n;
}

void usage(char *progName)
{
  cerr << "Usage:  " << progName << " {throw | nothrow}" << endl;
}

int main(int argc, char *argv[])
{
  int n;
  bool throwIt;

  if (argc != 2) {
    usage(argv[0]);
    return 1;
  }
  throwIt = string(argv[1]) == "throw";

  while ((n = promptAndReadN()) >= 0){
    cout <<  "fib(" << n << ") => " << fib(n, throwIt) << endl;
    cout << "Throw count is: " << i << endl;
    i = 0;
  }
}
