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
        float valor;
};

void ordena_funcao(struct Tveiculo *bd[],int *tam){
    Tveiculo *bd2[50];
    int j = 0;
    bd2[0] = new Tveiculo;
    bd2[0] = bd[0];
    for(int i = 1; i < *tam; i++){
        bd2[i]=new Tveiculo;
        if(bd[i]->placa < bd2[i-1]-> placa){
            for(j = i - 1; bd[i] -> placa < bd2[j] -> placa && j >= 0;j--){
                bd2[j+1] = bd2[j];

                if(j==0){
                    j--;
                    break;
                }
            }
            bd2[j + 1] = bd[i];
        }else{
            bd2[i]=bd[i];
        }
    }
}

int insercao_veiculo(struct Tveiculo *p[], struct Tveiculo *novo, int *Tam){
	if(*Tam < 50){
		p[*Tam] = novo;
		*Tam = *Tam + 1;
		return 0;
	}else{
		return -1;
	}
}

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
                p[j] = p[j+1];
				
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
        while (!myfile.eof()) {
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
            myfile >> bd[i]->valor;
            i++;
        }
        myfile.close();
        if(i<49){
            for(int j = i + 1; j < 50; j++){
                bd[j] = NULL;
            }
        }
		cout << "Digite a placa do veículo à procurar no modelo XXX0000: ";
		string placa;
		cin >> placa;
        switch(busca_e_remocao_de_veiculo(&bd[0], placa, &i)){
            case -1: 
                cout << "Elemento não encontrado!" << endl;
                break;
            case 0: 
                cout << "Elemento encontrado, mas não removido!" << endl;
                break;
            case 1: 
                cout << "Elemento encontrado e removido!" << endl;
                break;
            default: 
                cout << "ERROR" << endl;
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
                cout << bd[j]->valor;
				cout << endl;
			}
		Tveiculo *inserir;
		ifstream myfile ("veiculo_novo.txt");
		if(myfile.is_open()){
			inserir=new Tveiculo;
            myfile >> inserir->modelo;
            myfile >> inserir->marca;
            myfile >> inserir->tipo;
            myfile >> inserir->ano;
            myfile >> inserir->km;
            myfile >> inserir->potencia;
            myfile >> inserir->combustivel;
            myfile >> inserir->cambio;
            myfile >> inserir->direcao;
            myfile >> inserir->cor;
            myfile >> inserir->porta;
            myfile >> inserir->placa;
			switch(insercao_veiculo(bd, inserir, &i)){
				case -1:
					cout << endl << "Cheio!" << endl << endl;
					break;
				case 0:
					cout << endl << "Inserido" << endl << endl;
					break;
				default:
					cout << "ERROR" << endl;
					break;
			}
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
                cout << bd[j]->valor;
				cout << endl;
			}
            ordena_funcao(bd, &i);
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
                cout << bd[j]->valor;
				cout << endl;
            }
		}else{
			cout << "Unable to open file\n";
		}
		for(int j = 0; j < i;j++){
            delete (bd[j]);
		}
		delete (inserir);
	}
    else{
        cout << "Unable to open file\n";    
	}
}
