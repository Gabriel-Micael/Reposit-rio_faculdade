#include <iostream>
#include <stdlib.h>

using namespace std;
int i = 0, j = 0,k = 0;

void marge(int *a, int n1,  int *b, int n2, int *c, int n3){
    if(i < n3){
        if(k < n2 && j < n1){    
            if(*a > *b){
                *c = *b;
                i++;
                k++;
                marge(a, n1, b + 1, n2, c + 1, n3);
            }else{
                *c = *a;
                i++;
                j++;
                marge(a + 1, n1, b , n2, c + 1, n3);
            }
        }else{
            if( k == n2 && j < n1){
                *c = *a;
                j++;
                i++;
                marge(a + 1, n1, b, n2, c + 1, n3);
            }else if( j == n1 && k < n2){
                *c = *b;
                k++;
                i++;
                marge(a, n1 , b + 1, n2, c + 1, n3);
            }
        }
    }
}

int main(void){
    int a[] = {9, 4, 3, 6};
    int b[] = {5, 1, 2, 7, 8, 0};
    int c[10];
    marge(a, 4, b , 6, c, 10);
    for(int i = 0; i < 10; i++){
        cout << "  " << c[i];
    }
    cout << endl;
}