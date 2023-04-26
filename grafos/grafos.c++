#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grafo{{0,1,0,0,1,0,0,0},
                          {1,0,0,0,0,1,0,0},
                          {0,0,0,1,0,1,1,0},
                          {0,0,1,0,0,0,1,1},
                          {1,0,0,0,0,0,0,0},
                          {0,1,1,0,0,0,1,0},
                          {0,0,1,1,0,1,0,1},
                          {0,0,0,1,0,0,1,0},
                          };
vector<string> ListaDeStatus{"branco",
                             "branco",
                             "branco",
                             "branco",
                             "branco",
                             "branco",
                             "branco",
                             "branco"
                            };

void /*vector<int>*/ BuscaEmProfundidade(vector<vector<int>> grafo,int vertice){
    ListaDeStatus[vertice] = "cinza";
    for(int i = 0; i < 8; i++){
        if(grafo[i][vertice] == 1 && ListaDeStatus[i] == "branco"){
            cout << "Vértice " << vertice << "está conectado a " << i;
            BuscaEmProfundidade(grafo, i);
        }
    }
    ListaDeStatus[vertice] = "preto";
}

vector<int> BuscaEmLargura(vector<vector<int>>, int vertice){
    
}

int main(){
    BuscaEmProfundidade(grafo, 1);
}