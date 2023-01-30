#include "avl.h"

PONT criarNovoNo(Tveiculo veiculo){
    PONT novoNo = new NO;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->veiculo = &veiculo;
    novoNo->bal = 0;
    return novoNo;
}

int max(int a, int b){
    return (a>b)? a: b;
}

int altura(PONT p){
    if (!p)
        return -1;
    return 1 + max(altura(p->esq),altura(p->dir));
}

int fb(PONT no){
    if(no){
        return (altura(no->dir) - altura(no->esq));
    }
    return 0;
}

PONT rotacao_simples_a_esquerda(PONT no){
    PONT y, f;
    y = no -> dir;
    f = y -> esq;
    y -> esq = no;
    no -> dir = f;
    no -> bal = max(altura(no -> esq), altura(no -> dir)) + 1;
    y -> bal = max(altura(y -> esq), altura(y -> dir)) + 1;
    return y;
}

PONT rotacao_simples_a_direita(PONT no){
    PONT y, f;
    y = no -> esq;
    f = y -> dir;
    y -> dir = no;
    no -> esq = f;
    no -> bal = max(altura(no -> esq), altura(no -> dir)) + 1;
    y -> bal = max(altura(y -> esq), altura(y -> dir)) + 1;
    return y;
}

PONT rotacao_direita_esquerda(PONT no){
    no -> dir = rotacao_simples_a_direita(no->dir);
    return rotacao_simples_a_esquerda(no);
}

PONT rotacao_esquerda_direita(PONT no){
    no -> esq = rotacao_simples_a_esquerda(no->esq);
    return rotacao_simples_a_direita(no);
}

PONT insere_avl(PONT no, Tveiculo veiculo){
    cout << "chegou até aqui" << endl;
    if(no == NULL){
        cout << "chegou até aqui" << endl;
        return criarNovoNo(veiculo);
        cout << "chegou até aqui" << endl;
    }else{
        if(veiculo.placa < no->veiculo->placa)
            no -> esq =  insere_avl(no -> esq, veiculo);
        else if(veiculo.placa > no->veiculo->placa)
            no -> dir =  insere_avl(no -> dir, veiculo);
        else
            return NULL;
    }
    no -> bal = max(altura(no -> esq), altura(no -> dir)) + 1;
    no = balancear(no);
}

PONT remove_avl(PONT no, string placa){
    if(!no)
        return NULL;
    else
        if(no -> veiculo -> placa == placa)
            if(no -> esq == NULL && no -> dir == NULL)
                return no;
            else
                if(no -> esq != NULL && no -> dir != NULL){
                    PONT percorre = no -> esq;
                    while(percorre -> dir != NULL)
                        percorre = percorre -> dir;
                    no -> veiculo = percorre -> veiculo;
                    no -> esq = remove_avl(no -> esq, placa);
                    return no;
                }
                else{
                    PONT percorre;
                    if(no -> esq != NULL){}
                       // percorre = no -> esq;
                    //else
                        //percorre = no -> esq;
                }
        else{
            if(placa < no -> veiculo -> placa)
                no -> esq = remove_avl(no -> esq, placa);
            else
                no -> esq = remove_avl(no -> esq, placa);
        }
}

PONT balancear(PONT no){
    int fatorbalanciamento = fb(no);
    if(fatorbalanciamento < -1 && fb(no -> dir) <= 0)
        no = rotacao_simples_a_esquerda(no);
    else if(fatorbalanciamento > -1 && fb(no -> esq) >= 0)
        no = rotacao_simples_a_direita(no);
    else if(fatorbalanciamento > -1 && fb(no -> esq) < 0)
        no = rotacao_esquerda_direita(no);
    else if(fatorbalanciamento < -1 && fb(no -> dir) > 0)
        no = rotacao_direita_esquerda(no);
    return no;
}

/* Exibe arvore Em Ordem.         */
void exibirArvoreEmOrdem(PONT raiz){
    if (raiz == NULL)
        return;
    exibirArvoreEmOrdem(raiz->esq);
    /*cout << raiz->veiculo->modelo;
    cout << raiz->veiculo->marca;
    cout << raiz->veiculo->tipo;
    cout << raiz->veiculo->ano;
    cout << raiz->veiculo->km;
    cout << raiz->veiculo->potencia;
    cout << raiz->veiculo->combustivel;
    cout << raiz->veiculo->cambio;
    cout << raiz->veiculo->direcao;
    cout << raiz->veiculo->cor;
    cout << raiz->veiculo->porta;*/
    cout << "(" << raiz->veiculo->placa;
    //cout << raiz->veiculo->valor;
    exibirArvoreEmOrdem(raiz->dir);
    cout << ")";
}

/* Exibe arvore Pre Ordem.         */
void exibirArvorePreOrdem(PONT raiz){
    if (raiz == NULL)
        return;
    /*cout << raiz->veiculo->modelo;
    cout << raiz->veiculo->marca;
    cout << raiz->veiculo->tipo;
    cout << raiz->veiculo->ano;
    cout << raiz->veiculo->km;
    cout << raiz->veiculo->potencia;
    cout << raiz->veiculo->combustivel;
    cout << raiz->veiculo->cambio;
    cout << raiz->veiculo->direcao;
    cout << raiz->veiculo->cor;
    cout << raiz->veiculo->porta;*/
    cout << raiz->veiculo->placa << " ";
    //cout << raiz->veiculo->valor;
    exibirArvorePreOrdem(raiz->esq);
    exibirArvorePreOrdem(raiz->dir);
}

/* Exibe arvore Pos Ordem         */
void exibirArvorePosOrdem(PONT raiz){
    if (raiz == NULL)
        return;
    exibirArvorePreOrdem(raiz->esq);
    exibirArvorePreOrdem(raiz->dir);
    /*cout << raiz->veiculo->modelo;
    cout << raiz->veiculo->marca;
    cout << raiz->veiculo->tipo;
    cout << raiz->veiculo->ano;
    cout << raiz->veiculo->km;
    cout << raiz->veiculo->potencia;
    cout << raiz->veiculo->combustivel;
    cout << raiz->veiculo->cambio;
    cout << raiz->veiculo->direcao;
    cout << raiz->veiculo->cor;
    cout << raiz->veiculo->porta;*/
    cout << "(" << raiz->veiculo->placa;
    //cout << raiz->veiculo->valor;
    cout << ")";
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

/* funcao auxiliar na destruicao (liberacao da memoria) de uma arvore */
void destruirAux(PONT subRaiz){
    if (subRaiz){
	destruirAux(subRaiz->esq);
	destruirAux(subRaiz->dir);
	delete(subRaiz);
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
