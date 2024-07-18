#include <iostream>
#include <cmath>

using namespace std;

struct pessoas
{
    float salario;
    int idade;
    int filho; 
};


int main(){                     
    int  i, n;
    float salario_total = 0, salario_media, filho_total = 0, filho_media, salario_maior = 0, percentual, j = 0;
    cin >> n;

    pessoas pessoa[n];

    for (i = 0; i < n; i++){
        cin >> pessoa[i].salario;
        cin >> pessoa[i].idade >> pessoa[i].filho;
    }
    
    for (i = 0; i < n; i++)
        salario_total += pessoa[i].salario;

    salario_media = salario_total / n;

    for (i = 0; i < n; i++)
       filho_total += pessoa[i].filho;

    filho_media = filho_total / n;

    cout << endl << salario_media;
    cout << endl << filho_media;

    for (i = 0; i < n; i++){
        if(pessoa[i].salario > salario_maior){
            salario_maior = pessoa[i].salario;
        }
    }

    cout << endl << salario_maior;

    for (i = 0; i < n; i++){
        if(pessoa[i].salario > 1000)
            j++;
    }

    percentual = (j/n)*100;

    cout << endl << round(percentual) << "%";
    

    return 0;

}