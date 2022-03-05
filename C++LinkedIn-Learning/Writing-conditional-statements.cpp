#include <cstdio>

int main()
{
  int x = 42;
  int y = 7;

  printf("value is %d \n", x < y);

  if (x > y)
  {
    puts("conditional is true");
  }
  else
  {
    puts("conditional is false");
  }
  return 0;
}