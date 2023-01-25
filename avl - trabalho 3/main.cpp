/*
 * Autores: Gabriel Micael Henrique (2022.1.08.035)
 *          Rodrigo Cabral          (2022.1.08.037)
 *          Henry Lopes             (2022.1.08.038)
 *
 */

#include <fstream>
#include <iostream>
#include "avl.h"
#include "listaenc.h"

using namespace std;

int main() {
  cabeca *bd = inicia_lista();
  PONT *treebinary = new PONT;
  PONT *treeAVL = new PONT;
  inicializar(treeAVL);
  inicializar(treebinary);
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
    // VARIAVEL USADA PARA RECEBER A PLACA DO VEÍCULO
    string placa;
    // ESTRUTURA PARA GUARDAR AS INFORMAÇÕES DO VEÍCULO NOVO A SER USADO NA SIMULAÇÃO DE ENTRADA
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
           << "[2] - " << endl
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
        if (busca_e_remocao_de_veiculo(bd, placa) == -1) {
        cout << "ELEMENTO NÃO ENCONTRADO!" << endl;
        }
        break;
      case 2:
        break;
      case 3:
        do {
          cout << "------------------------------------------------------------"
                  "--"
               << endl
               << "[0] - LISTA PRINCIAPAL" << endl
               << "[1] - ÁRVORE BINÁRIA" << endl
               << "[2] - ÁRVORE AVL" << endl
               << "------------------------------------------------------------"
                  "--"
               << endl
               << "ESCOLHA UMA OPÇÃO: ";
          cin >> opc2;
          if (opc2 == 0) {
            if (!mostrar(bd)) {
              cout << endl << "LISTA VAZIA" << endl;
            }
          } else if (opc2 == 1) {
            make_tree_binary(treebinary, bd);
          } else if (opc2 == 2) {
            make_tree_AVL(treeAVL, bd);
          } else {
            cout << endl
                 << "VALOR INVÁLIDO, DIGITE APENAS '0', '1' OU '2'" << endl;
          }
        } while (opc2 != 0 && opc2 != 1 && opc2 != 2);
        break;
      case 4:
        cout << "ENTRADA DE USUÁRIO SIMULADA" << endl;
        insercao_veiculo(bd, inserir);
        break;
      default:
        cout << "VALOR INVÁLIDO, DIGITE APENAS '0' - '4'!" << endl;
        break;
      }
    } while (opc != 0);
    // LIBERANDO MEMÓRIA USADA
    encerra_lista(bd);
  } else {
    cout << "Unable to open file\n";
  }
}