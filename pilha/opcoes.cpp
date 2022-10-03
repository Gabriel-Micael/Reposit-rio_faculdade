#include <iostream>

using namespace std;

void remover_pilha(int *v, int *top){
    if(v == (v + *top)){
        cout << "Pilha vazia!";
    }else{
        *top = *top - 1;
    }
}
void inserir_pilha(int *v, int *top, int n){
    if(*top >= (v + n) - v){
        cout << "Pilha cheia! ";
    }else{
        cout << "Digite o número a inserir: ";
        cin >> *(v + *top);
        *top = *top + 1;
    }
}
void mostrar_pilha(int *v, int *top){
    for(int *p = v; p < v + *top; p++){
        cout << "  " << *p;
    }
}