/*
 * Autores: Gabriel Micael Henrique (2022.1.08.035)
 *          Rodrigo Cabral          (2022.1.08.037)
 *          Henry Lopes             (2022.1.08.038)
 *
 * Tipo do projeto: vetor sem buracos
 */

#include <fstream>
#include <iostream>
using namespace std;

// ESTRUTURA QUE SERVIRÁ DE MODELO PARA AS INFORMAÇÕES DOS VEÍCULOS SEREM
// GUARDADAS
struct Tveiculo {
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

typedef struct no_ {
  Tveiculo *veiculo;
  no_ *prox;
} no;

typedef struct {
  int tam;
  no *prox;
} cabeca;

cabeca *inicia_lista() {
  cabeca *novo = new cabeca;
  novo->prox = NULL;
  novo->tam = 0;
  return novo;
}

void encerra_lista(cabeca *bd) {
  no *ant;
  for (no *pont = bd->prox; pont != NULL;) {
    ant = pont;
    pont = pont->prox;
    delete (ant);
  }
  delete (bd);
}

void insere_pilha(cabeca *pilha, Tveiculo *veiculo) {
  no *novo = new no;
  novo->veiculo = veiculo;
  novo->prox = pilha->prox;
  pilha->prox = novo;
}
void insere_fila(cabeca *fila, Tveiculo *veiculo) {
  no *novo = new no;
  novo->veiculo = veiculo;
  novo->prox = NULL;
  no *pont;
  if (fila->prox != NULL) {
    for (pont = fila->prox; pont->prox != NULL; pont = pont->prox) {
    }
    pont->prox = novo;
  } else {
    fila->prox = novo;
  }
}

// FUNÇÃO PARA IMPRIMIR O VETOR DE STRUCT NA TELA
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
// FUNÇÃO QUE ORDENARÁ O VETOR DE LEITURA DO ARQUIVO EM ORDEM ALFANUMÉRICA DA
// PLACA
void ordena_por_placa(cabeca *bd) {
  cabeca *bd2 = inicia_lista();
  bd2->prox = new no;
  bd2->tam = 1;
  no * pont2 = bd2->prox;
  no * ant;
  for (; bd2->tam < bd->tam; pont2 = pont2->prox) {
    pont2->prox = new no;
    bd2->tam = bd2->tam + 1;
  }
  for (no *pont1 = bd->prox; pont1 != NULL; pont1 = pont1->prox) {
    ant = NULL;
    for (pont2 = bd2->prox;
         pont2->prox != NULL &&
         pont2->prox->veiculo->placa < pont1->veiculo->placa;
        ant = pont2, pont2 = pont2->prox) {
    }
    if(ant == NULL){
      pont2 -> prox -> veiculo = pont2 -> veiculo;
    }
  }
  mostrar(bd2);
  encerra_lista(bd2);
}
// FUNÇÃO QUE VAI TENTAR INSERIR UM NOVO VEÍCULO AO BANCO DE DADOS
void insercao_veiculo(cabeca *bd, cabeca *pilha, cabeca *fila,
                      Tveiculo *veiculo) {
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
  if (veiculo->direcao == "Hidráulica") {
    insere_pilha(pilha, veiculo);
  }
  if (veiculo->cambio == "Automático") {
    insere_fila(fila, veiculo);
  }
}
// FUNÇÃO QUE VAI TENTAR BUSCAR UM ELEMENTO E, SE ACHAR, PERGUNTAR SE DEVE
// REMOVER
int busca_e_remocao_de_veiculo(cabeca *bd, cabeca *pilha, cabeca *fila,
                               string placa) {
  int opc;
  if (bd->prox == NULL) {
    cout << endl << "BANCO DE DADOS VAZIO!" << endl;
    return -2;
  }
  no *ant = NULL;
  no *pont;
  for (pont = bd->prox; pont != NULL && pont->veiculo->placa != placa;
       ant = pont, pont = pont->prox) {
  }
  if (pont == NULL) {
    return -1;
  } else {
    cout << "ELEMENTO ENCONTRADO. DESEJA REMOVÊ-LO? ( 1 - SIM, 0 - NÃO) ";
    cin >> opc;
    if (opc == 0) {
      return 0;
    } else if (opc == 1) {
      if (ant == NULL) {
        bd->prox = pont->prox;
      } else {
        ant->prox = pont->prox;
      }
      // atualizando a pilha
      if (pilha->prox != NULL && pont->veiculo->direcao == "Hidráulica") {
        no *pont2 = pilha->prox;
        if (pilha->prox->veiculo == pont->veiculo) {
          pilha->prox = pont2->prox;
          delete (pont2);
        } else {
          for (; pont2->prox->veiculo != pont->veiculo && pont2->prox != NULL;
               pont2 = pont2->prox) {
          }
          no *aux = pont2->prox;
          pont2->prox = aux->prox;
          delete (aux);
          pilha->tam = pilha->tam - 1;
        }
      }
      // atualizando a fila
      if (fila->prox != NULL && pont->veiculo->cambio == "Automático") {
        no *pont2 = fila->prox;
        if (fila->prox->veiculo == pont->veiculo) {
          fila->prox = pont2->prox;
          delete (pont2);
        } else {
          for (; pont2->prox->veiculo != pont->veiculo && pont2->prox != NULL;
               pont2 = pont2->prox) {
          }
          no *aux = pont2->prox;
          pont2->prox = aux->prox;
          delete (aux);
          fila->tam = fila->tam - 1;
        }
      }
      delete (pont->veiculo);
      delete (pont);
      return 1;
    } else {
      cout << endl << "DIGITE APENAS '1' OU '0'" << endl;
    }
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
          if (i < bd->tam - 1) {
            myfile << pont->veiculo->modelo << " " << pont->veiculo->marca
                   << " " << pont->veiculo->tipo << " " << pont->veiculo->ano
                   << " " << pont->veiculo->km << " " << pont->veiculo->potencia
                   << " " << pont->veiculo->combustivel << " "
                   << pont->veiculo->cambio << " " << pont->veiculo->direcao
                   << " " << pont->veiculo->cor << " " << pont->veiculo->porta
                   << " " << pont->veiculo->placa << " " << pont->veiculo->valor
                   << "\n";
          } else {
            myfile << pont->veiculo->modelo << " " << pont->veiculo->marca
                   << " " << pont->veiculo->tipo << " " << pont->veiculo->ano
                   << " " << pont->veiculo->km << " " << pont->veiculo->potencia
                   << " " << pont->veiculo->combustivel << " "
                   << pont->veiculo->cambio << " " << pont->veiculo->direcao
                   << " " << pont->veiculo->cor << " " << pont->veiculo->porta
                   << " " << pont->veiculo->placa << " "
                   << pont->veiculo->valor;
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

int make_pilha(cabeca *pilha, cabeca *bd) {
  if (bd->prox != NULL) {
    for (no *pont = bd->prox; pont != NULL; pont = pont->prox) {
      if (pont->veiculo->direcao == "Hidráulica") {
        insere_pilha(pilha, pont->veiculo);
        pilha->tam = pilha->tam + 1;
      }
    }
    if (pilha->tam == 0) { // significa que não há pelo menos um veículo com
                           // direção hidráulica no banco de dados
      return -1;
    }
    return 1; // significa que funcionou
  }
  return 0; // significa que a lista encadeada principal está vazia
}

int make_fila(cabeca *fila, cabeca *bd) {
  no *pont = bd->prox;
  if (bd->prox != NULL) {
    for (; pont != NULL; pont = pont->prox) {
      if (pont->veiculo->cambio == "Automático") {
        insere_fila(fila, pont->veiculo);
        fila->tam = fila->tam + 1;
      }
    }
    if (fila->tam == 0) { // significa que não há pelo menos um veículo com
                          // câmbio automático no banco de dados
      return -1;
    }
    return 1; // significa que funcionou
  }
  return 0; // significa que a lista encadeada principal está vazia
}

int main() {
  cabeca *bd = inicia_lista();
  cabeca *pilha = inicia_lista();
  cabeca *fila = inicia_lista();
  ifstream myfile("BD_veiculos.txt");
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
        percorre->veiculo = new Tveiculo;
      }
      bd->tam = bd->tam + 1;
    }
    myfile.close();
    // VARIAVEL USADA PARA ESCOLHA DE OPÇÃO NO MENU
    int opc, opc2, verifica;
    // VARIAVEL USADA PARA RECEBER O PREÇO DO VEÍCULO
    float preco;
    // VARIAVEL USADA PARA RECEBER A PLACA DO VEÍCULO
    string placa;
    Tveiculo *inserir;
    // LEITURA DE ARQUIVO SIMULANDO ENTRADA DE USUÁRIO
    ifstream myfile("veiculo_novo.txt");
    if (myfile.is_open()) {
      while (!myfile.eof()) {
        inserir = new Tveiculo;
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
    } else {
      cout << "Unable to open file\n";
    }
    do {
      // MENU
      cout << "--------------------------------------------------------------"
           << endl
           << "[0] - SAIR" << endl
           << "[1] - BUSCA POR PLACA" << endl
           << "[2] - ORDENAR PELA PLACA" << endl
           << "[3] - RELATÓRIO" << endl
           << "[4] - INSERIR" << endl
           << "--------------------------------------------------------------"
           << endl
           << "ESCOLHA UMA OPÇÃO: ";
      cin >> opc;
      switch (opc) {
      case 0:
        salvar(bd);
        break;
      case 1:
        cout << "DIGITE A PLACA DO VEÍCULO A PROCURAR, NO MODELO AAA0000: ";
        cin >> placa;
        if (busca_e_remocao_de_veiculo(bd, pilha, fila, placa) == -1) {
          cout << "ELEMENTO NÃO ENCONTRADO!" << endl;
        }
        break;
      case 2:
        ordena_por_placa(bd);
        cout << "ORDENADO! " << endl;
        break;
      case 3:
        do {
          cout << "------------------------------------------------------------"
                  "--"
               << endl
               << "[0] - TODOS OS VEÍCULOS" << endl
               << "[1] - VEÍCULOS COM DIREÇÂO HIDRÁULICA" << endl
               << "[2] - VEÍCULOS COM CÂMBIO AUTOMÁTICO" << endl
               << "------------------------------------------------------------"
                  "--"
               << endl
               << "ESCOLHA UMA OPÇÃO: ";
          cin >> opc2;
          if (opc2 == 0) {
            if (mostrar(bd) == 0) {
              cout << endl << "LISTA VAZIA" << endl;
            }
          } else if (opc2 == 1) {
            if (mostrar(pilha) == 0) {
              make_pilha(pilha, bd);
              mostrar(pilha);
            }
          } else if (opc2 == 2) {
            if (mostrar(fila) == 0) {
              make_fila(fila, bd);
              mostrar(fila);
            }
          } else {
            cout << endl
                 << "VALOR INVÁLIDO, DIGITE APENAS '0', '1' OU '2'" << endl;
          }
        } while (opc2 != 0 && opc2 != 1 && opc2 != 2);
        break;
      case 4:
        cout << "ENTRADA DE USUÁRIO SIMULADA" << endl;
        insercao_veiculo(bd, pilha, fila, inserir);
        break;
      default:
        cout << "VALOR INVÁLIDO, DIGITE APENAS '0' - '4'!" << endl;
        break;
      }
    } while (opc != 0);
    // LIBERANDO MEMÓRIA USADA
    encerra_lista(bd);
    encerra_lista(pilha);
    encerra_lista(fila);
  } else {
    cout << "Unable to open file\n";
  }
}
