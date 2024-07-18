//Feito por: GUILHERME FABRICIO BRITO DA ROSA
//TURMA: 10A

#include <iostream>

using namespace std;

int main(){
    int n, i, j;

    cin >> n;

    string mat[n][n], sub[2][2];

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
        cin >> mat[i][j];
    }
    
    cout << endl;
    
       for(i=0; i < n-1; i++){
            for(j=0; j < n-1; j++){
                if ((mat[i][j] == "A" or mat[i][j] == "E" or mat[i][j] == "I" or mat[i][j] == "O" or mat[i][j] == "U") and 
                    (mat[i][j+1] == "A" or mat[i][j+1] == "E" or mat[i][j+1] == "I" or mat[i][j+1] == "O" or mat[i][j+1] == "U") and
                    (mat[i+1][j] == "A" or mat[i+1][j] == "E" or mat[i+1][j] == "I" or mat[i+1][j] == "O" or mat[i+1][j] == "U") and
                    (mat[i+1][j+1] == "A" or mat[i+1][j+1] == "E" or mat[i+1][j+1] == "I" or mat[i+1][j+1] == "O" or mat[i+1][j+1] == "U")){
                        
                        sub[0][0] = mat[i][j];
                        sub[0][1] = mat[i][j+1];
                        sub[1][0] = mat[i+1][j];
                        sub[1][1] = mat[i+1][j+1];
                }
            }
        }

    if(sub[0][0] == "A" or sub[0][0] == "E" or sub[0][0] == "I" or sub[0][0] == "O" or sub[0][0] == "U"){

    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++)
            cout << sub[i][j] << " ";

        cout << endl;
        }
    }

    else
    cout << "submatriz nao encontrada";

    
}