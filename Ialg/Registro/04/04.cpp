#include <iostream>
#include <string.h>

using namespace std;

struct tipo_carga
{
    string  carga;
    int disparo; 
};

struct arma{
    string carga2;
    string nome;
};


int main(){                     
    int n,n2, i, total = 0, sequen = 0, j;

    cin >> n;

    tipo_carga tiao[n];
    for (i = 0; i < n; i++){
        cin >> tiao[i].carga >> tiao[i].disparo;
    }

    cin >> n2;

    arma tiao2[n2];
    for (i = 0; i < n2; i++){
        cin >> tiao2[i].carga2 >> tiao2[i].nome;
    }

    for (j = 0; j < n2; j++){
    for (i = 0; i < n; i++){
        if(tiao2[sequen].nome == tiao[i].carga)
            total += tiao[i].disparo;
    }
    sequen++;
    }

    cout << endl << total;

    return 0;

}