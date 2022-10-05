#include <iostream>
#include <stdlib.h>

using namespace std;
int k = 0, j = 0;

void marge(int *a, int n1,  int *b, int n2, int *c, int n3){
        if(n3 <= n2 + n1){
            if(k < n2 && j < n1){    
                if(*a > *b){
                    *c = *b;
                    k++;
                    marge(a, n1, b + 1, n2, c + 1, n3);
                }else{
                    *c = *a;
                    j++;
                    marge(a + 1, n1, b , n2, c + 1, n3);
                }
            }else{
                if( k == n2 && j < n1){
                    *c = *a;
                    j++;
                    marge(a + 1, n1, b, n2, c + 1, n3);
                }else if( j == n1 && k < n2){
                    *c = *b;
                    k++;
                    marge(a, n1 , b + 1, n2, c + 1, n3);
                }
            }
        }
}

int main(void){
    int a[] = {2, 4, 6, 9};
    int b[] = {0, 1, 3, 5, 7, 8};
    int c[10];
    marge(a, 4, b , 6, c, 10);
    for(int i = 0; i < 10; i++){
        cout << "  " << c[i];
    }
    cout << endl;
}