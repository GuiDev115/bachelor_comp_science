#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int ehPerfeito(int n){
    int i, soma = 0;

    for(i = 1; i <= n/2; i++){
        if(n % i == 0)
            soma += i;
    }
    if(soma == n)
        return 1;
    else
        return 0;
}

void imprimeDivisores(int n){
    int i;

    for(i = 1; i < n; i++){
        if(n % i == 0)
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, quantidade = 0, perfeito, i = 1, validar;

    cin >> n;

    validar = ehPerfeito(n);

        if(validar == 1){
        imprimeDivisores(n);
            if(i % 50000 == 0)
                cout << i;
        }

        else{
            cout << "-1";
        }
    return 0;
}