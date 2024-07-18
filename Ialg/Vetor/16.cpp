#include <iostream>
using namespace std;

int fatorial (int n){
    if ( n == 0 or n == 1)
        return 1;
    else
        return n * fatorial ( n - 1 );
}

void pega_vetor(float *n1 , float i){
    *n1 = ((2 * fatorial (i)) + i ) / ((i * i) + 1.75);
}

int main(){
    int m , n, tam;
    float n1;

    cin >> m >> n;

    tam = m - n;

    float *v = new float[m];

    for ( int i = 0; i < m; i++){
        pega_vetor (&n1, i);
        v[i] = n1;
    }

    for ( int i = 0; i < tam; i++){
        cout << v[n] << endl;
        n++;
    }
    return 0;
}




