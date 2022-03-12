#include <iostream>

using namespace std;

void bubble(int values[], int size)
{
  bool change = true;
  while (change)
  {
    change = false;
    for (int i = 1; i < size; i++)
    {
      if (values[i] < values[i - 1])
      {
        change = true;
        int aux = values[i - 1];
        values[i - 1] = values[i];
        values[i] = aux;
      }
    }
  }
}

int main()
{
  int v1[5];

  for (int i = 0; i < 5; i++)
  {
    cout << "Position value " << i << endl;
    cin >> v1[i];
  }

  int max, min = v1[0];
  for (int i = 0; i < 5; i++)
  {
    if (v1[i] < min)
      min = v1[i];
    if (v1[i] > max)
      max = v1[i];
  }

  cout << "Maximun: " << max << endl;
  cout << "Minimun: " << min << endl;

  int pmax, pmin;
  pmax = pmin = 0;
  for (int i = 1; i < 5; i++)
  {
    if (v1[i] < v1[pmin])
      pmin = i;
    if (v1[i] > v1[pmax])
      pmax = i;
  }

  cout << "Maximun position: " << pmax << endl;
  cout << "Minimun position: " << pmin << endl;

  bubble(v1, 5);
  for (int i = 0; i < 5; i++)
    cout << i << " : " << v1[i] << endl;

  return 0;
}