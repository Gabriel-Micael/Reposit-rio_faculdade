/*
 * Autores: Gabriel Micael Henrique (2022.1.08.035)
 *          Rodrigo Cabral          (2022.1.08.037)
 *          Henry Lopes             (2022.1.08.038)
 * 
 * Tipo do projeto: vetor sem buracos
 */

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

typedef struct no_{
    Tveiculo * veiculo;
    no_ * prox;
}no;

typedef struct{
    int tam;
    no * prox;
}cabeca;

cabeca * inicia_lista(){
    cabeca * novo = new cabeca;
    novo -> prox = NULL;
    novo -> tam = 0;
    return novo;
}

void encerra_lista(cabeca *bd){
    no* ant;
    for(no* pont = bd->prox; pont != NULL;){
        ant = pont;
        pont = pont -> prox;
        delete(ant);
    }
}

void insere_pilha(cabeca * pilha, Tveiculo *veiculo){
    no* novo = new no;
    novo -> veiculo = veiculo;
    novo -> prox = pilha -> prox;
    pilha -> prox = novo;
}

no* remove_inicio(cabeca *bd){
    no* retorno = bd->prox;
    bd->prox = retorno->prox;
    return retorno;
}

void insere_fila(cabeca *fila, Tveiculo *veiculo){
    no* novo = new no;
    novo -> veiculo = veiculo;
    novo -> prox = NULL;
    no* pont;
    if(fila->prox != NULL){
        for(pont = fila->prox; pont ->prox != NULL; pont = pont -> prox){
        }
        pont -> prox = novo;
    }else{
        fila->prox = novo;
    }
}

//FUNÇÃO PARA IMPRIMIR O VETOR DE STRUCT NA TELA
void mostrar(cabeca *bd){
    for(no * pont  = bd->prox; pont != NULL; pont = pont -> prox){
        cout << pont->veiculo->modelo << " ";
        cout << pont->veiculo->marca << " ";
        cout << pont->veiculo->tipo << " ";
        cout << pont->veiculo->ano << " ";
        cout << pont->veiculo->km << " ";
        cout << pont->veiculo->potencia << " ";
        cout << pont->veiculo->combustivel << " ";
        cout << pont->veiculo->cambio << " ";
        cout << pont->veiculo->direcao << " ";
        cout << pont->veiculo->cor << " ";
        cout << pont->veiculo->porta << " ";
        cout << pont->veiculo->placa << " ";
        cout << pont->veiculo->valor << endl;
    }
}
//FUNÇÃO QUE ORDENARÁ O VETOR DE LEITURA DO ARQUIVO EM ORDEM ALFANUMÉRICA DA PLACA
void ordena_por_placa(cabeca *bd){
    cabeca *bd2 = inicia_lista();
    for(no* percorre = bd2->prox; bd2->tam <= bd->tam; percorre = percorre -> prox){
        percorre = new no;
        percorre->prox = NULL;
        bd2->tam = bd2->tam + 1;
    }
    bd2->prox->veiculo = bd->prox->veiculo; 
    no* pont1 = bd->prox->prox;
    no* pont2;
    for(; pont1 != NULL; pont1 = pont1 -> prox){
        for(pont2 = bd2->prox; pont2->veiculo -> placa < pont1 -> veiculo -> placa && pont2 != NULL; pont2=pont2->prox){
        }
        if(pont2 == bd2->prox){
            pont2 -> prox -> veiculo = pont2->veiculo;
            bd2->prox->veiculo = pont1->veiculo;
        }else{
            pont2->prox->veiculo = pont2 -> veiculo;
            pont2->veiculo = pont1->veiculo;
        }
    }
    mostrar(bd2);
    encerra_lista(bd2);
}
//FUNÇÃO QUE VAI TENTAR INSERIR UM NOVO VEÍCULO AO BANCO DE DADOS
void insercao_veiculo(cabeca *bd, Tveiculo * veiculo){
    no* novo = new no;
    novo -> veiculo = veiculo;
    novo -> prox = NULL;
    if(bd->prox == NULL){
        bd->prox = novo;
    }else{
        no * pont;
        for(pont = bd->prox; pont->prox != NULL; pont=pont->prox){
        }
        pont -> prox = novo;
        bd->tam = bd -> tam + 1;
    }
}
//FUNÇÃO QUE VAI TENTAR BUSCAR UM ELEMENTO E, SE ACHAR, PERGUNTAR SE DEVE REMOVER
int busca_e_remocao_de_veiculo(cabeca *bd, string placa){
    int opc;
    if(bd->prox == NULL){
        cout << endl << "BANCO DE DADOS VAZIO!" << endl;
        return -2;
    }else{
        no * ant = NULL;
        no * pont;
        for(pont = bd->prox;pont != NULL && pont->veiculo->placa != placa; ant = pont, pont = pont -> prox){
        }
        if(pont == NULL){
            return -1;
        }else{
            cout << "ELEMENTO ENCONTRADO. DESEJA REMOVÊ-LO? ( 1 - SIM, 0 - NÃO) ";
            cin >> opc;
            if(opc == 0){
                return 0;
            }else{
                if(ant == NULL){
                    bd->prox = pont->prox;
                }else{
                    ant->prox = pont->prox;
                }
                delete(pont);
                return 1;
            }
        }
    }
}
//FUNÇÃO QUE VAI TENTAR MOSTRAR OS 10 VEÍCULOS COM PREÇOS MAIS PRÓXIMO DO VALOR INSERIDO
/*void busca_por_preco(struct Tveiculo *bd[], float preco, int *tam){
    Tveiculo *bd2[*tam], *bd3[10];
    //ORDENANDO EM ORDEM CRESCENTE DE PREÇO
    int j = 0, i, k = 0;
    bd2[0] = bd[0];
    for(i = 1; i < *tam; i++){
            for(j = i - 1; pont->veiculo -> valor < bd2[j] -> valor && j >= 0;j--){         
                bd2[j+1] = bd2[j];
                if(j==0){
                    j--;
                    break;
                }
            }
            bd2[j + 1] = pont->veiculo;
    }
    for(i = 0; i < *tam && preco > bd2[i]->valor; i++){
    }
    for(int e = i - 1, d = i; k < 10 && (e >=0 || d < *tam); k++){
        if(e>=0){
            if(d < *tam){
                if((preco-bd2[e]->valor)<(bd2[d]->valor-preco)){
                    bd3[k]=bd2[e];
                    e--;
                }else if(d < *tam){
                    bd3[k]=bd2[d];
                    d++;
                }
            }else{
                bd3[k]=bd2[e];
                e--;
            }
        }else if(d < *tam){
            bd3[k]=bd2[d];
            d++;
        }
    }
    cout << endl << "OS ELEMENTOS MAIS PROXIMOS!" << endl << endl;
    mostrar(bd3,&k);
}*/
//FUNÇÃO PARA SALVAR OS DADOS NO ARQUIVO TEXTO
void salvar(cabeca *bd){
    int opc, i = 0;
    do{
        cout << "[1] - SALVAR" << endl << "[2] - NÃO SALVAR" << endl << endl << "ESCOLHA UMA OPÇÃO: ";
        cin >> opc;
        if(opc == 1){
            ofstream myfile ("BD_veiculos.txt");
            if(myfile.is_open()){
                for(no* pont = bd->prox; pont != NULL; pont = pont -> prox, i++){
                    if( i < bd->tam - 1){
                        myfile << pont->veiculo->modelo << " " << pont->veiculo->marca << " " << pont->veiculo->tipo << " " << pont->veiculo->ano << " " << pont->veiculo->km 
                        << " " << pont->veiculo->potencia << " " << pont->veiculo->combustivel << " " << pont->veiculo->cambio<< " " << pont->veiculo->direcao<< " " 
                        << pont->veiculo->cor<< " " << pont->veiculo->porta<< " " << pont->veiculo->placa<< " " << pont->veiculo->valor << "\n";
                    }else{
                        myfile << pont->veiculo->modelo << " " << pont->veiculo->marca << " " << pont->veiculo->tipo << " " << pont->veiculo->ano << " " << pont->veiculo->km 
                        << " " << pont->veiculo->potencia << " " << pont->veiculo->combustivel << " " << pont->veiculo->cambio<< " " << pont->veiculo->direcao<< " " 
                        << pont->veiculo->cor<< " " << pont->veiculo->porta<< " " << pont->veiculo->placa<< " " << pont->veiculo->valor;
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
    cabeca *bd = inicia_lista();
    cabeca *pilha = inicia_lista();
    cabeca *fila = inicia_lista();
    ifstream myfile ("BD_veiculos.txt");
    if (myfile.is_open() ) {
        bd->prox = new no;
        bd->prox->veiculo = new Tveiculo;
        no* percorre = bd->prox;
        while (!myfile.eof()){
            myfile >> percorre->veiculo->modelo;
            myfile >> percorre->veiculo->marca;
            myfile >> percorre->veiculo->tipo;
            myfile >> percorre->veiculo->ano;
            myfile >> percorre->veiculo->km;
            myfile >> percorre->veiculo->potencia;
            myfile >> percorre->veiculo->combustivel;
            myfile >> percorre->veiculo->cambio;
            myfile >> percorre->veiculo->direcao;
            myfile >> percorre->veiculo->cor;
            myfile >> percorre->veiculo->porta;
            myfile >> percorre->veiculo->placa;
            myfile >> percorre->veiculo->valor;
            if(percorre->veiculo->direcao == "Hidráulica"){
                insere_pilha(pilha, percorre->veiculo);
                pilha->tam = pilha->tam + 1;
            }
            if(percorre->veiculo->cambio == "Automático"){
                insere_fila(fila, percorre->veiculo);
                fila->tam = fila->tam + 1;
            }
            if(!myfile.eof()){
                percorre -> prox = new no;
                percorre = percorre -> prox;
                percorre->veiculo = new Tveiculo;
            }
            bd -> tam = bd -> tam + 1;
        }
        myfile.close();
        //VARIAVEL USADA PARA ESCOLHA DE OPÇÃO NO MENU
        int opc;
        //VARIAVEL USADA PARA RECEBER O PREÇO DO VEÍCULO
        float preco;
        //VARIAVEL USADA PARA RECEBER A PLACA DO VEÍCULO
        string placa;
        Tveiculo *inserir;
        //LEITURA DE ARQUIVO SIMULANDO ENTRADA DE USUÁRIO
        ifstream myfile ("veiculo_novo.txt");
        if(myfile.is_open()){
            while(!myfile.eof()){
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
            }
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
            switch(opc){
                case 0:
                    salvar(bd);
                    break;
                case 1:
                    cout <<  "DIGITE A PLACA DO VEÍCULO A PROCURAR, NO MODELO AAA0000: ";
		            cin >> placa;
                    if(busca_e_remocao_de_veiculo(bd, placa) == -1){
                        cout << "ELEMENTO NÃO ENCONTRADO!" << endl;
                    }
                    break;
                case 2:
                    cout << "DIGITE O PREÇO DO VEÍCULO A PROCURAR: ";
		            cin >> preco;
                    //busca_por_preco(bd, preco, &i);
                    break;
                case 3:
                    ordena_por_placa(bd);
                    cout <<  "ORDENADO! " << endl;
                    break;
                case 4:
                    mostrar(bd);
                    break;
                case 5:
                    cout << "ENTRADA DE USUÁRIO SIMULADA" << endl;
                    insercao_veiculo(bd, inserir);
                    break;
                default:
                    cout << "VALOR INVÁLIDO, DIGITE APENAS '0', '1', '2', '3', '4' OU '5'!" <<  endl;
                    break;
            }
        }while(opc != 0);
    //LIBERANDO MEMÓRIA USADA
    encerra_lista(bd);
    }else{
        cout << "Unable to open file\n";    
	}
}
