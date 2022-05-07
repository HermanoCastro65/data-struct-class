#pragma once

#include <string>

struct NoSimples {
	NoSimples* proximo = nullptr;
	std::string nome;
};

struct NoDuplo {
	NoDuplo* proximo = nullptr;
	NoDuplo* anterior = nullptr;
	std::string nome;
};

// Uso de modelo com inclusão ordenada...
// Busca simplificada
// Uso de vetor permitiria busca binária

NoSimples* createNoSimples(std::string nome);
void addNode(NoSimples*& raiz, std::string nome);
NoSimples* findNome(NoSimples* raiz, std::string nome);
NoSimples* findAnterior(NoSimples* raiz, std::string nome);
bool removeNome(NoSimples*& raiz, std::string nome);
void listar(NoSimples* raiz);
void removerLista(NoSimples*& raiz);

NoDuplo* createNoDuplo(std::string nome);
void addNode(NoDuplo*& raiz, std::string nome);
NoDuplo* findNome(NoDuplo* raiz, std::string nome);
bool removeNome(NoDuplo*& raiz, std::string nome);
void listar(NoDuplo* raiz);
void removerLista(NoDuplo*& raiz);

void addNodeCircular(NoDuplo*& raiz, std::string nome);
NoDuplo* findNomeCircular(NoDuplo* raiz, std::string nome);
bool removeNomeCircular(NoDuplo*& raiz, std::string nome);
void listarCircular(NoDuplo* raiz);
void removerListaCircular(NoDuplo*& raiz);

