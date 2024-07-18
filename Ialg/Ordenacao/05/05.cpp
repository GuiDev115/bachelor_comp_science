#include <iostream>

using namespace std;

struct funcionario {
	int id;
	float hora, valor, salario;
};

void bubble (funcionario vetor[], int n1){
    int i, j;
	
	for (i=0; i < n1-1; i++) {
		for (j=0; j < n1-1-i; j++) {
			if (vetor[j].salario > vetor[j+1].salario){
				swap(vetor[j], vetor[j+1]);
			}
		}
	}
}

void leitura (funcionario vetor[], int n1){
	for (int i=0; i< n1; i++){
		cin >> vetor[i].id;
		cin >> vetor[i].hora;
		cin >> vetor[i].valor;
		
		vetor[i].salario = vetor[i].hora * vetor[i].valor;
	}
}

int main(){
    int n1, i;
    string busca;
    
    cin >> n1;
    
    funcionario vetor[n1];
    
    leitura(vetor, n1);
    
    bubble(vetor, n1);

    cout << endl;
    
    for (i = 0; i < n1; i++){
			cout << vetor[i].id << " ";
			cout << vetor[i].salario << endl;
	}
	
    return 0;
}