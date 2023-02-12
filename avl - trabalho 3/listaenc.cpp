#include "listaenc.h"
#include "avl.h"
#include "binary.h"
#include <fstream>

//FUNÇÃO PARA FAZER A LEITURA DE UMA LINHA DE ARQUIVO *TXT
/**
 * @param veiculo endereço de um estrutura Tveiculo
 * @param nome_do_arquivo cadeia de caracteres com o nome do arquivo *txt
 * @return endereço da estrutura Tveiculo que está guardando os dados lidos
*/
Tveiculo * read_file(Tveiculo* veiculo, string nome_do_arquivo){
    ifstream myfile(nome_do_arquivo);
    if (myfile.is_open()) {
      veiculo = new Tveiculo;
      myfile >> veiculo->modelo;
      myfile >> veiculo->marca;
      myfile >> veiculo->tipo;
      myfile >> veiculo->ano;
      myfile >> veiculo->km;
      myfile >> veiculo->potencia;
      myfile >> veiculo->combustivel;
      myfile >> veiculo->cambio;
      myfile >> veiculo->direcao;
      myfile >> veiculo->cor;
      myfile >> veiculo->porta;
      myfile >> veiculo->placa;
      myfile >> veiculo->valor;
      myfile.close();
      return veiculo;
    }
    cout << "Unable to open file\n";
    return NULL;
}

//FUNÇÃO PARA FAZER A LEITURA DO ARQUIVO E GUARDAR EM UMA LISTA ENCADEADA
/**
 * @param bd endereço de uma estrutura do tipo cabeça (cabeçalho da lista encadeada)
 * @param nome_do_arquivo string com o nome do arquivo *txt a ser lido
 * @return endereço do cabeçalho da lista encadeada atualizada ou NULL caso não consiga
 * abrir o aquivo *txt
*/
no * read_file_listaenc(cabeca* bd, string nome_do_arquivo){
  ifstream myfile(nome_do_arquivo);
  if (myfile.is_open()) {
    bd->prox = new no;
    bd->prox->veiculo = new Tveiculo;
    no *percorre = bd->prox;
    while (!myfile.eof()) {
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
      if (!myfile.eof()) {
        percorre->prox = new no;
        percorre = percorre->prox;
        percorre -> prox = NULL;
        percorre->veiculo = new Tveiculo;
      }
      bd->tam = bd->tam + 1;
    }
    myfile.close();
    return bd -> prox;
} else {
    cout << "Unable to open file\n";
    return NULL;
}
}


// FUNÇÃO PARA IMPRIMIR O VETOR DE STRUCT NA TELA
/**
 * @param bd endereço de uma estrutura cabeca
 * @return 1 caso consiga imprimir os dados da estrutura
 * @return 0 caso a estrutura esteja "vazia"
*/
int mostrar(cabeca *bd) {
  if (bd->prox != NULL) {
    for (no *pont = bd->prox; pont != NULL; pont = pont->prox) {
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
    return 1;
  } else {
    return 0;
  }
}

// FUNÇÃO QUE VAI TENTAR INSERIR UM NOVO VEÍCULO AO BANCO DE DADOS
/**
 * @param bd endereço de uma estrutura cabeca
 * @param veiculo endereço de uma estrutura Tveiculo
*/
void insercao_veiculo(cabeca *bd, Tveiculo *veiculo) {
  no *novo = new no;
  novo->veiculo = veiculo;
  novo->prox = NULL;
  if (bd->prox == NULL) {
    bd->prox = novo;
  } else {
    no *pont;
    for (pont = bd->prox; pont->prox != NULL; pont = pont->prox) {
    }
    pont->prox = novo;
    bd->tam = bd->tam + 1;
  }
}
// FUNÇÃO QUE VAI TENTAR BUSCAR UM ELEMENTO E, SE ACHAR, PERGUNTAR SE DEVE
// REMOVER
/**
 * @param bd endereço de uma estrutura cabeca
 * @param placa cadeia de caracteres com a identificação da
 * placa do veículo
 * @return 0 caso o veículo não seja encontrado ou o banco
 * de dados esteja vazio
 * @return 1 caso o veículo seja encontrado mas não removido
 * @return 2 caso o veículo seja econtrado e removido
*/
int busca_e_remocao_de_veiculo(cabeca *bd, string placa) {
  int opc = -1;
  if (bd->prox == NULL) {
    return 0;
  }
  no *ant = NULL;
  no *pont;
  for (pont = bd->prox; pont != NULL && pont->veiculo->placa != placa;
       ant = pont, pont = pont->prox) {
  }
  if (pont == NULL) {
    return 0;
  } else {
    do {
      cout << "ELEMENTO ENCONTRADO. DESEJA REMOVÊ-LO? ( 1 - SIM, 2 - NÃO) ";
      cin >> opc;
      if(verifica_entrada()){
        if (opc == 2) {
          return 1;
        } else if (opc == 1) {
          if (ant == NULL) {
            bd->prox = pont->prox;
          } else {
            ant->prox = pont->prox;
          }
          delete (pont->veiculo);
          delete (pont);
          bd->tam = bd->tam - 1;
          return 2;
        } else {
          cout << endl << "DIGITE APENAS '1' OU '2'" << endl;
        }
      }
    } while (opc != 1 && opc != 2);
  }
}

// FUNÇÃO PARA SALVAR OS DADOS NO ARQUIVO TEXTO
/**
 * @param bd endereço de uma estrutura cabeca
*/
void salvar(cabeca *bd) {
  int opc, i = 0;
  do {
    cout << "--------------------------------------------------------------"
         << endl
         << "[1] - SALVAR" << endl
         << "[2] - NÃO SALVAR" << endl
         << "--------------------------------------------------------------"
         << endl
         << "ESCOLHA UMA OPÇÃO: ";
    cin >> opc;
    if(!verifica_entrada()){
      if (opc == 1) {
        ofstream myfile("BD_veiculos.txt");
        if (myfile.is_open()) {
          for (no *pont = bd->prox; pont != NULL; pont = pont->prox, i++) {
            myfile << pont->veiculo->modelo << " " << pont->veiculo->marca << " "
                  << pont->veiculo->tipo << " " << pont->veiculo->ano << " "
                  << pont->veiculo->km << " " << pont->veiculo->potencia << " "
                  << pont->veiculo->combustivel << " " << pont->veiculo->cambio
                  << " " << pont->veiculo->direcao << " " << pont->veiculo->cor
                  << " " << pont->veiculo->porta << " " << pont->veiculo->placa
                  << " " << pont->veiculo->valor;
            if(i < bd->tam - 1){
              myfile << "\n";
            }
          }
          myfile.close();
        } else {
          cout << "Unable to open file\n" << endl;
        }
      } else if (opc == 2) {
      } else {
        cout << endl << "DIGITE APENAS '1' OU '2'!" << endl;
      }
    }
  } while (opc != 1 && opc != 2);
}

//FUNÇÃO QUE INICIA A LISTA ENCADEADA
/**
 * @return endereço de uma estrutura cabeca alocada na memória
*/
cabeca * inicia_lista(){
  cabeca * novo = new cabeca;
  novo->prox = NULL;
  novo->tam = 0;
  return novo;
}

//FUNÇÃO QUE ENCERRA A LISTA ENCADEADA
/**
 * @param bd endereço de uma estrutura cabeca
*/
void encerra_lista(cabeca *bd) {
  no *ant;
  for (no *pont = bd->prox; pont != NULL;) {
    ant = pont;
    pont = pont->prox;
    delete (ant);
  }
  delete (bd);
}

/**
 * @return 0 se o tipo de entrada não for o tipo esperado
 * @return 1 caso contrário
*/
int verifica_entrada(){
  if(cin.fail()){
      cin.clear();
      fflush(stdin);
      cout << "VALOR INVÁLIDO!" << endl;
      return 0;
  }return 1;
}
