#include <iostream>
using namespace std;

int main()
{
  int number = 240; // define an init variable
  int *numPtr;      // define an integer pointer numPtr
  numPtr = &number; // assign the address to numPtr
  cout << "The address of number is: " << numPtr << endl;

  return 0;
}