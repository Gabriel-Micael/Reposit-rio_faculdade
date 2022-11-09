#include <iostream>

using namespace std;

typedef struct no_{
    int valor;
    no_ * prox;
}no;

no * inicia_pilha(){
    no* tPilha = new no;
    tPilha -> valor = 0;
    tPilha -> prox = NULL;
    return tPilha;
}

void encerra_pilha(no* tPilha){
    no* ant;
    for(no* pont = tPilha -> prox; pont != NULL; ){
        ant = pont;
        pont = pont -> prox;
        delete (ant);
    }
}

void inserir_pilha(no* tPilha, int valor){
    no * novo = new no;
    novo -> valor = valor;
    novo -> prox = tPilha -> prox;
    tPilha -> prox = novo;
}

no* remove_pilha(no* tPilha){
    no* ant = tPilha;
    no* pont = tPilha -> prox;
    ant -> prox = pont -> prox;
    return pont;
}

void imprime(no* tPilha){
    for(no* pont = tPilha -> prox; pont != NULL ; pont = pont -> prox ){
        cout << pont -> valor << " ";
    }
}

int main(){
    no * tPilha = inicia_pilha();
    inserir_pilha(tPilha, 5);
    cout << "Inserindo: ";
    imprime(tPilha);
    inserir_pilha(tPilha, 10);
    cout << endl << "Inserindo: ";
    imprime(tPilha);
    cout << endl << "Removendo: ";
    no* p = remove_pilha(tPilha);
    delete (p);
    imprime(tPilha);
    encerra_pilha(tPilha);
}