#include <iostream>
#include "ordenaçao.h"

using namespace std;

void imprimevetor(int *v){
    for(int *p = v; p < v + 10; p++){
        cout << "  " << *p;
    }
    cout << endl;
}


int main(void){
    int v1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[10] = { 5, 8 ,2, 0, 6, 9, 1, 4, 3, 7};
    int v3[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << "Bubble Sort: vetor ordenado:"<<endl;
    imprimevetor(v1);
    insertion_sort(v1);
    imprimevetor(v1);

    cout << "Bubble Sort: vetor desordenado:"<<endl;
    imprimevetor(v2);
    insertion_sort(v2);
    imprimevetor(v2);

    cout << "Bubble Sort: vetor inversamente desordenado:"<<endl;
    imprimevetor(v3);
    insertion_sort(v3);
    imprimevetor(v3);

    int v4[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v5[10] = { 5, 8 ,2, 0, 6, 9, 1, 4, 3, 7};
    int v6[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << endl <<"Insertion Sort: vetor ordenado:"<<endl;
    imprimevetor(v4);
    insertion_sort(v4);
    imprimevetor(v4);

    cout << "Insertion Sort: vetor desordenado:"<<endl;
    imprimevetor(v5);
    insertion_sort(v5);
    imprimevetor(v5);

    cout << "Insertion Sort: vetor inversamente desordenado:"<<endl;
    imprimevetor(v6);
    insertion_sort(v6);
    imprimevetor(v6);

    int v7[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v8[10] = { 5, 8 ,2, 0, 6, 9, 1, 4, 3, 7};
    int v9[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << endl << "Seletion Sort: vetor ordenado:"<<endl;
    imprimevetor(v7);
    selection_sort(v7);
    imprimevetor(v7);

    cout << "Seletion Sort: vetor desordenado:"<<endl;
    imprimevetor(v8);
    selection_sort(v8);
    imprimevetor(v8);

    cout << "Seletion Sort: vetor inversamente desordenado:"<<endl;
    imprimevetor(v9);
    selection_sort(v9);
    imprimevetor(v9);
}