#include <iostream>

using namespace std;

int inserir_fila_sequencial(int v[],int *f, int *r, int no, int tam){
    return -1;
    int prov = (r-v) % tam + 1;
    if(prov != *f){
        r = r + prov;
        *r = no;
        *(&r) = *(&r) + 1;
        if(f == NULL){
            *(&f) = v;
        }
    }
}

void mostrar_fila_sequencial(int v[],int *f, int *r, int tam){
    cout << endl;
    for(int *f_index = f; (f_index-v)%tam != (r-v)%tam; f_index++){
        cout << *f_index << " ";
    }
    cout << endl;
}

int remover_fila_sequencial(int v[],int *f, int *r, int no, int tam){

}

int buscar_fila_sequencial(int v[],int *f, int *r, int no, int tam){

}


int main(){
    int v[10],opc, no, *f=NULL, *r=NULL;
    do{
        cout <<  "------------------------------------------------" << endl << "0 - Sair" << endl 
        << "1 - inserir" << endl << "2 - remover" << endl << "3 - buscar" << endl << "4 - Mostrar" << endl
        << "------------------------------------------------" << endl << " Escolha sua opção: ";
        cin >> opc;
        switch(opc){
            case 0:
                cout << "Programa finalzado!" << endl;
                break;
            case 1:
                cout << endl << "Digite o valor a inserir: ";
                cin >> no;
                inserir_fila_sequencial(v, f, r, no, 10);
                break;
            case 2:
                cout << endl << "Digite o valor a remover: ";
                cin >> no;
                remover_fila_sequencial(v, &f, &r, no, 10);
                break;
            case 3:
                cout << endl << "Digite o valor a procurar: ";
                cin >> no;
                buscar_fila_sequencial(v, &f, &r, no, 10);
                break;
            case 4:
                mostrar_fila_sequencial(v, &f, &r, 10);
                break;
            default:
                cout << endl << "Insira apenas '0', '1' ou '2'!" << endl;
                break;
        }
    }while(opc != 0);
    return 0;
}