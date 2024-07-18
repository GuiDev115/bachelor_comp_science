#include <iostream>

using namespace std;

void select(int vet[], int n1){

    int i, maior, j;

    for(i=0; i<n1-1; i++){
        maior = i;

        for(j=i+1; j <n1; j++)
            if(vet[maior] < vet[j])
            maior = j;

            swap (vet[maior], vet[i]);

            for(int i=0; i<n1; i++){
                cout << vet[i]<<" ";
            }
            cout << endl;
    }
}

int main(){
    int n1;
    
    cin >> n1;

    int vet[n1];

    for(int i=0; i < n1; i++){
        cin >> vet[i];
    }

    select(vet, n1);

    return 0;
}