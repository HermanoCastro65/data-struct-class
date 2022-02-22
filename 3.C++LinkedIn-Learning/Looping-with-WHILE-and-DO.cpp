#include <cstdio>
using namespace std;

int main()
{
  int array[] = {1, 2, 3, 4, 5};
  int i = 0;

  do
  {
    printf("element %d is: %d \n", i, array[i]);
    i++;
  } while (i < 5);

  return 0;
}