#include <iostream>

using namespace std;

struct produto{
    int id;
    string nome;
    float preco;
};

void insertion_sort(produto vetor[], int tam){
    produto valor_pivo;
    
    int j;
    
    for (int i = 1; i < tam; i++) {
        valor_pivo.preco = vetor[i].preco;
        valor_pivo.id = vetor[i].id;
        valor_pivo.nome = vetor[i].nome;
        j = i - 1;
        while ((j >= 0) and (valor_pivo.preco < vetor[j].preco)){
            vetor[j+1].preco = vetor[j].preco;
            vetor[j+1].id = vetor[j].id;
			vetor[j+1].nome = vetor[j].nome;
            j--;
        }
        vetor[j+1].preco = valor_pivo.preco;
        vetor[j+1].id = valor_pivo.id;
        vetor[j+1].nome = valor_pivo.nome;
    }

}


int main(){
    int n1, i;
    float lim_inf, lim_sup;
    bool teste = false;

    cin >> n1;

    produto prod[n1];

    for(i=0; i < n1; i++){
        cin >> prod[i].id;
        cin.ignore();
        getline(cin, prod[i].nome);
        
        cin >> prod[i].preco;
    }

    cin >> lim_inf;
    cin >> lim_sup;

    cout << endl;
    
    insertion_sort(prod, n1);
    

    for(i=0; i < n1; i++){
		if(prod[i].preco >= lim_inf and prod[i].preco <= lim_sup){
        cout << endl << prod[i].id << " " << '"' << prod[i].nome << '"' <<" " << prod[i].preco;
        teste = true; 
	}
    }
    
    if(teste == false)
    cout << "Inexistente";
    
    return 0;

		
}