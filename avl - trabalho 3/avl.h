#include <iostream>

using namespace std;

#ifndef AVL_H
#define AVL_H

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
    struct aux *esq, *dir;
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

int fb(PONT no);
void inicializar(PONT *raiz);
void destruirArvore(PONT * raiz);
void destruirAux(PONT subRaiz);
PONT buscaBinaria(Tveiculo veiculo, PONT raiz);
void exibirArvorePosOrdem(PONT raiz);
void exibirArvorePreOrdem(PONT raiz);
void exibirArvoreEmOrdem(PONT raiz);
int altura(PONT p);
int max(int a, int b);
PONT criarNovoNo(Tveiculo veiculo);
PONT rotacao_simples_a_esquerda(PONT no);
PONT rotacao_simples_a_direita(PONT no);
PONT rotacao_direita_esquerda(PONT no);
PONT rotacao_esquerda_direita(PONT no);
PONT balancear(PONT no);
PONT insere_avl(PONT no, Tveiculo veiculo);
PONT remove_avl(PONT no, Tveiculo veiculo);

#endif //AVL_H
