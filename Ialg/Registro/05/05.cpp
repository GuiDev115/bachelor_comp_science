#include <iostream>

using namespace std;

struct pessoa
{
    string  nome;
    int dia, mes, ano;
};


int main(){                     
    int n, i, dia1, mes1, ano1;
    cin >> n;

    pessoa pessoa[n];
    int dif_ano[n];

    for (i = 0; i < n; i++){
        cin >> pessoa[i].nome;
        cin >> pessoa[i].dia >> pessoa[i].mes >> pessoa[i].ano;
    }

    cin >> dia1 >> mes1 >> ano1;

    for (i = 0; i < n; i++)
        dif_ano[i] = ano1 - pessoa[i].ano;

    cout << endl;


    for (i = 0; i < n; i++){
        if(dif_ano[i] < 0)
        cout << pessoa[i].nome << ": " << dif_ano[i] << endl;

        else if(dif_ano[i] == 0 or dif_ano[i] == 1)
        cout << pessoa[i].nome << ": " << dif_ano[i] << " ano" <<endl;

        else
        cout << pessoa[i].nome << ": " << dif_ano[i] << " anos" <<endl;
    }

    return 0;

}