#include <iostream>

using namespace std;

struct pessoa
{
     string nome;
     char sexo;
     float tall, peso;
};


int main(){                     
    int n, i;
    int pesado = 0;
    string pessoa_pesada;
    cin >> n;   

    pessoa indiv[n];
    float imc[n];

    for (i = 0; i < n; i++){
        cin >> indiv[i].nome;
        cin >> indiv[i].sexo >> indiv[i].tall >> indiv[i].peso;
    }


    for (i = 0; i < n; i++){
        if(indiv[i].peso > pesado){
            pessoa_pesada = indiv[i].nome;
        }
    }

    cout << endl << pessoa_pesada << endl;

    for (i = 0; i < n; i++){
        if (indiv[i].sexo == 'H'){
            imc[i] = (72.7 * indiv[i].tall - 58) - indiv[i].peso;
        }
        else
        imc[i] = (62.1 * indiv[i].tall - 44.7) - indiv[i].peso;

    }

    for (i = 0; i < n; i++){
         if (imc[i] < 0)
         cout << indiv[i].nome << " " << imc[i] << endl;
     }

     for (i = 0; i < n; i++){
         if (imc[i] > 0)
         cout << indiv[i].nome << " " << imc[i] << endl;
     }

     

    return 0;

}