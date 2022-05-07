#include "SistemaLista.h"

int main()
{
  int opcao;
  Livro livro;
  Lista *lista = criaLista();

  do
  {
    printf("1 - Incluir Livro\n2 - Excluir Livro\n3 - Listar Livros\n4 - Encerrar Aplicacao\n");
    scanf("%d", &opcao);
    system("clear");

    switch (opcao)
    {
    case 1:
      printf("\nInforme titulo: ");
      scanf("%s", livro.titulo);
      fflush(stdin);
      printf("\nInforme autor: ");
      scanf("%s", livro.autor);
      fflush(stdin);
      printf("\nInforme ano: ");
      scanf("%d", &livro.ano);
      fflush(stdin);
      printf("\nInforme editora: ");
      scanf("%s", livro.editora);
      fflush(stdin);
      incluir(lista, livro);
      system("clear");
      break;
    case 2:
      printf("\nInforme titulo:\n");
      scanf("%s", livro.titulo);
      fflush(stdin);
      excluir(lista, livro.titulo);
      system("clear");
      break;
    case 3:
      listar(lista);
      break;
    case 4:
      printf("Fim da Aplicacao");
    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 4);

  return 0;
}