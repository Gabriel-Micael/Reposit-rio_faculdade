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
 * binárias e árvores avl. Oferece os recursos de buscas variadas, exclusão 
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
  //VARIAVEIS USADAS EM MENUS
  PONT teste;
  int opc, opc2, opc3, verifica, valor;
  string placa;
  if((bd -> prox = read_file_listaenc(bd,"BD_veiculos.txt"))){
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
           << "[1] - SAIR" << endl
           << "[2] - FILTROS" << endl
           << "[3] - INCLUSÃO" << endl
           << "[4] - EXCLUSÃO" << endl
           << "[5] - RELATÓRIOS" << endl
           << "--------------------------------------------------------------"
           << endl
           << "ESCOLHA UMA OPÇÃO: ";
      cin >> opc;
      if(verifica_entrada()){
        switch (opc) {
        case 1:
          salvar(bd);
          break;
        case 2:
          do{
            cout << endl << "--------------------------------------------------------------"
            << endl
            << "[1] - VOLTAR" << endl
            << "[2] - PLACA" << endl
            << "[3] - VALOR" << endl
            << "[4] - DIREÇÃO" << endl
            << "[5] - CÂMBIO" << endl
            << "[6] - COR" << endl
            << "[7] - MODELO" << endl
            << "--------------------------------------------------------------"
            << endl
            << "ESCOLHA UMA OPÇÃO: ";
            cin >> opc2;
            if(verifica_entrada()){
              if(opc2 == 2){
                  cout << endl << "DIGITE A PLACA A PROCURAR: ";
                  cin >> placa;
                  if((teste = buscaBinaria_placa(placa, treeAVL))){
                    imprimir_veiculo(teste->veiculo);
                  }else{
                    cout << endl << "NÃO ENCONTRADO!" << endl;
                  }
              }else if(opc2 == 3){
                do{
                  cout << endl << "DIGITE O VALOR:";
                  cin >> valor;
                }while(!verifica_entrada());
                do{
                  cout << endl << "----------------------------------------------" << endl
                  << "[1] - VALORES MAIORES" << endl
                  << "[2] - VALORES MENORES" << endl
                  << "----------------------------------------------" << endl
                  << "ESCOLHA UMA OPÇÃO:";
                  cin >> opc3;
                }while(!verifica_entrada() || (opc3 != 1 && opc3 != 2));
                if(opc3 == 1 ){
                  valores_acima(treeAVL, valor);
                }else if( opc3 == 2){
                  valores_abaixo(treeAVL, valor);
                }
              }else if(opc2 == 4){
                do{
                  cout << endl << "----------------------------------------------" << endl
                  << "[1] - HIDRÁULICA" << endl
                  << "[2] - ELÉTRICA" << endl
                  << "----------------------------------------------" << endl
                  << "ESCOLHA UMA OPÇÃO:";
                  cin >> opc3;
                }while(!verifica_entrada() || (opc3 != 1 && opc3 != 2));
                if(opc3 == 1){
                  direcao_hidraulica(treeAVL);
                }else if(opc3 == 2){
                  direcao_eletrica(treeAVL);
                }
              }else if(opc2 == 5){
                do{
                  cout << endl << "----------------------------------------------" << endl
                  << "[1] - AUTOMÁTICO" << endl
                  << "[2] - MANUAL" << endl
                  << "----------------------------------------------" << endl
                  << "ESCOLHA UMA OPÇÃO:";
                  cin >> opc3;
                }while(!verifica_entrada() || (opc3 != 1 && opc3 != 2));
                if(opc3 == 1){
                  cambio_automatico(treeAVL);
                }else if(opc3 == 2){
                  cambio_manual(treeAVL);
                }
              }else if(opc2 == 6){
                do{
                  cout << endl << "----------------------------------------------" << endl
                  << "[1] - BRANCO" << endl
                  << "[2] - PRETO" << endl
                  << "[3] - PRATA" << endl
                  << "[4] - CINZA" << endl
                  << "[5] - LARANJA" << endl
                  << "[6] - VERMELHO" << endl
                  << "----------------------------------------------" << endl
                  << "ESCOLHA UMA OPÇÃO:";
                  cin >> opc3;
                }while(!verifica_entrada() || (opc3 != 1 && opc3 != 2 && opc3 != 3 && opc3 != 4 && opc3 != 5 && opc3 != 6));
                if(opc3 == 1){
                  cor(treeAVL, "Branco");
                }else if(opc3 == 2){
                  cor(treeAVL, "Preto");
                }else if(opc3 == 3){
                  cor(treeAVL, "Prata");
                }else if(opc3 == 4){
                  cor(treeAVL, "Cinza");
                }else if(opc3 == 5){
                  cor(treeAVL, "Laranja");
                }else if(opc3 == 6){
                  cor(treeAVL, "Vermelho");
                }
              }else if(opc2 == 7){
                cout << "DIGITE O MODELO:";
                cin >> placa;
                modelo(treeAVL, placa);
              }
            }
          }while( opc2 != 1 && opc2 != 2
           && opc2 != 3 && opc2 != 4 && opc2 != 5 && opc2 != 6 && opc2 != 7);
          break;
        case 3:
          insercao_veiculo(bd, inserir);
          treeAVL = insere_avl(treeAVL, inserir);
          treebinary = insert_tree_binary(treebinary, inserir);
          cout << "ENTRADA DE USUÁRIO SIMULADA" << endl;
          break;
        case 4:
          cout << "DIGITE A PLACA DO VEÍCULO A EXCLUIR: ";
          cin >> placa;
          verifica = busca_e_remocao_de_veiculo(bd, placa);
          if( verifica == 2){
            remove_avl(treeAVL, placa);
            remove_binary(treebinary, placa);
            cout << endl << "REMOVIDO!!" << endl;
          }else if( verifica == 0){
            cout << "VALOR NÃO ENCONTRADO OU BANCO DE DADOS VAZIO!" << endl;
          }else{
            cout << "VALOR ENCONTRADO, MAS NÃO REMOVIDO!" << endl;
          }
          break;
          break;
        case 5:
        do {
            cout << endl << "------------------------------------------------------------"
                    "--"
                << endl
                << "[1] - LISTA PRINCIPAL" << endl
                << "[2] - ÁRVORE BINÁRIA" << endl
                << "[3] - ÁRVORE AVL" << endl
                << "------------------------------------------------------------"
                    "--"
                << endl
                << "ESCOLHA UMA OPÇÃO: ";
            cin >> opc2;
            if(verifica_entrada()){
              if (opc2 == 1) {
                if (!mostrar(bd)) {
                  cout << endl << "LISTA VAZIA" << endl;
                }
              } else if (opc2 == 2) {
                printAVLTree(treebinary, 0);
                cout << endl << "BINÁRIA EM PRÉ-ORDEM: ";
                exibirArvorePreOrdem(treebinary);
              } else if (opc2 == 3) {
                printAVLTree(treeAVL, 0);
                cout << endl << "AVL EM PRÉ-ORDEM: ";
                exibirArvorePreOrdem(treeAVL);
              } else {
                cout << "DIGITE APENAS '0', '1' OU '2'" << endl;
              }
            }
          } while (opc2 != 1 && opc2 != 2 && opc2 != 3);
          break;
        default:
          cout << "VALOR INVÁLIDO, DIGITE APENAS '0' - '4'!" << endl;
          break;
        }
      }
     }while (opc != 1);
    // LIBERANDO MEMÓRIA USADA
    encerra_lista(bd);
    destruirArvore(&treebinary);
    destruirArvore(&treeAVL);
}
}
