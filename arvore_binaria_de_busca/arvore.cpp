#include "arvore.h"

tNode * busca_pre_ordem(tNode * pai, int valor){
    if(pai != NULL){
        if(pai -> valor == valor){
            return pai;
        }
        if(pai->esquerda != NULL){
            busca_pre_ordem(pai->esquerda);
        }
        if(pai->direita != NULL){
            busca_pre_ordem(pai->direita);
        }
    }else{
        return NULL;
    }
}

void * imprime_pre_ordem(tNode * pai){
    if(pai != NULL){
        cout << pai -> valor << " ";
        if(pai->esquerda != NULL){
            imprime_pre_ordem(pai->esquerda);
        }
        if(pai->direita != NULL){
            imprime_pre_ordem(pai->direita);
        }
    }
}
void * imprime_in_ordem(tNode * pai){
    if(pai != NULL){
        if(pai->esquerda != NULL){
            imprime_in_ordem(pai->esquerda);
        }
        cout << pai -> valor << " ";
        if(pai->direita != NULL){
            imprime_in_ordem(pai->direita);
        }
    }
}

void * imprime_pos_ordem(tNode * pai){
    if(pai != NULL){
        if(pai->esquerda != NULL){
            imprime_pos_ordem(pai->esquerda);
        }
        if(pai->direita != NULL){
            imprime_pos_ordem(pai->direita);
        }
        cout << pai->valor << " ";
    }
}

tNode * inicia_arvore(){
    tNode novo = new tNode;
    return novo;
}

void encerra_arvore(){
    if(pai != NULL){
        if(pai->esquerda != NULL){
            pos_ordem(pai->esquerda);
        }
        if(pai->direita != NULL){
            pos_ordem(pai->direita);
        }
        delete(pai);
    }
}

void insere(tNode * pai, int valor){
    if(pai != NULL){
        if(pai->esquerda != NULL && pai -> valor > valor){
            insere(pai->esquerda, valor);
        }
        if(pai->direita != NULL && pai -> valor < valor){
            insere(pai->direita, valor);
        }
    }
}

tNode * remove(tNode * pai, int valor){

}