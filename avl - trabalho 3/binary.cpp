#include "binary.h"

PONT insert_tree_binary(PONT no, Tveiculo * veiculo){
    if(!no){
        return criarNovoNo(veiculo);
    }else{
        if(veiculo->placa < no->veiculo->placa){
            no -> esq =  insere_avl(no -> esq, veiculo);
        }
        else if(veiculo->placa > no->veiculo->placa){
            no -> dir =  insere_avl(no -> dir, veiculo);
        }else{
            cout << endl << "ELEMENTO COM PLACA " << veiculo->placa << "JÁ EXISTE!" << endl;
        }
    }
    no -> bal = max(altura(no -> esq), altura(no -> dir)) + 1;
    return no;
}

PONT remove_binary(PONT no, string placa){
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
                    PONT percorre = no -> esq, aux = new NO;
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
                    PONT percorre;
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
