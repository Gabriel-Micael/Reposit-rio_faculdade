#include "avl.h"

typedef struct no_{
  Tveiculo *veiculo;
  no_ * prox;
}no;

typedef struct cabeca{
  no * prox;
  int tam;
}cabeca;

#ifndef LISTAENC_H
#define LISTAENC_H
void encerra_lista(cabeca *bd);
void make_tree_binary(PONT *treebinary, cabeca *bd);
void make_tree_AVL(PONT *treeAVL, cabeca *bd);
cabeca * inicia_lista();
void salvar(cabeca *bd);
int busca_e_remocao_de_veiculo(cabeca *bd, string placa);
void insercao_veiculo(cabeca *bd, Tveiculo *veiculo);
int mostrar(cabeca *bd);
void read_file(Tveiculo *veiculo, string nome_do_arquivo);
#endif
