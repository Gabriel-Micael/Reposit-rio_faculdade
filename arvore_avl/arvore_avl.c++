#include <iostream>

using namespace std;

typedef struct no_{
    int valor;
    no* esq;
    no* dir;
}no;

typedef struct {
    no* raiz;
}cabecalho;

no* rotacao_simples_direita(no* pai){
    no* aux = pai -> dir;
    pai -> dir -> esq = pai;
    pai -> dir = NULL;
    return aux;
}


no* rotacao_simples_esquerda(no* pai){
    no* aux = pai -> esq;
    pai -> esq -> dir = pai;
    pai -> esq = NULL;
    return aux;
}

no* rotacao_dupla_direita(no* pai){
    pai -> dir -> esq -> dir = pai -> dir;
    pai -> dir = pai -> dir -> esq;
    return rotacao_simples_direita(pai);
}

no* rotacao_dupla_esquerda(no* pai){
    pai -> esq -> dir -> esq = pai -> esq;
    pai -> esq = pai -> esq -> dir;
    return rotacao_simples_esquerda(pai);
}

int fb(no* raiz, int * alt1, int * alt2){
    
}

no* insere_arvore_avl(no* raiz, int valor){
    if( raiz == NULL){
        no* novo = new no;
        novo -> valor = valor;
        novo -> esq = NULL;
        novo -> dir = NULL;
        raiz = novo;
        return raiz;
    }else{
        if(raiz -> valor > valor){
            if(raiz -> esq != NULL){
                raiz -> esq = insere_arvore_avl(raiz -> esq, valor);
            }else{
                no* novo = new no;
                novo -> valor = valor;
                novo -> esq = NULL;
                novo -> dir = NULL;
                raiz -> esq = novo;
            }
        }else if(raiz -> valor < valor){
            if(raiz -> dir != NULL){
                raiz -> dir = insere_arvore_avl(raiz -> dir, valor);
            }else{
                no* novo = new no;
                novo -> valor = valor;
                novo -> esq = NULL;
                novo -> dir = NULL;
                raiz -> esq = novo;
            }
        }
    }
    int alt1 = 0, alt2 = 0;
    if(fb(raiz, &alt1, &alt2) == 2 || fb(raiz, &alt1, &alt2) == -2){

    }
}


int main(){
    stop:
}
