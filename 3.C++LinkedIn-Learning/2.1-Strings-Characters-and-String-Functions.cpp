#include <cstdio>

int main()
{
  const char *cstring = "String"
                        " another string";

  puts(cstring);

  for (int i = 0; cstring[i]; i++)
  {
    printf("%d: %c \n", i, cstring[i]);
  }
  return 0;
}