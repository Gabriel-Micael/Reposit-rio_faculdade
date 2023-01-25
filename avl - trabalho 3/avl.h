#include <iostream>
using namespace std;

typedef struct{
  string modelo;
  string marca;
  string tipo;
  int ano;
  int km;
  float potencia;
  string combustivel;
  string cambio;
  string direcao;
  string cor;
  int porta;
  string placa;
  float valor;
}Tveiculo;

typedef struct aux {
    Tveiculo *veiculo;
    struct aux *esq;
    struct aux *dir;
    int bal; // fator de balanceamento (0, -1 ou +1) => alt. direita - alt. esquerda
} NO, *PONT;

typedef struct no{
  Tveiculo *veiculo;
  no * prox;
}no;

typedef struct cabeca{
  no * prox;
  int tam;
}cabeca;

#ifndef AVL_H
#define AVL_H

void inicializar(PONT * raiz);
void destruirArvore(PONT * raiz);
void destruirAux(PONT subRaiz);
void rotacaoR2(PONT *p);
void rotacaoL2(PONT *p);
bool excluirAVL(PONT* raiz, Tveiculo veiculo, bool* alterou);
PONT buscaBinaria(Tveiculo veiculo, PONT raiz);
void inserirAVL(PONT* pp, Tveiculo veiculo, bool* alterou);
PONT rotacaoR(PONT p);
PONT rotacaoL(PONT p);
void exibirArvorePosOrdem(PONT raiz);
void exibirArvorePreOrdem(PONT raiz);
void exibirArvoreEmOrdem(PONT raiz);
int altura(PONT p);
int max(int a, int b);
PONT criarNovoNo(Tveiculo veiculo);
PONT maiorAEsquerda(PONT p, PONT *ant);
#endif