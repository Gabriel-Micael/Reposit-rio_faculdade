#include "avl.h"

typedef struct no_binary_{
    no_binary_ *esq;
    no_binary_ *dir;
    Tveiculo *veiculo;
}no_binary;

#ifndef BINARY_H
#define BINARY_H

no_binary * insert_tree_binary(Tveiculo * veiculo, no_binary * no);
no_binary * criarNovoNo_binary(Tveiculo *veiculo);
void printBinaryTree(no_binary *node, int level);
void destruirArvoreBinary(no_binary * no);
no_binary * remove_binary(no_binary *no, string placa);

#endif
