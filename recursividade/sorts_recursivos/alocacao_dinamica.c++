#include <iostream>

using namespace std;

int* inicializa(int tam){
    int *v = (int *)malloc(tam * sizeof(int));
    int *p;
    srand(time(NULL));
    for(p = v; p < v + tam; p++){
        *p = rand() % 100;
    }
    return v;
}


int main(void){
    int *v = inicializa(10);
    for(int *p = v; p < v + 10; p++){
        cout << "  " << *p;
    }
    free(v);
}