#include <iostream>





struct noLista {
    int dado;
    noLista* proximo;
};

noLista* inicio = NULL;

void add(int dado) {
    noLista* novo = new noLista;
    novo->dado = dado;
    novo->proximo = inicio;
    inicio = novo;
}

void remove(int dado) {
    noLista* aux = inicio;
    noLista* anterior = NULL;
    while (aux != NULL && aux->dado != dado) {
        anterior = aux;
        aux = aux->proximo;
    }
    if (aux != NULL) {
        if (anterior == NULL)
            inicio = aux->proximo;
        else
            anterior->proximo = aux->proximo;
        delete aux;
    }
}

void listar() {
    noLista* aux = inicio;
    while (aux != NULL) {
        std::cout << aux->dado << std::endl;
        aux = aux->proximo;
    }
}

void limpar() {
    while (inicio != NULL) {
        noLista* aux = inicio;
        inicio = inicio->proximo;
        delete aux;
    }
}

void swap(noLista* no1, noLista* no2) {
    int valor = no1->dado;
    no1->dado = no2->dado;
    no2->dado = valor;
}

// Selection Sort
void ordenar() {
    noLista* aux = inicio;
    while (aux != NULL) {
        noLista* outro = aux->proximo;
        noLista* menor = aux;
        while (outro != NULL) {
            if (outro->dado < menor->dado) 
                menor = outro;
            outro = outro->proximo;
        }
        if (menor != aux)
            swap(menor, aux);
        aux = aux->proximo;
    }
}

int main()
{
    int valor;
    // Incluindo
    do {
        std::cin >> valor;
        add(valor);
    } while (valor != 0);
    
    remove(0);
    ordenar();
    listar();
    limpar();
}

