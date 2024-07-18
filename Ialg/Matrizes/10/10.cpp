#include <iostream>

using namespace std;

int binaria(int vetor[], int n1, int busca, int &c, int troca) {   

	int inicio=0, meio, fim=n1-1;
	  
	while (inicio <= fim) {
		meio = (inicio + fim)/2;
		c++;
		
		if (vetor[meio] == busca){
			vetor[meio] = troca;
			return meio;
		} 
        
        else{ 
			if (vetor[meio] < busca)
				inicio = meio+1;
                
			else{ 
				fim = meio;
			}
		}
	}
	return -1;
}


int main (){
	int n1, busca, k=0, troca;
	
	cin >> n1;
	
	int vetor[n1];
	
	for (int i=0; i < n1; i++)
		cin >> vetor[i];
	
	
	cin >> busca >> troca;
	
	binaria (vetor, n1, busca, k, troca);
	
	for (int i=0; i < n1; i++)
		cout << vetor[i] << " ";

	cout << endl;
	cout << k << endl;
	
	return 0;
}