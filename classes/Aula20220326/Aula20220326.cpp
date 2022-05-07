#include <iostream>






struct NoLista {
    int dado;
    NoLista* proximo = NULL;
};

struct Lista {
    NoLista* inicio = NULL;
    int tamanho = 0;
};

void adicionar(Lista& lista, int dado) {
    NoLista* aux = new(NoLista);
    aux->dado = dado;
    if (lista.inicio == NULL) {
        lista.inicio = aux;
    }
    else {
        NoLista* fim = lista.inicio;
        while (fim->proximo != NULL)
            fim = fim->proximo;
        fim->proximo = aux;
    }
    lista.tamanho++;
}

void adicionar_v(Lista& lista, int quantidade, int dados[]) {
    for (int i = 0; i < quantidade; i++)
    {
        adicionar(lista, dados[i]);
    }
}

void listar(Lista& lista) {
    NoLista* aux = lista.inicio;
    while (aux != NULL) {
        std::cout << aux->dado << std::endl;
        aux = aux->proximo;
    }
}

void remover(Lista& lista, int posicao) {
    if (posicao >= 0 && posicao < lista.tamanho) {
        NoLista* aux = lista.inicio;
        NoLista* anterior = NULL;
        for (int i = 0; i < posicao; i++) {
            anterior = aux;
            aux = aux->proximo;
        }
        if (anterior == NULL) {
            lista.inicio = aux->proximo;
        } else {
            anterior->proximo = aux->proximo;
        }
        delete(aux);
        lista.tamanho--;
    }
}

void remover(Lista& lista) {
    remover(lista, lista.tamanho - 1);
}

void limpar(Lista& lista) {
    while (lista.inicio != NULL)
        remover(lista, 0);
}

void adicionar_ordenando(Lista& lista, int dado) {
    NoLista* aux = new(NoLista);
    aux->dado = dado;
    NoLista* maior = lista.inicio;
    NoLista* anterior = NULL;
    while (maior != NULL && maior->dado < dado) {
        anterior = maior;
        maior = maior->proximo;
    }
    aux->proximo = maior;
    if (anterior != NULL) { anterior->proximo = aux; }
    else { lista.inicio = aux; }
    lista.tamanho++;
}

void adicionar_ordenando_v(Lista& lista, int quantidade, int dados[]) {
    for(int i=0; i<quantidade; i++)
    {
        adicionar_ordenando(lista, dados[i]);
    }
}

NoLista* obter_no(Lista& lista, int posicao) {
    NoLista* aux = NULL;
    if (posicao >= 0 && posicao < lista.tamanho) {
        aux = lista.inicio;
        for (int i = 0; i < posicao; i++) {
            aux = aux->proximo;
        }
    }
    return aux;
}

void trocar(Lista& lista, int pos1, int pos2) {
    NoLista* no1 = obter_no(lista, pos1);
    NoLista* no2 = obter_no(lista, pos2);
    if (no1 != NULL && no2 != NULL) {
        int valor = no1->dado;
        no1->dado = no2->dado;
        no2->dado = valor;
    }
}

void ordenar_bubble(Lista& lista) {
    bool modificado = true;
    while (modificado) {
        modificado = false;
        for (int i = 1; i < lista.tamanho; i++) {
            if (obter_no(lista, i - 1)->dado > obter_no(lista, i)->dado) {
                modificado = true;
                trocar(lista, i - 1, i);
            }
        }
    }
}

int main()
{
    Lista minhaLista;
    int valores[] = { 52, 37, 68, 25, 1, 100, 97, 14, 78, 82 };
    adicionar_v(minhaLista, 10, valores);
    ordenar_bubble(minhaLista);
    listar(minhaLista);
    limpar(minhaLista);
}

