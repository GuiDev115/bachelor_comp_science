#include <iostream>

using namespace std;

struct meme{
    int id;
    string nome;
    string assunto;
    string site;
};

void insertion_sort(meme vetor[], int tam){
    meme valor_pivo;
    
    int j, i;
    
    for (i = 1; i < tam; i++) {
        valor_pivo.assunto = vetor[i].assunto;
        valor_pivo.id = vetor[i].id;
        valor_pivo.nome = vetor[i].nome;
        valor_pivo.site = vetor[i].site;
        j = i - 1;
        while ((j >= 0) and (valor_pivo.id < vetor[j].id)){
            vetor[j+1].assunto = vetor[j].assunto;
            vetor[j+1].id = vetor[j].id;
			vetor[j+1].nome = vetor[j].nome;
            vetor[j+1].site = vetor[j].site;
            j--;
        }
        vetor[j+1].assunto = valor_pivo.assunto;
        vetor[j+1].id = valor_pivo.id;
        vetor[j+1].nome = valor_pivo.nome;
        vetor[j+1].site = valor_pivo.site;
    }

}

void exibe(meme mem[], int n1, string siten, bool testar){
    int i;

    for(i=0; i < n1; i++){
        if(siten == mem[i].site){
            cout << endl << mem[i].id << " " << mem[i].nome << " " << mem[i].assunto << " " << mem[i].site;
            testar = true;
        }
    }
    if(testar == false)
    cout << "Inexistente";
}

void cadastro(meme mem[], int n){
    int i;
        for(i=0; i < n; i++){
        cin >> mem[i].id;

        cin >> mem[i].nome;

        cin >> mem[i].assunto;

        cin >> mem[i].site;
        
    }
}

int main(){
    int n1, i;
    string n_site;
    bool teste = false;

    cin >> n1;

    meme mem[n1];

    cadastro(mem, n1);

    cin >> n_site;

    cout << endl;

    insertion_sort(mem, n1);

    exibe(mem, n1, n_site, teste);

    return 0;
}