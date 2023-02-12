#include "avl.h"

/**
 * @param veiculo endereço de uma estrutura Tveiculo
 * @return endereço do novo no criado e inserido com os
 * dados do veículo informado
*/
PONT criarNovoNo(Tveiculo *veiculo){
    PONT novoNo = (PONT)new NO;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->veiculo = veiculo;
    novoNo->bal = 0;
    return novoNo;
}

/**
 * @param a valor inteiro
 * @param b valor inteiro
 * @return maior dos valores a e b
*/
int max(int a, int b){
    return (a > b)? a: b;
}

/**
 * @param p endereço de uma estrutura NO
 * @return altura da estrutura p informada
*/
int altura(PONT p){
    if (!p){
        return -1;
    }
    return 1 + max(altura(p->esq),altura(p->dir));
}
/**
 * @param no endereço de uma estrutura NO
 * @return fator de balanciamento da estrutura no informada
*/
int fb(PONT no){
    if(no){
        return (altura(no->esq) - altura(no->dir));
    }
    return 0;
}

/**
 * @param no endereço de uma estrutura NO
 * @return no reajustado com rotação simpres a esquerda
*/
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

/**
 * @param no endereço de uma estrutura NO
 * @return no reajustado com rotação simpres a direita
*/
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

/**
 * @param no endereço de uma estrutura NO
 * @return no reajustado com rotação dupla (direita-esquerda)
*/
PONT rotacao_direita_esquerda(PONT no){
    no -> dir = rotacao_simples_a_direita(no->dir);
    return rotacao_simples_a_esquerda(no);
}

/**
 * @param no endereço de uma estrutura NO
 * @return no reajustado com rotação dupla (esquerda-direita)
*/
PONT rotacao_esquerda_direita(PONT no){
    no -> esq = rotacao_simples_a_esquerda(no->esq);
    return rotacao_simples_a_direita(no);
}

/**
 * @param no endereço de uma estrutura NO
 * @param veiculo endereço de uma estrutura Tveiculo
 * @return no raiz balanceado com o veiculo inserido
*/
PONT insere_avl(PONT no, Tveiculo *veiculo){
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
    no = balancear(no);
    return no;
}

/**
 * @param no endereço de uma estrutura NO
 * @param placa cadeia de caracteres com a placa do veículo a remover
 * @return NULL caso não encontre
 * @return no raiz balanceado com a remoção realizado caso tenha encontre
*/
PONT remove_avl(PONT no, string placa){
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
                    no -> esq = remove_avl(no -> esq, placa);
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
                no -> esq = remove_avl(no -> esq, placa);
            else
                no -> dir = remove_avl(no -> dir, placa);
        }
    }
    no -> bal = max(altura(no -> esq), altura(no -> dir)) + 1;
    no = balancear(no);
    return no;
}

/**
 * Função para balancear um nó de uma árvore
 * @param no endereço de uma estrutura NO
 * @return o endereço de um no balanceado
*/
PONT balancear(PONT no){
    int fatorbalanciamento = fb(no);
    if(fatorbalanciamento < -1 && fb(no -> dir) <= 0){
        no = rotacao_simples_a_esquerda(no);
    }else if(fatorbalanciamento > 1 && fb(no -> esq) >= 0){
        no = rotacao_simples_a_direita(no);
    }else if(fatorbalanciamento > 1 && fb(no -> esq) < 0){
        no = rotacao_esquerda_direita(no);
    }else if(fatorbalanciamento < -1 && fb(no -> dir) > 0){
        no = rotacao_direita_esquerda(no);
    }return no;
}
/**
 * Função para imprimir um árvore de modo organizado
 * @param node endereço de uma estrutura NO
 * @param level profundidade do nó
*/
void printAVLTree(PONT node, int level)
{
    if (node != NULL)
    {
        printAVLTree(node->dir, level + 1);
        for (int i = 0; i < level; i++)
            cout << "     ";
        cout << node->veiculo->placa << "(" << node -> bal + 1 << ")" << endl;
        printAVLTree(node->esq, level + 1);
    }
}

/* Exibe arvore Pre Ordem.         */
/**
 * @param raiz endereço de uma estrutura NO
 * */
void exibirArvorePreOrdem(PONT raiz){
    if (raiz == NULL){
        return;
    }
    cout << raiz->veiculo->placa << " ";
    exibirArvorePreOrdem(raiz->esq);
    exibirArvorePreOrdem(raiz->dir);
}

/* Exibe arvore Pos Ordem         */
/**
 * @param raiz endereço de uma estrutura NO
*/
void exibirArvorePosOrdem(PONT raiz){
    if (raiz == NULL)
        return;
    exibirArvorePreOrdem(raiz->esq);
    exibirArvorePreOrdem(raiz->dir);
    cout << raiz->veiculo->placa << " ";
}
/**
 * Função para busca de um nó
 * @param veiculo endereço de uma estrutura Tveículo
 * @param raiz endereço de um estrutura NO
 * @return NULL se não encontrar e o nó caso contrário
*/
PONT buscaBinaria_placa(string placa, PONT raiz){
    if (raiz == NULL)
        return NULL;
    if (raiz->veiculo->placa == placa)
        return raiz;
    if (raiz->veiculo->placa < placa) 
        return buscaBinaria_placa(placa,raiz->dir);
    return buscaBinaria_placa(placa,raiz->esq); 
}  

/* funcao auxiliar na destruicao (liberacao da memoria) de uma arvore */
/**
 * @param subRaiz endereço de uma estrutura NO
*/
void destruirAux(PONT subRaiz){
    if (subRaiz){
	destruirAux(subRaiz->esq);
	destruirAux(subRaiz->dir);
	delete(subRaiz);
    }
}

/* libera toda memoria de uma arvore e coloca NULL no valor da raiz    */
/**
 * @param raiz endereço de uma estrutura NO
*/
void destruirArvore(PONT * raiz){
    destruirAux(*raiz);
    *raiz = NULL;
}
/**
 * @param veiculo endereço de uma estrutura Tveiculo
*/
void imprimir_veiculo(Tveiculo* veiculo){
    if(veiculo){
        cout << veiculo->modelo << " ";
        cout << veiculo->marca << " ";
        cout << veiculo->tipo << " ";
        cout << veiculo->ano << " ";
        cout << veiculo->km << " ";
        cout << veiculo->potencia << " ";
        cout << veiculo->combustivel << " ";
        cout << veiculo->cambio << " ";
        cout << veiculo->direcao << " ";
        cout << veiculo->cor << " ";
        cout << veiculo->porta << " ";
        cout << veiculo->placa << " ";
        cout << veiculo->valor << endl;
    }
}

/**
 * @param raiz endereço de uma estrutura NO
 * @param valor valor inteiro (preço)
*/
void valores_acima(PONT raiz, int valor){
    if(raiz){
        if(raiz -> esq)valores_acima(raiz -> esq, valor);
        if(raiz -> veiculo -> valor >= valor)imprimir_veiculo(raiz->veiculo);
        if(raiz -> dir)valores_acima(raiz -> dir, valor);
    }
}

/**
 * @param raiz endereço de uma estrutura NO
 * @param valor valor inteiro (preço)
*/
void valores_abaixo(PONT raiz, int valor){
    if(raiz){
        if(raiz -> esq)valores_abaixo(raiz -> esq, valor);
        if(raiz -> veiculo -> valor <= valor)imprimir_veiculo(raiz->veiculo);
        if(raiz -> dir)valores_abaixo(raiz -> dir, valor);
    }
}

/**
 * @param raiz endereço de uma estrutura NO
*/
void direcao_hidraulica(PONT raiz){
    if(raiz){
        if(raiz->esq)direcao_hidraulica(raiz->esq);
        if(raiz -> veiculo -> direcao == "Hidráulica")imprimir_veiculo(raiz -> veiculo);
        if(raiz->dir)direcao_hidraulica(raiz->dir);
    }
}

/**
 * @param raiz endereço de uma estrutura NO
*/
void direcao_eletrica(PONT raiz){
    if(raiz){
        if(raiz->esq)direcao_eletrica(raiz->esq);
        if(raiz -> veiculo -> direcao == "Elétrica")imprimir_veiculo(raiz -> veiculo);
        if(raiz->dir)direcao_eletrica(raiz->dir);
    }
}

/**
 * @param raiz endereço de uma estrutura NO
*/
void cambio_automatico(PONT raiz){
    if(raiz){
        if(raiz->esq)cambio_automatico(raiz->esq);
        if(raiz -> veiculo -> cambio == "Automático")imprimir_veiculo(raiz -> veiculo);
        if(raiz->dir)cambio_automatico(raiz->dir);
    }
}

/**
 * @param raiz endereço de uma estrutura NO
*/
void cambio_manual(PONT raiz){
    if(raiz){
        if(raiz->esq)cambio_manual(raiz->esq);
        if(raiz -> veiculo -> cambio == "Manual")imprimir_veiculo(raiz -> veiculo);
        if(raiz->dir)cambio_manual(raiz->dir);
    }
}

/**
 * @param raiz endereço de uma estrutura NO
 * @param entrada_cor cadeia de caracteres com a cor a buscar
*/
void cor(PONT raiz, string entrada_cor){
    if(raiz){
        if(raiz->esq)cor(raiz->esq, entrada_cor);
        if(raiz -> veiculo -> cor == entrada_cor)imprimir_veiculo(raiz -> veiculo);
        if(raiz->dir)cor(raiz->dir, entrada_cor);
    }
}

/**
 * @param raiz endereço de uma estrutura NO
 * @param modelo_entrada cadeia de caracteres com o modelo a buscar
*/
void modelo(PONT raiz, string modelo_entrada){
    if(raiz){
        if(raiz->esq)modelo(raiz->esq, modelo_entrada);
        if(raiz -> veiculo -> modelo == modelo_entrada)imprimir_veiculo(raiz -> veiculo);
        if(raiz->dir)modelo(raiz->dir, modelo_entrada);
    }
}
