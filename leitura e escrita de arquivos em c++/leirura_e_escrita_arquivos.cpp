#include <iostream>
#include <fstream>

using namespace std;

//ESTRUTURA QUE SERVIRÁ DE MODELO PARA AS INFORMAÇÕES DOS VEÍCULOS SEREM GUARDADAS
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

//FUNÇÃO QUE ORDENARÁ O VETOR DE LEITURA DO ARQUIVO EM ORDEM ALFANUMÉRICA DA PLACA
void ordena_por_placa(struct Tveiculo *bd[], int *tam){
    Tveiculo *bd2[*tam];
    //GARANTINDO QUE O VETOR SECUNDÁRIO SEJA NULO
    for(int j = 0; j < *tam; j++){
        bd2[j] = NULL;
    }
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
    //TRANSEFINDO O VETOR ORDENADO PARA O VETOR DE LEITURA PRINCIPAL
    for(int i = 0; i < *tam; i++){
        bd[i]=bd2[i];
    }
}

//FUNÇÃO QUE VAI TENTAR INSERIR UM NOVO VEÍCULO AO BANCO DE DADOS
int insercao_veiculo(struct Tveiculo *p[], struct Tveiculo *novo, int *Tam){
	if(*Tam < 50){
		p[*Tam] = novo;
		*Tam = *Tam + 1;
		return 0;
	}else{
		return -1;
	}
}

//FUNÇÃO QUE VAI TENTAR BUSCAR UM ELEMENTO E, SE ACHAR, PERGUNTAR SE DEVE REMOVER
int busca_e_remocao_de_veiculo(struct Tveiculo *p[],string placa, int *tam){
    int i, opc;
    if(*tam == 0){
        cout << endl << "BANCO DE DADOS VAZIO!" << endl;
    }else{
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
}

//FUNÇÃO QUE VAI TENTAR MOSTRAR OS 10 VEÍCULOS COM PREÇOS MAIS PRÓXIMO DO VALOR INSERIDO
int busca_por_preco(struct Tveiculo *bd[], float preco, int *tam){
    Tveiculo *bd2[*tam];
    //GARANTINDO QUE O VETOR SECUNDÁRIO SEJA NULO
    for(int j = 0; j < *tam; j++){
        bd2[j] = NULL;
    }
    int j = 0;
    bd2[0] = new Tveiculo;
    bd2[0] = bd[0];
    for(int i = 1; i < *tam; i++){
        bd2[i]=new Tveiculo;
        if(bd[i]->valor < bd2[i-1]-> valor){
            for(j = i - 1; bd[i] -> valor < bd2[j] -> valor && j >= 0;j--){         
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
    cout << endl << "OS 10 CARROS MAIS PRÓXIMOS DO VALOR INFORMADO SÃO: " << endl << endl;
    int i;
    for(i = 0; i < *tam && preco > bd2[i]->valor; i++){
    }
    if(i == 0){
        for(j = 0; j < 10; j++){
            cout << j + 1 << "º CARRO MAIS PRÓXIMO DO VALOR: ";
            cout << bd2[j]->modelo << " ";
            cout << bd2[j]->marca << " ";
            cout << bd2[j]->tipo << " ";
            cout << bd2[j]->ano << " ";
            cout << bd2[j]->km << " ";
            cout << bd2[j]->potencia << " ";
            cout << bd2[j]->combustivel << " ";
            cout << bd2[j]->cambio << " ";
            cout << bd2[j]->direcao << " ";
            cout << bd2[j]->cor << " ";
            cout << bd2[j]->porta << " ";
            cout << bd2[j]->placa << " ";
            cout << bd2[j]->valor << endl;
        }
    }else if(i == *tam){
        int k = 0;
        for(j = *tam-1; j > *tam - 11; j--, k++){
            cout << k + 1 << "º CARRO MAIS PRÓXIMO DO VALOR: ";
            cout << bd2[j]->modelo << " ";
            cout << bd2[j]->marca << " ";
            cout << bd2[j]->tipo << " ";
            cout << bd2[j]->ano << " ";
            cout << bd2[j]->km << " ";
            cout << bd2[j]->potencia << " ";
            cout << bd2[j]->combustivel << " ";
            cout << bd2[j]->cambio << " ";
            cout << bd2[j]->direcao << " ";
            cout << bd2[j]->cor << " ";
            cout << bd2[j]->porta << " ";
            cout << bd2[j]->placa << " ";
            cout << bd2[j]->valor << endl;
        }
    }else{
        j = 0;
        cout << j + 1 << "º CARRO MAIS PRÓXIMO DO VALOR: ";
        cout << bd2[i]->modelo << " ";
        cout << bd2[i]->marca << " ";
        cout << bd2[i]->tipo << " ";
        cout << bd2[i]->ano << " ";
        cout << bd2[i]->km << " ";
        cout << bd2[i]->potencia << " ";
        cout << bd2[i]->combustivel << " ";
        cout << bd2[i]->cambio << " ";
        cout << bd2[i]->direcao << " ";
        cout << bd2[i]->cor << " ";
        cout << bd2[i]->porta << " ";
        cout << bd2[i]->placa << " ";
        cout << bd2[i]->valor << endl;
        for(int j = 2, e = i - 1, d = i + 1; j < 10; j++){
            if((bd2[i]->valor-bd2[e]->valor)<(bd2[d]->valor-bd2[i]->valor) && e>=0){
                cout << j << "º CARRO MAIS PRÓXIMO DO VALOR: ";
                cout << bd2[e]->modelo << " ";
                cout << bd2[e]->marca << " ";
                cout << bd2[e]->tipo << " ";
                cout << bd2[e]->ano << " ";
                cout << bd2[e]->km << " ";
                cout << bd2[e]->potencia << " ";
                cout << bd2[e]->combustivel << " ";
                cout << bd2[e]->cambio << " ";
                cout << bd2[e]->direcao << " ";
                cout << bd2[e]->cor << " ";
                cout << bd2[e]->porta << " ";
                cout << bd2[e]->placa << " ";
                cout << bd2[e]->valor << endl;
                e--;
            }else if(d < *tam){
                cout << j + 1 << "º CARRO MAIS PRÓXIMO DO VALOR: ";
                cout << bd2[d]->modelo << " ";
                cout << bd2[d]->marca << " ";
                cout << bd2[d]->tipo << " ";
                cout << bd2[d]->ano << " ";
                cout << bd2[d]->km << " ";
                cout << bd2[d]->potencia << " ";
                cout << bd2[d]->combustivel << " ";
                cout << bd2[d]->cambio << " ";
                cout << bd2[d]->direcao << " ";
                cout << bd2[d]->cor << " ";
                cout << bd2[d]->porta << " ";
                cout << bd2[d]->placa << " ";
                cout << bd2[d]->valor << endl;
                d++;
            }
        }
    }
}

//FUNÇÃO PARA IMPRIMIR O VETOR DE STRUCT NA TELA
void mostrar(struct Tveiculo *bd[],int *tam){
    for(int i = 0; i < *tam; i++){
        cout << bd[i]->modelo << " ";
        cout << bd[i]->marca << " ";
        cout << bd[i]->tipo << " ";
        cout << bd[i]->ano << " ";
        cout << bd[i]->km << " ";
        cout << bd[i]->potencia << " ";
        cout << bd[i]->combustivel << " ";
        cout << bd[i]->cambio << " ";
        cout << bd[i]->direcao << " ";
        cout << bd[i]->cor << " ";
        cout << bd[i]->porta << " ";
        cout << bd[i]->placa << " ";
        cout << bd[i]->valor << endl;
    }
}

//FUNÇÃO PARA SALVAR OS DADOS NO ARQUIVO TEXTO
void salvar(struct Tveiculo *p[], int *tam){
    int opc;
    do{
        cout << "[1] - SALVAR" << endl << "[2] - NÃO SALVAR" << endl << endl << "ESCOLHA UMA OPÇÃO: ";
        cin >> opc;
        if(opc == 1){
            ofstream myfile ("BD_veiculos.txt");
            if(myfile.is_open()){
                for(int i = 0; i < *tam; i++){
                    if(i < *tam - 1){
                        myfile << p[i]->modelo << " " << p[i]->marca << " " << p[i]->tipo << " " << p[i]->ano << " " << p[i]->km 
                        << " " << p[i]->potencia << " " << p[i]->combustivel << " " << p[i]->cambio<< " " << p[i]->direcao<< " " 
                        << p[i]->cor<< " " << p[i]->porta<< " " << p[i]->placa<< " " << p[i]->valor << "\n";
                    }else{
                        myfile << p[i]->modelo << " " << p[i]->marca << " " << p[i]->tipo << " " << p[i]->ano << " " << p[i]->km 
                        << " " << p[i]->potencia << " " << p[i]->combustivel << " " << p[i]->cambio<< " " << p[i]->direcao<< " " 
                        << p[i]->cor<< " " << p[i]->porta<< " " << p[i]->placa<< " " << p[i]->valor;
                    }
                }
                myfile.close();
            }else{
                cout <<"Unable to open file\n" << endl;
            }
        }else if(opc == 2){
        }else{
            cout << endl << "DIGITE APENAS '1' OU '2'!" << endl;
        }
    }while(opc != 1 && opc != 2);
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
        //GARANTINDO QUE O RESTANTE DO VETOR DE LEITURA SEJA NULO
        if(i<49){
            for(int j = i + 1; j < 50; j++){
                bd[j] = NULL;
            }
        }
        //VARIAVEL USADA PARA ESCOLHA DE OPÇÃO NO MENU
        int opc;
        //VARIAVEL USADA PARA RECEBER O PREÇO DO VEÍCULO
        float preco;
        //VARIAVEL USADA PARA RECEBER A PLACA DO VEÍCULO
        string placa;
        Tveiculo *inserir, *bd2[50];
        //GARANTINDO QUE O VETOR SECUNDÁRIO SEJA NULO
        for(int j = 0; j < 50; j++){
            bd2[j] = NULL;
        }
        //LEITURA DE ARQUIVO SIMULANDO ENTRADA DE USUÁRIO
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
            myfile >> inserir->valor;
            myfile.close();
        }else{
            cout << "Unable to open file\n";
        }
        do{
            //MENU
            cout << "--------------------------------------------------------------" << endl << "[0] - SAIR" << endl << "[1] - BUSCA POR PLACA" << endl 
            << "[2] - BUSCA POR PREÇO" << endl << "[3] - ORDENAR PELA PLACA" << endl << "[4] - MOSTRAR" << endl << "[5] - INSERIR" <<  endl
            << "--------------------------------------------------------------" << endl << "ESCOLHA UMA OPÇÃO: ";
            cin >> opc;
            cout << endl;
            switch(opc){
                case 0:
                    salvar(bd, &i);
                    break;
                case 1:
                    cout <<  "DIGITE A PLACA DO VEÍCULO A PROCURAR, NO MODELO AAA0000: ";
		            cin >> placa;
                    if(busca_e_remocao_de_veiculo(bd, placa, &i) == -1){
                        cout << "ELEMENTO NÃO ENCONTRADO!" << endl;
                    }
                    break;
                case 2:
                    cout << "DIGITE O PREÇO DO VEÍCULO A PROCURAR: ";
		            cin >> preco;
                    busca_por_preco(bd, preco, &i);
                    break;
                case 3:
                    ordena_por_placa(bd, &i);
                    cout <<  "ORDENADO! " << endl;
                    break;
                case 4:
                    mostrar(bd, &i);
                    break;
                case 5:
                    cout << "ENTRADA DE USUÁRIO SIMULADA" << endl;
                    insercao_veiculo(bd, inserir, &i);
                    break;
                default:
                    cout << "VALOR INVÁLIDO, DIGITE APENAS '0', '1', '2', '3', '4' OU '5'!" <<  endl;
                    break;
            }
        }while(opc != 0);
    for(int j = 0; j < i;j++){
        delete (bd[j]);
        delete (bd2[j]);
    }
    }else{
        cout << "Unable to open file\n";    
	}
}
