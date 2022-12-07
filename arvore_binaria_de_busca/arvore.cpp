#include <iostream>
using namespace std;

typedef struct tNode_{
    int valor;
    tNode_ * esquerda;
    tNode_ * direita;
}tNode;

tNode * busca_pre_ordem(tNode * pai, int valor){
    if(pai != NULL){
        if(pai -> valor == valor){
            return pai;
        }
        if(pai->esquerda != NULL){
            busca_pre_ordem(pai->esquerda, valor);
        }
        if(pai->direita != NULL){
            busca_pre_ordem(pai->direita, valor);
        }
    }else{
        return NULL;
    }
}

void imprime_pre_ordem(tNode * pai){
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
void imprime_in_ordem(tNode * pai){
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

void imprime_pos_ordem(tNode * pai){
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
    tNode *novo = new tNode;
    novo -> esquerda = NULL;
    novo -> direita = NULL;
    return novo;
}

void encerra_arvore(tNode *pai){
    if(pai != NULL){
        if(pai->esquerda != NULL){
            encerra_arvore(pai->esquerda);
        }
        if(pai->direita != NULL){
            encerra_arvore(pai->direita);
        }
        delete(pai);
    }
}

void insere(tNode * pai, int valor){
    if(pai != NULL){
        if(pai -> valor > valor){
            if(pai->esquerda != NULL){
                insere(pai->esquerda, valor);
            }else{
                pai -> esquerda = inicia_arvore();
                pai -> esquerda -> valor = valor;
            }
        }else{
            if(pai->direita != NULL){
                insere(pai->direita, valor);
            }else{
                pai -> direita = inicia_arvore();
                pai -> direita -> valor = valor;
            }
        }
    }else{
        pai = inicia_arvore();
        pai -> valor = valor;
    }
}

tNode * remove(tNode * pai, int valor){

}
