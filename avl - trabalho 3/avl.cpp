#include "avl.h"
#include <malloc.h>

PONT criarNovoNo(Tveiculo veiuclo){
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->veiculo = NULL;
    novoNo->bal = 0;
    return novoNo;
}

int max(int a, int b){
    if (a>b)
        return a;
    return b;
}

int altura(PONT p){
    if (!p)
        return -1;
    else return 1 + max(altura(p->esq),altura(p->dir));
}

/* Exibe arvore Em Ordem.         */
void exibirArvoreEmOrdem(PONT raiz){
    if (raiz == NULL)
        return;
    exibirArvoreEmOrdem(raiz->esq);
    cout << raiz->veiculo->modelo;
    cout << raiz->veiculo->marca;
    cout << raiz->veiculo->tipo;
    cout << raiz->veiculo->ano;
    cout << raiz->veiculo->km;
    cout << raiz->veiculo->potencia;
    cout << raiz->veiculo->combustivel;
    cout << raiz->veiculo->cambio;
    cout << raiz->veiculo->direcao;
    cout << raiz->veiculo->cor;
    cout << raiz->veiculo->porta;
    cout << raiz->veiculo->placa;
    cout << raiz->veiculo->valor;
    exibirArvoreEmOrdem(raiz->dir);
}

/* Exibe arvore Pre Ordem.         */
void exibirArvorePreOrdem(PONT raiz){
    if (raiz == NULL)
        return;
    cout << raiz->veiculo->modelo;
    cout << raiz->veiculo->marca;
    cout << raiz->veiculo->tipo;
    cout << raiz->veiculo->ano;
    cout << raiz->veiculo->km;
    cout << raiz->veiculo->potencia;
    cout << raiz->veiculo->combustivel;
    cout << raiz->veiculo->cambio;
    cout << raiz->veiculo->direcao;
    cout << raiz->veiculo->cor;
    cout << raiz->veiculo->porta;
    cout << raiz->veiculo->placa;
    cout << raiz->veiculo->valor;
    exibirArvorePreOrdem(raiz->esq);
    exibirArvorePreOrdem(raiz->dir);
}

/* Exibe arvore Pos Ordem         */
void exibirArvorePosOrdem(PONT raiz){
    if (raiz == NULL)
        return;
    exibirArvorePreOrdem(raiz->esq);
    exibirArvorePreOrdem(raiz->dir);
    cout << raiz->veiculo->modelo;
    cout << raiz->veiculo->marca;
    cout << raiz->veiculo->tipo;
    cout << raiz->veiculo->ano;
    cout << raiz->veiculo->km;
    cout << raiz->veiculo->potencia;
    cout << raiz->veiculo->combustivel;
    cout << raiz->veiculo->cambio;
    cout << raiz->veiculo->direcao;
    cout << raiz->veiculo->cor;
    cout << raiz->veiculo->porta;
    cout << raiz->veiculo->placa;
    cout << raiz->veiculo->valor;
}

PONT rotacaoL(PONT p){
    cout << "Rotacao a esquerda, problema no no: " << p->veiculo << endl;
    PONT u, v;
    u = p->esq;
    if(u->bal == -1) {   // LL
        p->esq = u->dir;
        u->dir = p;
        p->bal = 0;
        u->bal = 0;
        return u;
    }
    else 
        if (u->bal == 1) {  // LR
            v = u->dir;
            u->dir = v->esq;
            v->esq = u;
            p->esq = v->dir;
            v->dir = p;
            if(v->bal == -1)
                p->bal = 1;
            else
                p->bal = 0;
            if(v->bal == 1)
                u->bal = -1;
            else
                u->bal = 0;
            v->bal = 0;
            return v;
	}else{   // caso necessario apenas para a exclusao (u->bal == 0)
            p->esq = u->dir;
            u->dir = p;
            // p->bal = -1;    desnecessario pois o balanceamento de p nao chegou a ser mudado para -2
            u->bal = 1;
            return u;
	}
}

PONT rotacaoR(PONT p){
    cout << "Rotacao a direita, problema no no: " << p->veiculo << endl;
    PONT u, v;
    u = p->dir;
    if(u->bal == 1) {   // RR
        p->dir = u->esq;
        u->esq = p;
        p->bal = 0;
        u->bal = 0;
	return u;
    } 
    else 
        if (u->bal == -1){  // RL
            v = u->esq;
            u->esq = v->dir;
            v->dir = u;
            p->dir = v->esq;
            v->esq = p;
            if(v->bal == 1)
                p->bal = -1;
            else 
                p->bal = 0;
            if(v->bal == -1)
                u->bal = 1;
            else
                u->bal = 0;
            v->bal = 0;
            return v;
	}else{   // caso necessario apenas para a exclusao (u->bal == 0)
            p->dir = u->esq;
            u->esq = p;
            u->bal = -1;
            // p->bal = 1;    desnecessario pois o balanceamento de p nao chegou a ser mudado para 2
            return u;	
	}
}

void inserirAVL(PONT* pp, Tveiculo veiculo, bool* alterou){
    PONT p = *pp;
    if(!p){
        *pp = criarNovoNo(veiculo);
        *alterou = true;
    } else {
        if(&veiculo == p->veiculo)
            *alterou = false;
        else
            if(&veiculo <= p->veiculo
      ) {
                inserirAVL(&(p->esq), veiculo, alterou);
                if(*alterou)
                    switch (p->bal) {
                        case 1 :
                            p->bal = 0;
                            *alterou = false;
                            break;
			case 0 : 
                            p->bal = -1;
                            break;
			case -1:
                            *pp = rotacaoL(p);
                            *alterou = false;
                            break;
			}
		} else {
                    inserirAVL(&(p->dir), veiculo, alterou);
                    if(*alterou)
                        switch (p->bal) {
                            case -1:
                                p->bal = 0;
				*alterou = false;
                                break;
                            case 0 :
                                p->bal = 1;
				break;
                            case 1 :
                                *pp = rotacaoR(p);
				*alterou = false;
				break;
			}
		}
	}
}

PONT buscaBinaria(Tveiculo *veiculo, PONT raiz){
    if (raiz == NULL)
        return NULL;
    if (raiz->veiculo->placa == veiculo->placa)
        return raiz;
    if (raiz->veiculo->placa < veiculo->placa) 
        return buscaBinaria(veiculo,raiz->dir);
    return buscaBinaria(veiculo,raiz->esq);
}  

bool excluirAVL(PONT* raiz, Tveiculo *veiculo, bool* alterou){
    PONT atual = *raiz;
    if (!atual) {
        *alterou = false;
        return false;
    }
    if (atual->veiculo == veiculo){
        PONT substituto, pai_substituto;
        if(!atual->esq || !atual->dir) { // tem zero ou um filho
            if(atual->esq)
                substituto = atual->esq;
            else 
                substituto = atual->dir;
            *raiz = substituto;
            free(atual);
            *alterou = true;
            return true;
        }
        else {   // tem dois filhos
            substituto = maiorAEsquerda(atual,&pai_substituto);
            atual->veiculo
      = substituto->veiculo
      ;
            veiculo = substituto->veiculo
      ; // continua o codigo excluindo o substituto
        }
    }
    bool res;
    if (veiculo > atual->veiculo) {
        res = excluirAVL(&(atual->dir), veiculo, alterou);
        cout << "Excluir recursivo a direita:" << atual->veiculo << " (" << atual->bal << ")" << endl; 
        if (*alterou){
            switch (atual->bal){
                case 1:
                    atual->bal = 0;
                    return true;
                case 0:
                    atual->bal = -1;
                    *alterou = false;
                    return true;
                case -1:
                    *raiz = rotacaoL(atual);
                    if (atual->bal != 0)
                        *alterou = false;
                    return true;
            }
        }
    }else{
        res = excluirAVL(&(atual->esq), veiculo, alterou);
        cout << "Excluir recursivo a esquerda: " << atual->veiculo << "(" << atual->bal << ")" << endl; 
        if (*alterou){
            switch (atual->bal){
                case -1:
                    atual->bal = 0;
                    return true;
                case 0:
                    atual->bal = 1;
                    *alterou = false;
                    return true;
                case 1:
                    *raiz = rotacaoR(atual);
                    if (atual->bal != 0)
                        *alterou = false;
                    return true;
            }
        }
    }
    return res;
}

/* Rotações à direita (LL e LR) */
void rotacaoL2(PONT *p) {
    cout << "Rotacao a esquerda, problema no no: " << (*p)->veiculo << endl;
    PONT u, v;
    u = (*p)->esq;
    if (u->bal == -1) { // LL
        (*p)->esq = u->dir;
        u->dir = *p;
        (*p)->bal = 0;
        *p = u;
    } else { // LR
        v = u->dir;
        u->dir = v->esq;
        v->esq = u;
        (*p)->esq = v->dir;
        v->dir = *p;
        if (v->bal == -1)
            (*p)->bal = 1;
        else 
            (*p)->bal = 0;
        if (v->bal == 1)
            u->bal = -1;
        else 
            u->bal = 0;
        *p = v;
    }
    (*p)->bal = 0; // balanço final da raiz (p) da subarvore
}

/* Rotações à esquerda (RR e RL)    */
void rotacaoR2(PONT *p) {
    cout << "Rotacao a direita, problema no no: " << (*p)->veiculo << endl;
    PONT u, v;
    u = (*p)->dir;
    if (u->bal == 1) { // RR
        (*p)->dir = u->esq;
        u->esq = *p;
        (*p)->bal = 0;
        *p = u;
    } else { // RL
        v = u->esq;
        u->esq = v->dir;
        v->dir = u;
        (*p)->dir = v->esq;
        v->esq = *p;
        if (v->bal == 1)
            (*p)->bal = -1;
        else 
            (*p)->bal = 0;
        if (v->bal == -1)
            u->bal = 1;
        else 
            u->bal = 0;
        *p = v;
    }
    (*p)->bal = 0; // balanço final da raiz (p) da subarvore
}

/* funcao auxiliar na destruicao (liberacao da memoria) de uma arvore */
void destruirAux(PONT subRaiz){
    if (subRaiz){
	destruirAux(subRaiz->esq);
	destruirAux(subRaiz->dir);
	free(subRaiz);
    }
}

/* libera toda memoria de uma arvore e coloca NULL no valor da raiz    */
void destruirArvore(PONT * raiz){
    destruirAux(*raiz);
    *raiz = NULL;
}

void inicializar(PONT * raiz){
    *raiz = NULL;
}

PONT maiorAEsquerda(PONT p, PONT *ant){
    *ant = p;
    p = p->esq;
    while (p->dir) {
        *ant = p;
        p = p->dir;
    }
    return(p);
}