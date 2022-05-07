#include <stdio.h>
#include <stdlib.h>

int sequencial(int n)
{
  int soma = 0;
  for (int i = 0; i <= n; i++)
    soma = soma + i;
  return soma;
}

int recursiva(int n)
{
  if (n == 0)
    return 0;
  else
    return n + recursiva(n - 1);
}

int main()
{
  int param;

  printf("Parametro: ");
  scanf("%d", &param);

  printf("\nSequencial: %d", sequencial(param));
  printf("\nRecursiva: %d \n", recursiva(param));

  return 0;
}