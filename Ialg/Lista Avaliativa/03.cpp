//Feito por: GUILHERME FABRICIO BRITO DA ROSA
//TURMA: 10A

#include <iostream>

using namespace std;

int main(){
    int X = 2 , Y = 2, Z = 3;
    int i, j, k, n1;
    bool parada = false;

    int*** matrix;

    matrix = new int**[X];
    for (int i=0; i<X; i++) {
        matrix[i] = new int*[Y];
        for (int j=0; j<Y; j++) {
            matrix[i][j] = new int[Z];
            for (int k=0; k<Z; k++) {
                matrix[i][j][k] = k;
                cin >> matrix[i][j][k];
            }
        }
    }

    cin >> n1;
    cout << endl;

    for (int i=0; i<X; i++){
        for (int j=0; j<Y; j++){
            for (int k=0; k<Z; k++){
                if(n1 == matrix[i][j][k]){
                    cout << i << " " << j << " " << k << endl;
                    parada = true;
                }
            }
        }
    }

    if(parada == false){
        cout << "-1";
    }

    else
    return 0;



} 