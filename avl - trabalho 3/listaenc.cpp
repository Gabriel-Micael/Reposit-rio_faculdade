#include "listaenc.h"
#include "avl.h"
#include <fstream>

//FUNÇÃO PARA FAZER A LEITURA DE UMA LINHA DO ARQUIVO
void read_file(Tveiculo *veiculo, string nome_do_arquivo){
    ifstream myfile(nome_do_arquivo);
    if (myfile.is_open()) {
      while (!myfile.eof()) {
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
      }
      myfile.close();
    } else {
      cout << "Unable to open file\n";
    }
}

// FUNÇÃO PARA IMPRIMIR O VETOR DE STRUCT NA TELA
/**
 * @param bd endereço de uma estrutura do tipo cabeca
 * @return 1 se a lista encadeada não estiver vazia e 0 caso cotrário
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
 * @param veiculo endereço de um estrutura veiculo
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
// FUNÇÃO QUE VAI TENTAR BUSCAR UM ELEMENTO E, SE ACHAR, PERGUNTAR SE DEVE REMOVER
/**
 * @param bd recebe uma estrutura cabeca
 * @param placa recebe uma string com a identificação da placa do veículo
 * @return 0 caso a lista encadeada esteja vazia ou o elemento não tenha sido encontrado
 * @return 1 caso tenha sido encontrado e excluído
 * @return 2 caso tenha sido encontrado, mas não foi excluído
*/
int busca_e_remocao_de_veiculo(cabeca *bd, string placa) {
  int opc;
  if (bd->prox == NULL) {
    cout << endl << "BANCO DE DADOS VAZIO!" << endl;
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
      cout << "ELEMENTO ENCONTRADO. DESEJA REMOVÊ-LO? ( 1 - SIM, 0 - NÃO) ";
      cin >> opc;
      if (opc == 0) {
        return 2;
      } else if (opc == 1) {
        if (ant == NULL) {
          bd->prox = pont->prox;
        } else {
          ant->prox = pont->prox;
        }
        delete (pont->veiculo);
        delete (pont);
        bd->tam = bd->tam - 1;
        return 1;
      } else {
        cout << endl << "DIGITE APENAS '1' OU '0'" << endl;
      }
    } while (opc != 0 && opc != 1);
  }
}

// FUNÇÃO PARA SALVAR OS DADOS NO ARQUIVO TEXTO
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
  } while (opc != 1 && opc != 2);
}

//FUNÇÃO QUE INICIA A LISTA ENCADEADA
cabeca * inicia_lista(){
  cabeca * novo = new cabeca;
  novo->prox = NULL;
  novo->tam = 0;
  return novo;
}

//FUNÇÃO QUE ENCERRA A LISTA ENCADEADA
void encerra_lista(cabeca *bd) {
  no *ant;
  for (no *pont = bd->prox; pont != NULL;) {
    ant = pont;
    pont = pont->prox;
    delete (ant);
  }
  delete (bd);
}
