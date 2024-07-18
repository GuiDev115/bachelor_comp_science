#include <fstream>
#include <iostream>

using namespace std;

float *expande(float *vetor, int &tam){
    float *novo = new float[tam+1];

    for(int i=0;i<tam;i++) 
        novo[i] = vetor[i];

    tam++;

    return novo;

}

float *preencher(string nome,float *valores, int &tam){
    float aux;
    int i=0;

    ifstream arquivo(nome);

    while(arquivo >> aux){ 
        valores = expande(valores,tam);
        
        valores[i]=aux;
        i++;
    }

    arquivo.close();

    return valores;

}

int main(){
    string nome_arquivo;
    float *valores = NULL;
    int tam = 0, i, j;

    cin >> nome_arquivo;

    valores = preencher(nome_arquivo,valores,tam);

    if(tam %2 == 0){
        for(i=tam-1, j=tam-2; j>-1; i-=2, j-=2)
            cout << (valores[i]+valores[j])/2 << " ";
        
    }
    
    else{
        cout << valores[tam-1] << " ";
        for( i=tam-2, j=tam-3;j>-1;i-=2,j-=2)
            cout << (valores[i]+valores[j])/2 << " ";
        
    }

    return 0;
}