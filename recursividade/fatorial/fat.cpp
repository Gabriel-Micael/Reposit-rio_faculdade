#include <iostream>

using namespace std;

/*int fatorial(int n){
    if ( n < 0){
        return -1;
    }else{
        int fatorial(int n);{
            int fat = 1;
            while(n > 1){
                fat = fat * n;
                n--;
            }
            return fat;
        }
    }
}*/
int fatorial(int n){
    if(n < 2 && n >= 0){
        return 1;
    }else if( n >=2 ){
        return n * fatorial(n - 1);
    }else{
        return -1;
    }
}

int main(void){
    int n, ft;
    cout << "Cálculo fatorial ..." << endl;
    cout << "Digite um valor de n: ";
    cin >> n;
    ft = fatorial(n);
    if(ft == -1){
        cout << "Valor inválido" << endl;
    }else{
        cout << " O fatorial de " << n << " é ->" << ft << endl;
    }
}