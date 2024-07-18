#include <iostream>

using namespace std;

int fatorial (int n){
    int fat = 1;
    for(int i = 2; i <= n; i++)
    fat *= i;
    return fat;

}

int compara(char *v, int t){
    int i, j, contadorletra, total = 1, fat;
    for(i=0; i < t - 1; i++){
        contadorletra = 1;

        if (v[i] != ' '){
            for(j=i+1; j < t; j++) {

                if(v[i] == v[j]){
                    contadorletra++;
                    v[j] = ' ';
                }
            }
        }
        if (contadorletra > 1 ){
            fat = fatorial (contadorletra);
            total *= fat;
        }
    }
    return fatorial (t) / total;
}

int main(){
    string palavra;
    cin >> palavra;
    int tamanho = palavra.size();
    //cout << tamanho << endl;

    char *v = new char [tamanho];

    for(int i=0; i < tamanho; i++)
        v[i] = palavra[i];
    
    //for(int i=0; i < tamanho; i++)
      //  cout << *(v+1) << endl;

    cout << compara(v, tamanho);

    delete [] v;

    return 0;
}