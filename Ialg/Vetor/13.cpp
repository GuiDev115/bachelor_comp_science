#include <iostream>
#include <string>

using namespace std;

void funcao(int *hora, int *m, int minuto){

    *hora = minuto / 60;
    *m = minuto % 60;

}

int main(){

    int min;
    cin >> min;

    int h, m;

    funcao(&h, &m, min);
    cout << h << endl << m;

    return 0;

}