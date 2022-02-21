#include <cstdio>

class Class
{
  int i;

public:
  void setValue(int value) { i = value; }
  int getValue() { return i; }
};

int main()
{
  int i = 47;
  Class obj1;
  Class obj2;
  Class obj3;

  obj1.setValue(i);
  obj2.setValue(i * 2);
  obj3.setValue(i * 3);
  printf("value is %d \n", obj1.getValue());
  printf("value is %d \n", obj2.getValue());
  printf("value is %d \n", obj3.getValue());

  return 0;
}