
#include <iostream>

#include <chrono>
#include <time.h>
#include <ctime>

using std::chrono::milliseconds;
using std::chrono::duration_cast;
using std::chrono::system_clock;

long getMilisegundos() {
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}


int fatorial(int x) {
    if (x < 2)
        return 1;
    else
        return x * fatorial(x - 1);
}

int fatorial2(int x) {
    int aux = 1;
    while (x > 1) {
        aux *= x;
        x--;
    }
    return aux;
}

int fibo_recursivo(int pos) {
    if (pos == 0 || pos == 1)
        return 1;
    return fibo_recursivo(pos - 1) + fibo_recursivo(pos - 2);
}

int fibo_linear(int pos) {
    int pos_1 = 1, pos_2 = 1, aux = 1, i = 2;
    while (i <= pos) {
        aux = pos_1 + pos_2;
        i++;
        pos_2 = pos_1;
        pos_1 = aux;
    }
    return aux;
}

int main()
{
    int pos = 31;

    long inicio = getMilisegundos();
    std::cout << fibo_linear(pos) << "\n";
    std::cout << "Final linear:: "  << 
                 getMilisegundos() - inicio << "\n";

    inicio = getMilisegundos();
    std::cout << fibo_recursivo(pos) << "\n";
    std::cout << "Final recursivo:: " <<
        getMilisegundos() - inicio << "\n";

}

