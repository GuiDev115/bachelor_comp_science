#include <iostream>
#include <string>

using namespace std;

int main()
{
    int  i, ler, inserir, passar_vetor, x = 9, x2 = 8;
    int vetor[10] = {0};

    cin >> ler;

    for (i = 0; i < ler; i++)
    cin >> vetor[i];

    cin >> inserir; 

    cin >> passar_vetor;

    for (i = 0; i != 10 - (passar_vetor + 1); i++){
    swap (vetor[x], vetor[x2]);
    x--; x2--;
    }

    vetor[passar_vetor] = inserir;

    for (i = 0; i < 10; i++)
    cout << vetor[i] << " ";    
}