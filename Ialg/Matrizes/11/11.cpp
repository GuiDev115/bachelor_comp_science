#include <iostream>

using namespace std;

int operacao(int vetor[], int tam, int busca, int &cont) {   

	int inicio=0, meio, fim=tam-1;
	  
	while (inicio <= fim ) {
		meio = (inicio + fim )/2;
		cont++;
		
		if (vetor[meio] == busca){
			return meio;
		} else{ 
			if (vetor[meio] < busca){ 
				inicio = meio+1;
			}else{ 
				fim = meio;
			}
		}
	}
	return -1;

}


int main (){
	int n1, busca, contador=0;
	
	cin >> n1;
	
	int vetor[n1];
	
	for (int i=0; i < n1; i++){
		cin >> vetor[i];
	}
	
	cin >> busca;
	
	cout << operacao(vetor, n1, busca, contador) << endl;
	cout <<  contador << endl;
	
	return 0;
}