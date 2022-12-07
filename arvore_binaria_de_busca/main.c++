#include <iostream>
#include "arvore.h"

using namespace std;

int main(){
   tNode * raiz;
   insere(raiz,2);
   insere(raiz,1);
   insere(raiz,3);
   imprime_in_ordem(raiz);
}
