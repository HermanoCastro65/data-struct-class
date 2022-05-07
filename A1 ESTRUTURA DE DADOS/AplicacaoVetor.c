#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Livro
{
  char titulo[25];
  char autor[25];
  int ano;
  char editora[25];
} Livro;
Livro *p;

int num, num_novo, num_old, opcao, realoca = 0;
char op;
void cadastra();
void exibe();
void menu();

int main()
{
  do
  {
    menu();

    printf("\tOpcao: ");
    scanf("%d", &opcao);
    fflush(stdin);

    switch (opcao)
    {
    case 0:
      break;

    case 1:
    {
      do
      {
        cadastra();
        printf("Deseja cadastrar mais (s/n): ");
        op = getchar();
        fflush(stdin);

      } while (toupper(op) != 'N');
      break;
    }

    case 2:
      exibe();
      break;

    case 3:
      excluir();
      break;

    default:
      printf("Opcao invalida.\n\n");
    }
  } while (opcao != 0);

  getchar();

  return 0;
}

void menu()
{
  printf("\t[0] Sair\n\t[1] Cadastrar\n\t[2] Exibe\n\t[3] Excluir\n");
}

void cadastra()
{
  if (realoca == 0)
  {
    printf("Numero de cadastros: ");
    scanf("%d", &num);
    fflush(stdin);

    p = (Livro *)calloc(num, sizeof(Livro));

    int i;
    for (i = 0; i < num; i++)
    {
      printf("Cadastro %d\n", i + 1);
      printf("Informe titulo: ");
      gets(p[i].titulo);
      fflush(stdin);
      printf("Informe Autor: ");
      gets(p[i].autor);
      fflush(stdin);
      printf("Informe ano: ");
      scanf("%d", &p[i].ano);
      fflush(stdin);
      printf("Informe editora: ");
      gets(p[i].editora);
      fflush(stdin);
      printf("\n\n");
    }
    realoca = 1;
  }
  else
  {

    num_old = num;
    num = num + 1;

    p = (Livro *)realloc(p, num);

    int i;

    for (i = num_old; i < num; i++)
    {
      printf("Cadastro %d\n", i + 1);
      printf("Informe titulo: ");
      gets(p[i].titulo);
      fflush(stdin);
      printf("Informe Autor: ");
      gets(p[i].autor);
      fflush(stdin);
      printf("Informe ano: ");
      scanf("%d", &p[i].ano);
      fflush(stdin);
      printf("Informe editora: ");
      gets(p[i].editora);
      fflush(stdin);
      printf("\n\n");
    }
  }
}

void exibe()
{
  int j;
  if (p == NULL)
    printf("\t -- Cadastro vazio. --\n\n");

  else
  {

    for (j = 0; j < num; j++)
    {

      printf("Livro %d\n\n", j + 1);
      printf("Titulo: %s\n", p[j].titulo);
      printf("Autor: %s\n", p[j].autor);
      printf("Ano: %d", p[j].ano);
      printf("Editora: %s\n", p[j].editora);
      puts("\n\n");
    }
  }
}

void excluir()
{
  printf("Qual a posição a excluir?");
  int pos;
  scanf("%d", &pos);
  pos--;

  if (pos >= 0 && pos < num)
  {
    int i;

    for (i = pos; i < num - 1; ++i)
    {
      p[i] = p[i + 1];
    }

    p = realloc(p, --num * sizeof(Livro));
  }
}