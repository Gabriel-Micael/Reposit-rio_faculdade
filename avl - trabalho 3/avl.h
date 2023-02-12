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
    aux *esq;
    aux *dir;
    int bal; // fator de balanceamento (0, -1 ou +1) => alt. direita - alt. esquerda
} NO, *PONT;

int fb(PONT no);
void destruirArvore(PONT * raiz);
void destruirAux(PONT subRaiz);
PONT buscaBinaria_placa(string placa, PONT raiz);
void exibirArvorePosOrdem(PONT raiz);
void exibirArvorePreOrdem(PONT raiz);
void printAVLTree(PONT node, int level);
int altura(PONT p);
int max(int a, int b);
PONT criarNovoNo(Tveiculo *veiculo);
PONT rotacao_simples_a_esquerda(PONT no);
PONT rotacao_simples_a_direita(PONT no);
PONT rotacao_direita_esquerda(PONT no);
PONT rotacao_esquerda_direita(PONT no);
PONT balancear(PONT no);
PONT insere_avl(PONT no, Tveiculo *veiculo);
PONT remove_avl(PONT no, string placa);
void imprimir_veiculo(Tveiculo* veiculo);
void valores_acima(PONT raiz, int valor);
void valores_abaixo(PONT raiz, int valor);
void direcao_eletrica(PONT raiz);
void direcao_hidraulica(PONT raiz);
void cambio_automatico(PONT raiz);
void cambio_manual(PONT raiz);
void cor(PONT raiz, string entrada_cor);
void modelo(PONT raiz, string modelo_entrada);
#endif //AVL_H
