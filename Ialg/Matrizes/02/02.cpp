#include <iostream>
#include <string>

using namespace std;

int main(){

    int dimensao;
    cin >> dimensao;

    int mat[dimensao][dimensao], i, j;

    for (i = 0; i<dimensao; i++)
        for (j = 0; j<dimensao; j++)
        cin >> mat[i][j];  

    int soma = 0;

    for (i = 0; i<dimensao; i++){
        for (j = 0; j<dimensao; j++){
            if(i+j >= dimensao){
                cout << mat[i][j] << " ";
                soma += mat[i][j];
            }
        }
    }


    cout << endl << soma << endl;

    return 0;
}