/*
 *      BANCO DE DADOS (VEÍCULOS) USANDO LISTA ENCADEADA, ÁRVORES AVLS E BINÁRIAS.
 *                                      AEDs II
 *
 *
 *
 * Autores: Gabriel Micael Henrique (2022.1.08.035)
 *          Rodrigo Cabral Diniz    (2022.1.08.037)
 *
 *  Esse programa é feito em c++ e tem como objetivo gerenciar um banco
 * de dados relacionados a veículos usando lista encadeada, árvores 
 * binárias e árvores avl. Oferece os recursos de busca variadas, exclusão 
 * e inclusão de veículos, além de relatórios variados e a possibilidade de salvamento
 * das alterações feitas.
 * 
 */

/**
 * Bibliotecas utilizadas no programa
*/
#include <fstream>
#include <iostream>
#include "avl.h"
#include "listaenc.h"
#include "binary.h"

using namespace std;

//Função principal
int main() {
  cabeca *bd = inicia_lista();
  PONT treebinary = NULL;
  PONT treeAVL = NULL;
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
      treeAVL = insere_avl(treeAVL, percorre->veiculo);
      treebinary = insert_tree_binary(treebinary, percorre->veiculo); 
      if (!myfile.eof()) {
        percorre->prox = new no;
        percorre = percorre->prox;
        percorre -> prox = NULL;
        percorre->veiculo = new Tveiculo;
      }
      bd->tam = bd->tam + 1;
    }
    myfile.close();
    // VARIAVEL USADA PARA ESCOLHA DE OPÇÃO NO MENU
    int opc, opc2;
    // VARIAVEL USADA PARA RECEBER A PLACA DO VEÍCULO
    string placa;
    // ESTRUTURA PARA GUARDAR AS INFORMAÇÕES DO VEÍCULO NOVO A SER USADO NA SIMULAÇÃO DE ENTRADA
    Tveiculo *inserir;
    // LEITURA DE ARQUIVO SIMULANDO ENTRADA DE USUÁRIO
    //read_file(&inserir, "veiculo_novo.txt");
    ifstream myfile("veiculo_novo.txt"); 
    if (myfile.is_open()) {
      while (!myfile.eof()) {
        inserir = new Tveiculo;
        myfile >> inserir->modelo;
        myfile >> inserir->marca;
        myfile >> inserir->tipo;
        myfile >> inserir->ano;
        myfile >> inserir->km;      //CONSERTAR A FUNÇÂO DE LER ARQUIVO
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
      cout << endl << "--------------------------------------------------------------"
           << endl
           << "[0] - SAIR" << endl
           << "[1] - BUSCAS" << endl
           << "[2] - INCLUSÃO" << endl
           << "[3] - EXCLUSÃO" << endl
           << "[4] - RELATÓRIOS" << endl
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
        cout << "ENTRADA DE USUÁRIO SIMULADA" << endl;
        insercao_veiculo(bd, inserir);
        treeAVL = insere_avl(treeAVL, inserir);
        treebinary = insert_tree_binary(treebinary, inserir);
        break;
      case 3:
        cout << "DIGITE A PLACA DO VEÍCULO A EXCLUIR: ";
        cin >> placa;
        if(!remove_avl(treeAVL, placa) || !remove_binary(treebinary, placa) || !busca_e_remocao_de_veiculo(bd, placa)){
          cout << "VALOR NÃO ENCONTRADO!" << endl;
        }
        break;
      case 4:
      do {
          cout << "------------------------------------------------------------"
                  "--"
               << endl
               << "[0] - LISTA PRINCIPAL" << endl
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
            printAVLTree(treebinary, 0);
          } else if (opc2 == 2) {
            printAVLTree(treeAVL, 0);
          } else {
            cout << endl
                 << "VALOR INVÁLIDO, DIGITE APENAS '0', '1' OU '2'" << endl;
          }
        } while (opc2 != 0 && opc2 != 1 && opc2 != 2);
        break;
      default:
        cout << "VALOR INVÁLIDO, DIGITE APENAS '0' - '4'!" << endl;
        break;
      }
    } while (opc != 0);
    // LIBERANDO MEMÓRIA USADA
    encerra_lista(bd);
    destruirArvore(&treebinary);
    destruirArvore(&treeAVL);
  } else {
    cout << "Unable to open file\n";
  }
}
