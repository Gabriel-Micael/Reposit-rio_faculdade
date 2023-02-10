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

int main() {
  // CABEÇALHO DA LISTA ENCADEADA
  cabeca *bd = inicia_lista();
  // NÓ RAIZ DA ÁRVORE AVL E BINARIA
  PONT treebinary = NULL;
  PONT treeAVL = NULL;
  // VARIAVEL USADA PARA ESCOLHA DE OPÇÃO NO MENU
  int opc, opc2;
  // VARIAVEL USADA PARA RECEBER A PLACA DO VEÍCULO
  string placa;
  if((bd -> prox = read_file_listaenc(bd,"BD_veiculos.txt",treeAVL, treebinary))){
    // CRIANDO ÁRVORES BINÁRIA E AVL PARA RELATÓRIO GERAL
    for(no* pont = bd -> prox; pont != NULL; pont = pont -> prox){
      treeAVL = insere_avl(treeAVL, pont->veiculo);
      treebinary = insert_tree_binary(treebinary, pont -> veiculo);
    }
    // ESTRUTURA A SER USADA NA ENTRADA DE USUÁRIO SIMULADA
    Tveiculo *inserir = read_file(inserir, "veiculo_novo.txt");
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
        cout << "[]"; 
        break;
      case 2:
        insercao_veiculo(bd, inserir);
        treeAVL = insere_avl(treeAVL, inserir);
        treebinary = insert_tree_binary(treebinary, inserir);
        cout << "ENTRADA DE USUÁRIO SIMULADA" << endl;
        break;
      case 3:
        cout << "DIGITE A PLACA DO VEÍCULO A EXCLUIR: ";
        cin >> placa;
        if(busca_e_remocao_de_veiculo(bd, placa)){
          remove_avl(treeAVL, placa);
          remove_binary(treebinary, placa);
        }else{
          cout << "VALOR NÃO ENCONTRADO OU BANCO DE DADOS VAZIO!" << endl;
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
  }
}
