#include <iostream>

using namespace std;
int ult = 1, penult = 0;
void fibonacci(int n, int ult, int penult){
    cout << ult << "  ";
    if(ult + penult < n){
        fibonacci(n, ult+penult, ult);
    }
}

int main(){
    int n;
    cout << "Cálculo Sequência de Fibonacci ..." << endl;
    cout << "Digite um valor de n: ";
    cin >> n;
    cout << "Seguencia ->";
    fibonacci(n, ult, penult);
}