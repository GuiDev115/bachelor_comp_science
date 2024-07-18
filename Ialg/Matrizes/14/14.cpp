#include <iostream>

using namespace std;

int busca (int *v, int t, int num ){
    int meio, inicio = 0, fim = t-1;

    while (inicio <= fim){
        meio = (inicio + fim) / 2;

        if (v[meio] == num)
            return meio;

        if (v[meio] < num)
            inicio = meio + 1;
        else
            fim = meio;
    }

    return -1;
}

int main() {
    int n1, num;
    cin >> n1;

    int vet[n1];

    for(int i=0; i < n1; i++)
        cin >> vet[i];

    cin >> num;

    cout << busca(vet, n1, num);
}