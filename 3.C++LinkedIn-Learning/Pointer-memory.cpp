#include <iostream>
using namespace std;

int main()
{
  cout << "Size of a boolean: " << sizeof(bool) << endl;
  cout << "Size of a char: " << sizeof(char) << endl;
  cout << "Size of a int: " << sizeof(int) << endl;
  cout << "Size of a float: " << sizeof(float) << endl;
  cout << "Size of a long: " << sizeof(long) << endl;
  cout << "Size of a double: " << sizeof(double) << endl;

  bool *pBool;
  char *pChar;
  int *pInt;
  cout << "Size of boolean ptr: " << sizeof(pBool) << endl;
  cout << "Size of char ptr: " << sizeof(pChar) << endl;
  cout << "Size of int ptr: " << sizeof(pInt) << endl;

  return 0;
}