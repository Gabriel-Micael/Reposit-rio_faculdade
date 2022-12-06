#ifdef ARVORE_H
#define ARVORE_H
    typedef struct tNode_{
        int valor;
        tNode_ * esquerda;
        tNode_ * direita;
    }tNode;
    tNode * busca_pre_ordem(tNode * pai, int valor);
    void * imprime_pre_ordem(tNode * pai);
    void * imprime_in_ordem(tNode * pai);
    void * imprime_pos_ordem(tNode * pai);
    tNode * inicia_arvore();
    void encerra_arvore();
    void insere(tNode * pai, int valor);
    tNode * remove(tNode * pai, int valor);
#endif