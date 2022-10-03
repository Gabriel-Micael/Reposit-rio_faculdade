#include <iostream>
#include <stdlib.h>
#include "pilha.h"

using namespace std;

int main(){
    int top = 0 ,n;
    cout << "Digite o tamanho da pilha (fixo): " ;
    cin >> n;
    int v[n], opc;
    int cont = 1;
    for(int *p = v; p < v + n && cont != 0; p++){
        cout << endl << "0 - Parar de inserir\n1 - Continuar inserindo\nEscolha: ";
        cin >> cont;
        switch(cont){
            case 0:
                break;
            case 1:
                cout << "inserindo elemento " << p - (v - 1) << ": ";
                cin >> *p;
                top++;
                break;
            default:
                cout << "Inválido!";
                break;
        }
    }
    do{
        cout << endl << "Faça uma escolha: \n0 - Sair\n1 - Inserir\n2 - Mostrar\n3 - Remover\nEscolha: " ;
        cin >> opc;
        switch(opc){
            case 0:
                break;
            case 1:
                inserir_pilha(v, &top, n);
                break;
            case 2:
                mostrar_pilha(v, &top);
                break;
            case 3:
                remover_pilha(v, &top);
                break;
            default:
                cout << "Opção Inválida!";
                break;
        }
    }while(opc != 0);
}