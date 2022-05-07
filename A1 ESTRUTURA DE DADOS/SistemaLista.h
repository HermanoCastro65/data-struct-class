#ifndef SISTEMA_LISTA
#define SISTEMA_LISTA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro
{
  char titulo[25];
  char autor[25];
  int ano;
  char editora[25];
} Livro;

typedef struct No
{
  struct Livro dados;
  struct No *proximo;
} No;

typedef struct Lista
{
  No *inicio;
  No *fim;
  int tamanho;
} Lista;

No *criaNo(Livro livro)
{
  No *no;
  no = (No *)malloc(sizeof(No));
  no->dados = livro;
  no->proximo = NULL;
  return no;
}

Lista *criaLista()
{
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->tamanho = 0;
  return lista;
}

void incluir(Lista *lista, struct Livro livro)
{
  No *novo = criaNo(livro);
  if (lista->inicio == NULL)
  {
    novo->proximo = NULL;
    lista->inicio = novo;
    lista->fim = novo;
  }
  else
  {
    novo->proximo = lista->inicio;
    lista->inicio = novo;
  }
  lista->tamanho++;
}

void excluir(Lista *lista, char titulo[25])
{
  No *inicio = lista->inicio;
  No *noAExcluir = NULL;

  if (inicio != NULL && strcmp(lista->inicio->dados.titulo, titulo) == 0)
  {
    noAExcluir = lista->inicio;
    lista->inicio = noAExcluir->proximo;
    if (lista->inicio == NULL)
      lista->fim = NULL;
  }
  else
  {
    while (inicio != NULL && inicio->proximo != NULL && strcmp(inicio->proximo->dados.titulo, titulo) != 0)
    {
      inicio = inicio->proximo;
    }
    if (inicio != NULL && inicio->proximo != NULL)
    {
      noAExcluir = inicio->proximo;
      inicio->proximo = noAExcluir->proximo;
      if (inicio->proximo == NULL)
        lista->fim = inicio;
    }
  }
  if (noAExcluir)
  {
    free(noAExcluir);
    lista->tamanho--;
  }
}

void listar(Lista *lista)
{
  No *inicio = lista->inicio;
  printf("Número de Registros: %d\n", lista->tamanho);
  while (inicio != NULL)
  {
    printf("\n\nTitulo: %s \nAutor: %s \nAno: %d \nEditora: %s ", inicio->dados.titulo, inicio->dados.autor, inicio->dados.ano, inicio->dados.editora);
    inicio = inicio->proximo;
  }
  printf("\n\n");
}

#endif
