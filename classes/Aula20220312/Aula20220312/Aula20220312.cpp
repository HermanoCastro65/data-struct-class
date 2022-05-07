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

void bubble_pessoa(pessoa valores[], int tamanho)
{
    bool mudou = true;
    while (mudou)
    {
        mudou = false;
        for (int i = 1; i < tamanho; i++)
        {
            if (valores[i].idade < valores[i - 1].idade)
            {
                mudou = true;
                pessoa aux = valores[i - 1];
                valores[i - 1] = valores[i];
                valores[i] = aux;
            }
        }
    }
}

int **muliplica(int **m1, int m, int k1, int **m2, int k2, int n)
{
    return NULL;
}

using namespace std;
int main()
{
    pessoa vp1[3];
    vp1[0].idade = 25;
    strcpy(vp1[0].nome, "Ana");
    vp1[1].idade = 64;
    strcpy(vp1[1].nome, "Pedro");
    vp1[2].idade = 12;
    strcpy(vp1[2].nome, "Carlos");
    bubble_pessoa(vp1, 3);
    for (int i = 0; i < 3; i++)
    {
        cout << vp1[i].nome << " : " << vp1[i].idade << "\n";
    }

    int m1[2][3] = {{2, 5, 7},
                    {2, 1, 4}};

    int m2[3][4] = {{1, 2, 3, 4},
                    {4, 3, 2, 1},
                    {1, 2, 3, 4}};

    int resultado[2][4];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int acum = 0;
            for (int k = 0; k < 3; k++)
                acum += m1[i][k] * m2[k][j];
            resultado[i][j] = acum;
        }
    }

    int v1[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Valor da posição " << i << ":\n";
        cin >> v1[i];
    }

    int max, min;
    max = min = v1[0]; // Quais valores?
    for (int i = 1; i < 5; i++)
    {
        if (v1[i] < min)
            min = v1[i];
        if (v1[i] > max)
            max = v1[i];
    }
    cout << "Maior: " << max << "  Menor: " << min << "\n";

    int pmax, pmin;
    pmax = pmin = 0; // Onde estão os valores?
    for (int i = 1; i < 5; i++)
    {
        if (v1[i] < v1[pmin])
            pmin = i;
        if (v1[i] > v1[pmax])
            pmax = i;
    }
    cout << "Maior: " << v1[pmax] << "  Menor: " << v1[pmin] << "\n";

    bubble(v1, 5);
    for (int i = 0; i < 5; i++)
        cout << i << " : " << v1[i] << "\n";
}
