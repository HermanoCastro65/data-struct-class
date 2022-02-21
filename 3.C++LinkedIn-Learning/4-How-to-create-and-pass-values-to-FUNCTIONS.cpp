#include <cstdio>
#include <string>

void func(const std::string &s)
{
  printf("the value is %s \n", s.c_str());
}

int main()
{
  std::string s = "This is a string";
  puts("this is main()");
  func(s);
  return 0;
}