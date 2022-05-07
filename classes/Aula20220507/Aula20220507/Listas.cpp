#include "Listas.h"
#include <iostream>

NoSimples* createNoSimples(std::string nome)
{
	NoSimples* aux = new NoSimples;
	aux->nome = nome;
	return aux;
}

void addNode(NoSimples*& raiz, std::string nome)
{
	NoSimples *aux = raiz, *anterior = nullptr;
	while (aux != nullptr && aux->nome < nome) {
		anterior = aux;
		aux = aux->proximo;
	}
	if (aux != nullptr && aux->nome == nome)
		return; // Nada a fazer
	if (anterior == nullptr) {
		// Entra na primeira posição
		NoSimples* novo = createNoSimples(nome);
		novo->proximo = raiz;
		raiz = novo;
	}
	else {
		NoSimples* novo = createNoSimples(nome);
		novo->proximo = anterior->proximo;
		anterior->proximo = novo;
	}
}

NoSimples* findNome(NoSimples* raiz, std::string nome)
{
	NoSimples* aux = raiz;
	while (aux != nullptr)
		if (aux->nome == nome)
			return aux;
		else
			aux = aux->proximo;
	return nullptr;	
}

NoSimples* findAnterior(NoSimples* raiz, std::string nome)
{
	NoSimples* aux = raiz, * anterior = nullptr;
	while (aux != nullptr && aux->nome < nome) {
		anterior = aux;
		aux = aux->proximo;
	}
	return anterior;
}

bool removeNome(NoSimples*& raiz, std::string nome)
{
	NoSimples* aux = findNome(raiz, nome);
	if (aux == nullptr) {
		return false;
		// Não encontrou
	}
	if (aux == raiz) {
		raiz = raiz->proximo;
		delete aux;
	}
	else {
		NoSimples* anterior = findAnterior(raiz, nome);
		anterior->proximo = aux->proximo;
		delete aux;
	}
	return true;
}

void listar(NoSimples* raiz)
{
	NoSimples* aux = raiz;
	while (aux != nullptr) {
		std::cout << aux->nome << std::endl;
		aux = aux->proximo;
	}
}

void removerLista(NoSimples*& raiz)
{
	while (raiz != nullptr) {
		NoSimples* aux = raiz;
		raiz = raiz->proximo;
		delete aux;
	}
}

NoDuplo* createNoDuplo(std::string nome)
{
	NoDuplo* aux = new NoDuplo;
	aux->nome = nome;
	return aux;
}

void addNode(NoDuplo*& raiz, std::string nome)
{
	NoDuplo* aux = raiz, * anterior = nullptr;
	while (aux != nullptr && aux->nome < nome) {
		anterior = aux;
		aux = aux->proximo;
	}
	if (aux != nullptr && aux->nome == nome)
		return; // Nada a fazer
	if (anterior == nullptr) {
		// Entra na primeira posição
		NoDuplo* novo = createNoDuplo(nome);
		novo->proximo = raiz;
		if (raiz != nullptr)
			raiz->anterior = novo;
		raiz = novo;
	}
	else {
		NoDuplo* novo = createNoDuplo(nome);
		novo->proximo = anterior->proximo;
		if (novo->proximo != nullptr)
			novo->proximo->anterior = novo;
		anterior->proximo = novo;
		novo->anterior = anterior;
	}
}

NoDuplo* findNome(NoDuplo* raiz, std::string nome)
{
	NoDuplo* aux = raiz;
	while (aux != nullptr)
		if (aux->nome == nome)
			return aux;
		else
			aux = aux->proximo;
	return nullptr;
}

bool removeNome(NoDuplo*& raiz, std::string nome)
{
	NoDuplo* aux = findNome(raiz, nome);
	if (aux == nullptr) {
		return false;
		// Não encontrou
	}
	if (aux == raiz) {
		raiz = raiz->proximo;
		raiz->anterior = nullptr;
		delete aux;
	}
	else {
		if (aux->anterior != nullptr)
			aux->anterior->proximo = aux->proximo;
		if (aux->proximo != nullptr)
			aux->proximo->anterior = aux->anterior;
		delete aux;
	}
	return true;
}

void listar(NoDuplo* raiz)
{
	NoDuplo* aux = raiz;
	while (aux != nullptr) {
		std::cout << aux->nome << std::endl;
		aux = aux->proximo;
	}
}

void removerLista(NoDuplo*& raiz)
{
	while (raiz != nullptr) {
		NoDuplo* aux = raiz;
		raiz = raiz->proximo;
		delete aux;
	}
}

void addNodeCircular(NoDuplo*& raiz, std::string nome)
{
	if (raiz == nullptr) {
		raiz = createNoDuplo(nome);
		raiz->proximo = raiz;
		raiz->anterior = raiz;
		return;
	}
	NoDuplo* aux = raiz;
	while (aux->nome < nome) {
		aux = aux->proximo;
		if (aux == raiz)
			break;
	}
	if (aux->nome == nome)
		return; // Nada a fazer
	NoDuplo* novo = createNoDuplo(nome);
	novo->proximo = aux;
	novo->anterior = aux->anterior;
	novo->anterior->proximo = novo;
	novo->proximo->anterior = novo;
	if (aux->nome < raiz->nome)
		raiz = aux;
}

NoDuplo* findNomeCircular(NoDuplo* raiz, std::string nome)
{
	NoDuplo* aux = raiz;
	if (aux != nullptr) {
		do {
			if (aux->nome == nome)
				return aux;
			aux = aux->proximo;
		} while (aux != raiz);
	}
	return nullptr;
}

bool removeNomeCircular(NoDuplo*& raiz, std::string nome)
{
	NoDuplo* aux = findNomeCircular(raiz, nome);
	if (aux == nullptr) {
		return false;
		// Não encontrou
	}
	if (aux->proximo == aux) {
		// Ocorre apenas quando a raiz é o único elemento
		raiz = nullptr;
		delete aux;
		return true;
	}
	if (aux == raiz)
		raiz = raiz->proximo;
	aux->proximo->anterior = aux->anterior;
	aux->anterior->proximo = aux->proximo;
	delete aux;
	return true;
}

void listarCircular(NoDuplo* raiz)
{
	NoDuplo* aux = raiz;
	if (aux != nullptr) {
		do {
			std::cout << aux->nome << std::endl;
			aux = aux->proximo;
		} while (aux != raiz);
	}
}

void removerListaCircular(NoDuplo*& raiz)
{
	while (raiz != nullptr) {
		NoDuplo* aux = raiz;
		raiz = raiz->proximo;
		// Quando aponta para si mesmo é o único elemento
		if (raiz == aux)
			raiz = nullptr;
		else {
			raiz->anterior = aux->anterior;
			raiz->anterior->proximo = raiz;
		}
		delete aux;
	}
}
