// Aula20220507.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "Listas.h"

void testeCircular() {
    NoDuplo* raiz = nullptr;
    addNodeCircular(raiz, "Ana");
    addNodeCircular(raiz, "Luiz");
    addNodeCircular(raiz, "Carlos");
    addNodeCircular(raiz, "Beatriz");
    addNodeCircular(raiz, "Paulo");
    std::cout << "Primeira Rodada...." << std::endl;
    listarCircular(raiz);
    removeNomeCircular(raiz, "Carlos");
    std::cout << "Segunda Rodada...." << std::endl;
    listarCircular(raiz);
    removerListaCircular(raiz);
    std::cout << "Fim...." << std::endl;
}

void testeDuplo() {
    NoDuplo* raiz = nullptr;
    addNode(raiz, "Ana");
    addNode(raiz, "Luiz");
    addNode(raiz, "Carlos");
    addNode(raiz, "Beatriz");
    addNode(raiz, "Paulo");
    std::cout << "Primeira Rodada...." << std::endl;
    listar(raiz);
    removeNome(raiz, "Carlos");
    std::cout << "Segunda Rodada...." << std::endl;
    listar(raiz);
    removerLista(raiz);
    std::cout << "Fim...." << std::endl;
}

void testeSimples() {
    NoSimples* raiz = nullptr;
    addNode(raiz, "Ana");
    addNode(raiz, "Luiz");
    addNode(raiz, "Carlos");
    addNode(raiz, "Beatriz");
    addNode(raiz, "Paulo");
    std::cout << "Primeira Rodada...." << std::endl;
    listar(raiz);
    removeNome(raiz, "Carlos");
    std::cout << "Segunda Rodada...." << std::endl;
    listar(raiz);
    removerLista(raiz);
    std::cout << "Fim...." << std::endl;
}

int main()
{
    testeSimples();
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
