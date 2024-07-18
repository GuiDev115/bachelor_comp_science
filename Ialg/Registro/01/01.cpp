#include <iostream>

using namespace std;

struct carro
{
    string  nome;
    int ano;
    int preco; 
};


int main(){                     
    int n, i;
    int ref;
    cin >> n;

    carro veiculo[n];

    for (i = 0; i < n; i++){
        cin >> veiculo[i].nome;
        cin >> veiculo[i].ano >> veiculo[i].preco;
    }

    cin >> ref;


    for (i = 0; i < n; i++){
        if(veiculo[i].preco < ref){
        cout << veiculo[i].nome << " " << veiculo[i].ano << " " << veiculo[i].preco << endl;
        }
    }

    return 0;

}