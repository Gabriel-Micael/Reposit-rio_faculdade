#include "binary.h"

no_binary * criarNovoNo_binary(Tveiculo *veiculo){
    no_binary *novo = new no_binary;
    novo -> dir = NULL;
    novo -> esq = NULL;
    novo -> veiculo = veiculo;
    return novo;
}

void printBinaryTree(no_binary *node, int level)
{
    if (node != NULL)
    {
        printBinaryTree(node->dir, level + 1);
        for (int i = 0; i < level; i++)
            cout << "     ";
        cout << node->veiculo->placa << endl;
        printBinaryTree(node->esq, level + 1);
    }
}

no_binary * insert_tree_binary(Tveiculo * veiculo, no_binary * no){
    if(!no){
        return criarNovoNo_binary(veiculo);
    }else{
        if(veiculo->placa < no->veiculo->placa){
            no -> esq =  insert_tree_binary(veiculo, no -> esq);
        }
        else if(veiculo->placa > no->veiculo->placa){
            no -> dir =  insert_tree_binary(veiculo, no -> dir);
        }else{
            cout << endl << "ELEMENTO COM PLACA " << veiculo->placa << "JÁ EXISTE!" << endl;
        }
    }
    return no;
}

void destruirArvoreBinary(no_binary * no){
    if(!no){
        return;
    }
    destruirArvoreBinary(no->esq);
    destruirArvoreBinary(no->dir);
    delete(no);
}

no_binary * remove_binary(no_binary *no, string placa){
    if(!no){
        return NULL;
    }else{
        if(no -> veiculo -> placa == placa){
            if(no -> esq == NULL && no -> dir == NULL){
                delete(no);
                return NULL;
            }
            else{
                if(no -> esq != NULL && no -> dir != NULL){
                    no_binary *percorre = no -> esq, *aux = new no_binary;
                    while(percorre -> dir != NULL){
                        percorre = percorre -> dir;
                    }
                    aux -> veiculo = no -> veiculo;
                    no -> veiculo = percorre -> veiculo;
                    percorre -> veiculo = aux -> veiculo;
                    no -> esq = remove_binary(no -> esq, placa);
                    return no;
                }
                else{
                    no_binary *percorre;
                    if(no -> esq != NULL){
                        percorre = no -> esq;
                    }
                    else{
                        percorre = no -> dir;
                    }
                    delete(no);
                    return percorre;
                }
            }
        }
        else{
            if(placa < no -> veiculo -> placa)
                no -> esq = remove_binary(no -> esq, placa);
            else
                no -> dir = remove_binary(no -> dir, placa);
        }
        return no;
    }
}
