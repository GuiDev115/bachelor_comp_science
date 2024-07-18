#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct registro{
    int numero;
    int quant = 0;
};

void batalha_naval(int **mat1, int **mat2, int n1){
    vector <registro> num;
    bool achei = false;
    int derrotados =0;

    for(int i=0;i<n1;i++){
        for(int j=0;j<n1;j++){
            if(mat1[i][j] > 0){
                for(int k=0;k<(int)num.size();k++){ 
                    if(num[k].numero == mat1[i][j]){
                        achei = true;
                        num[k].quant++;
                    }
                }
                if(achei == false){
                    num.resize((int)num.size() + 1);
                    num[(int)num.size() -1].numero = mat1[i][j];
                    num[(int)num.size() -1].quant++;
                }
                achei = false;
            }
            if(mat2[i][j]==1){
                if(mat1[i][j]>0){
                    for(int x=0;x<(int)num.size();x++){
                        if(num[x].numero == mat1[i][j]){
                            num[x].quant--;
                        }
                    }
                }
            }
        }
    }

    for(int i=0;i<(int)num.size();i++){
        if(num[i].quant == 0){
            derrotados++;
        }
    }

    cout << derrotados << endl;
}

int main(){
    string nome_arquivo = "BatalhaNaval.txt";
    int n1;

    ifstream arquivo(nome_arquivo);
    arquivo >> n1;

    int **mat1 = new int*[n1];
    int **mat2 = new int*[n1];

    for(int i=0;i<n1;i++){
        mat1[i] = new int[n1];
        mat2[i] = new int[n1];
    }

    int i=0, k=0;
    for(i=0;i<n1;i++){
        for(k=0;k<n1;k++){
            arquivo >> mat1[i][k];
        }
    }
    for(i=0;i<n1;i++){
        for(k=0;k<n1;k++){
            arquivo >> mat2[i][k];
        }
    }

    batalha_naval(mat1,mat2,n1);

    for(i=0;i<n1;i++){
        delete[]mat1[i];
        delete[]mat2[i];
    }
    delete[]mat1;
    delete[]mat2;

    return 0;
}