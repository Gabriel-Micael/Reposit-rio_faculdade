#include <iostream>
#include <fstream>

using namespace std;

struct Tveiculo{
        string modelo;
        string marca;
        string tipo;
        int ano;
        int km;
        float potencia;
        string combustivel;
        string cambio;
        string direcao;
        string cor;
        int porta;
        string placa;
};

int busca_e_remocao_de_veiculo(struct Tveiculo *p[],string placa, int *tam){
    int i, opc;
    for(i = 0;i < *tam && p[i]->placa != placa;i++){
    }
    if(i==*tam){
        return -1;
    }else{
        cout << "Elemento encontrado. Deseja removê-lo? ( 1 - sim, 0 - não) ";
        cin >> opc;
        if(opc == 0){
            return 0;
        }else{
            for(int j = i; j < *tam;j++){
                if(j < *tam - 1){
                    p[j] = p[j+1];
                }else{
                    p[j] = NULL;
                }
            }
            *tam = *tam - 1;
            return 1;
        }
    }
}

int main(){
    Tveiculo *bd[50];
    int i = 0;
    ifstream myfile ("BD_veiculos.txt");
    if (myfile.is_open() ) {
        while ( !myfile.eof() ) {
            bd[i]=new Tveiculo;
            myfile >> bd[i]->modelo;
            myfile >> bd[i]->marca;
            myfile >> bd[i]->tipo;
            myfile >> bd[i]->ano;
            myfile >> bd[i]->km;
            myfile >> bd[i]->potencia;
            myfile >> bd[i]->combustivel;
            myfile >> bd[i]->cambio;
            myfile >> bd[i]->direcao;
            myfile >> bd[i]->cor;
            myfile >> bd[i]->porta;
            myfile >> bd[i]->placa;
            i++;
        }
        i--;
        myfile.close();
        for(int j = 0; j < i; j++){
            cout << bd[j]->modelo << " ";
            cout << bd[j]->marca << " ";
            cout << bd[j]->tipo << " ";
            cout << bd[j]->ano << " ";
            cout << bd[j]->km << " ";
            cout << bd[j]->potencia << " ";
            cout << bd[j]->combustivel << " ";
            cout << bd[j]->cambio << " ";
            cout << bd[j]->direcao << " ";
            cout << bd[j]->cor << " ";
            cout << bd[j]->porta << " ";
            cout << bd[j]->placa << " ";
            cout << endl;
        }
        if(!(i<49)){
            for(int j = i; j < i; j++){
                bd[j] = NULL;
            }
        }
        for(int j = 0; j < i;j++){
            delete (bd[j]);
        }
        switch(busca_e_remocao_de_veiculo(bd, bd[0]->placa, &i)){
            case -1: 
                cout << "Elemento não encontrado!";
                break;
            case 0: 
                cout << "Elemento encontrado, mas não removido!";
                break;
            case 1: 
                cout << "Elemento encontrado e removido!";
                break;
            default: 
                cout << "ERROR";
                break;
        }
        for(int j = 0; j < i; j++){
            cout << bd[j]->modelo << " ";
            cout << bd[j]->marca << " ";
            cout << bd[j]->tipo << " ";
            cout << bd[j]->ano << " ";
            cout << bd[j]->km << " ";
            cout << bd[j]->potencia << " ";
            cout << bd[j]->combustivel << " ";
            cout << bd[j]->cambio << " ";
            cout << bd[j]->direcao << " ";
            cout << bd[j]->cor << " ";
            cout << bd[j]->porta << " ";
            cout << bd[j]->placa << " ";
            cout << endl;
        }
    }
    else
        cout << "Unable to open file\n";    
}