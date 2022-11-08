/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include "lista.h"

using namespace std;

/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
tLista* inicia_lista() {
	tLista* tmp = new (tLista);
	tmp->tam = 0;
	tmp->lista = NULL;

        cout << "-A lista foi iniciada."<<endl;
	return tmp;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 * @param ptlista ponteiro para a lista.
 * @return NULL para atualizar o ponteiro da lista.
 */
tLista * encerra_lista(tLista * ptlista) {
	no * ant = ptlista->lista;
	no * pont = ptlista->lista;
	
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(ptlista);
        cout << "-A lista foi removida."<<endl;
	
        return NULL;
}

/**
 * Busca pelo valor de chave passado dentro da lista encadeada.
 * @param chave a ser buscada.
 * @param ant ponteiro anterior a posicao encontrada.
 * @return verdareiro se o elemento foi encontrado.
 */
no * busca(tLista * ptlista, int valor) {
	no_ *p;
	for(p = ptlista->lista; p != NULL && p->valor != valor;){
		p=p->prox;
	}
	return p;
}

/**
 * Realiza a insercao do elemento no início da lista ligada.
 * @param valor a ser inserido.
 */
void insere_inicio(tLista * ptlista, int valor){
	no* novo;
	novo = new no;
	novo->valor = valor;
	novo->prox = ptlista->lista;
	ptlista->lista = novo;
	ptlista->tam = ptlista->tam + 1;
}

/**
 * Realiza a insercao do elemento no fim da lista ligada.
 * @param valor a ser inserido.
 */
void insere_fim(tLista * ptlista, int valor){
	no* novo, p;
	novo = new no;
	for(no* p = ptlista->lista; p->prox != NULL;){
		p=p->prox;
	}
	p.prox = novo;
	ptlista->tam = ptlista->tam + 1;
}

/**
 * Realiza a remocao do primeiro elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no * remove_inicio(tLista * ptlista){
	if(ptlista->lista == NULL){
		return NULL;
	}else{
		return ptlista->lista;
		ptlista->lista = ptlista->lista->prox;
		ptlista->tam = ptlista->tam - 1;
	}
}

/**
 * Realiza a remocao do último elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no * remove_fim(tLista * ptlista){
	if(ptlista->lista != NULL){
		no* p = ptlista->lista;
		while(p->prox->prox != NULL){
			p = p->prox;
		}
		return p->prox;
		p->prox == NULL;
		ptlista->tam = ptlista->tam - 1;
	}else{
		return NULL;
	}
}

/**
 * Imprime a lista encadeada.
 */
void imprime(tLista * ptlista){
	for(no *p = ptlista->lista; p->prox != NULL;){
		cout << p->valor << " ";
	}
}

