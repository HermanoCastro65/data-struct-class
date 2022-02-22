#include <cstdio>

int main()
{
  bool a = true;
  bool b = false;

  if (a || b)
  {
    puts("true");
  }
  else
  {
    puts("false");
  }

  if (a && b)
  {
    puts("true");
  }
  else
  {
    puts("false");
  }

  if (a == b)
  {
    puts("true");
  }
  else
  {
    puts("false");
  }

  if (a != b)
  {
    puts("true");
  }
  else
  {
    puts("false");
  }
  return 0;
}