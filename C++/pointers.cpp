#include <iostream>

struct pessoa
{
  int idade;
  char nome[40];
};

void bubble(int valores[], int tamanho)
{
  bool mudou = true;
  while (mudou)
  {
    mudou = false;
    for (int i = 1; i < tamanho; i++)
    {
      if (valores[i] < valores[i - 1])
      {
        mudou = true;
        int aux = valores[i - 1];
        valores[i - 1] = valores[i];
        valores[i] = aux;
      }
    }
  }
}

pessoa *criar_pessoa(int idade, const char *nome)
{
  pessoa *novo = new (pessoa);
  novo->idade = idade;
  strcpy(novo->nome, nome);
  return novo;
}

int main()
{
  pessoa *valores[3];
  valores[0] = criar_pessoa(25, "Ana");
  valores[1] = criar_pessoa(64, "Pedro");
  valores[2] = criar_pessoa(12, "Carlos");

  return 0;
}
