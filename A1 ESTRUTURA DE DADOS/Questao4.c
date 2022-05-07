#include <stdio.h>
#include <stdlib.h>

int a[] = {5, 2, 3, 8, 7, 1, 22, 13, 6, 4, 9};

int valorMax(int vet[11])
{
  int max = vet[0];
  for (int i = 1; i < 11; i++)
  {
    if (max < vet[i])
      max = vet[i];
  }
  return max;
}

double media(int vet[11])
{
  int soma = 0;
  for (int i = 0; i < 11; i++)
  {
    soma = soma + vet[i];
  }
  return (double)soma / 11;
}

int main()
{
  printf("Valor maximo: %d \n", valorMax(a));
  printf("Media: %f \n", media(a));
  return 0;
}