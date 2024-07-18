#include <iostream>
#include <string>

using namespace std;

int main(){
    int dimensao = 10;
    int mat[dimensao][dimensao], i, j;
    
    for(i=0; i<dimensao; i++)
        for(j=0; j<dimensao; j++)
            cin >> mat[i][j];

    int linhaMaior = 0, maior = mat[0][0];
    for(i=0; i<dimensao; i++){
        for(j=0; j<dimensao; j++){
            if(mat[i][j] > maior){
                maior = mat[i][j];
                linhaMaior = i;
            }
        }
    }

    int menor = mat[linhaMaior][0], coluna = 0;
    for (j=1; j < dimensao; j++){
        if (mat[linhaMaior][j] < menor){
            menor = mat[linhaMaior][j];
            coluna=j;
        }
    }

    cout << menor << endl;
    cout << linhaMaior << " " << coluna; 


return 0;

}