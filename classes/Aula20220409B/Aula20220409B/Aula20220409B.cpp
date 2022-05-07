#include <iostream>






const int TAMANHO = 10;

int dados[TAMANHO];
int pos = -1;

void add(int dado) {
    if (pos == TAMANHO - 1)
        return;
    dados[++pos] = dado;
}

void remove(int dado) {
    int i;
    for (i = 0; i <= pos; i++) {
        if (dados[i] == dado)
            break;
    }
    if (i <= pos) {
        while (i < pos) {
            dados[i] = dados[i + 1];
            i++;
        }
        pos--;
    }
}

void listar() {
    for (int i = 0; i <= pos; i++)
        std::cout << dados[i] << std::endl;
}


int main()
{
    std::cout << "Hello World!\n";
}

