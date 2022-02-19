#include <stdio.h>
#include <iostream>
#include <string.h>

struct full_name
{
  char name[20];
  char last[20];
};

int main(int argc, char **argv)
{

  int var, *v1, *v2;
  full_name person1;

  // Linguagem C
  scanf("%d", &var);
  v1 = &var;
  (*v1)++;
  printf("test in C: %d \n", var);

  // Linguagem C++
  std::cin >> var;
  std::cout << "test in C++: " << var << "\n";

  std::cout << "Name: ";
  std::cin >> person1.name;
  std::cout << "Last name: ";
  std::cin >> person1.last;
  std::cout << "Welcome " << person1.name << " " << person1.last << "\n";

  return 0;
}