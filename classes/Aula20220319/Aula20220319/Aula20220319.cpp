
#include <iostream>




struct pessoa {
    int idade;
    char nome[40];
};


struct no_pessoa {
    pessoa* dado;
    no_pessoa* proximo;
};


void adicionar_pessoa(no_pessoa*& raiz, pessoa* dado) {
    no_pessoa* novo = new(no_pessoa);
    novo->dado = dado;
    novo->proximo = NULL;
    if (raiz == NULL) {
        raiz = novo;
    }
    else {
        no_pessoa* aux = raiz;
        while (aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = novo;
    }
}

void bubble_pessoa(pessoa* valores[], int tamanho) {
    bool mudou = true;
    while (mudou) {
        mudou = false;
        for (int i = 1; i < tamanho; i++) {
            if (valores[i]->idade < valores[i - 1]->idade) {
                mudou = true;
                pessoa* aux = valores[i - 1];
                valores[i - 1] = valores[i];
                valores[i] = aux;
            }
        }
    }
}

pessoa* criar_pessoa(int idade, const char* nome) {
    pessoa* novo = new(pessoa);
    novo->idade = idade;
    strcpy_s(novo->nome, nome);
    return novo;
}

int main()
{
    pessoa* valores[3];
    valores[0] = criar_pessoa(25, "Ana");
    valores[1] = criar_pessoa(64, "Pedro");
    valores[2] = criar_pessoa(12, "Carlos");
    bubble_pessoa(valores, 3);
    for (int i = 0; i < 3; i++) {
        std::cout << valores[i]->nome << " : " << 
                     valores[i]->idade << "\n";
    }
    for (int i = 0; i < 3; i++) {
        delete(valores[i]);
    }

    no_pessoa* raiz = NULL;

    adicionar_pessoa(raiz, criar_pessoa(25, "Ana"));
    adicionar_pessoa(raiz, criar_pessoa(32, "Bia"));
    adicionar_pessoa(raiz, criar_pessoa(10, "Lucas"));
    no_pessoa* aux = raiz;
    while (aux != NULL) {
        std::cout << aux->dado->nome << "\n";
        aux = aux->proximo;
    }
    // Limpando a lista
    while (raiz != NULL) {
        no_pessoa* aux = raiz;
        raiz = raiz->proximo;
        delete(aux->dado);
        delete(aux);
    }
    
}

