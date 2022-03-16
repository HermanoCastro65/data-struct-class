// BuscaTexto.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <chrono>
#include <time.h>
#include <ctime>

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;

long getMilisegundos()
{
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int buscar_forca_bruta(char t[], int sizet, char p[], int sizep)
{
    for (int i = 0; i <= sizet - sizep; i++)
    {
        int j = 0;
        while ((j < sizep) && (t[i + j] == p[j]))
            j++;
        if (j == sizep)
            return i;
    }
    return -1;
}

int buscar_boyer_moore(char t[], int sizet, char p[], int sizep)
{
    // Compara a partir do final
    // Se encontra incompatibilidade, busca o incompativel no restante do texto
    // 1 - Encontrou, alinha com o texto
    // 2 - Não encontrou, salta para a posição após a incompatibilidade
    int i = 0;
    while (i <= sizet - sizep)
    {
        int pos = sizep - 1;
        while ((pos > -1) && (t[i + pos] == p[pos]))
            pos--;
        if (pos == -1) // Encontrou
            return i;
        else
        {
            char c = t[i + pos];
            int posDif = pos;
            // Tenta achar o caractere no trecho anterior
            do
            {
                pos--;
            } while ((pos > -1) && (c != p[pos]));

            if (pos == -1) // Não encontrou, desloca após a diferença
                i += (posDif + 1);
            else // Encontrou, alinha com equivalente
                i += (posDif - pos);
        }
    }
    return -1;
}

int main()
{
    char texto[] = "GCAATGCCTATGTGACCGAT";
    char padrao[] = "CGAT";

    std::cout << "FB: " << buscar_forca_bruta(texto, 20, padrao, 4) << "\n";

    std::cout << "BM: " << buscar_boyer_moore(texto, 20, padrao, 4) << "\n";
}
