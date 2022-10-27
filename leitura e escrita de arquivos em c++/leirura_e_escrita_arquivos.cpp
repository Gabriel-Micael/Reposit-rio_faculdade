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
void ordena_por_placa(struct Tveiculo *bd[], struct Tveiculo *bd2[], int *tam){
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
            cout << "ELEMENTO ENCONTRADO. DESEJA REMOVÊ-LO? ( 1 - SIM, 0 - NÃO) ";
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
int busca_por_preco(struct Tveiculo *bd[], float preco){

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
    }else{
        cout <<"Unable to open file\n" << endl;
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
            cout << "--------------------------------------------------------------" << endl << "[0] - SAIR E SALVAR" << endl << "[1] - BUSCA POR PLACA" << endl 
            << "[2] - BUSCA POR PREÇO" << endl << "[3] - ORDENAR PELA PLACA" << endl << "[4] - MOSTRAR" << endl << "[5] - INSERIR" <<  endl
            << "--------------------------------------------------------------" << endl << "ESCOLHA UMA OPÇÃO: ";
            cin >> opc;
            cout << endl;
            switch(opc){
                case 0:
                    salvar(bd, &i);
                    cout << "DADOS SALVOS E PROGRAMA ENCERRADO" << endl << endl;
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
                    busca_por_preco(bd, preco);
                    break;
                case 3:
                    ordena_por_placa(bd, bd2, &i);
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
