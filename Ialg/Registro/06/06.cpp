#include <iostream>

using namespace std;

struct aluno
{
    string  nome;
    int matricula;
    int nota; 
};


int main(){                     
    int n, i;
    float media_acumu = 0, media, fora_media = 0, porcent, nota_maior = 0;
    string nome_nota_maior;
    cin >> n;

    aluno discente[n];

    for (i = 0; i < n; i++){
        cin >> discente[i].matricula;
        cin >> discente[i].nome >> discente[i].nota;
    }


    for (i = 0; i < n; i++)
        media_acumu += discente[i].nota;
        
    media = media_acumu / n;

    cout << endl << media << endl;

    for (i = 0; i < n; i++){
        if(discente[i].nota == 0)
        cout << discente[i].matricula << endl;

        if(discente[i].nota < media)
        fora_media++;
        
    }

    porcent = (fora_media / n) * 100;

    cout << porcent << "%" << endl;
    
    for (i = 0; i < n; i++){
        if(discente[i].nota > nota_maior){
            nota_maior = discente[i].nota;
            nome_nota_maior = discente[i].nome;
        }
    }

    cout << nome_nota_maior;

    return 0;

}   