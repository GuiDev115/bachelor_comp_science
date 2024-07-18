#include <iostream>

using namespace std;

void insertion (int vetor[], int n1){
	
	int pivo, j, i;
	
	for(i=1; i < n1; i++){
		pivo = vetor[i];
		j = i-1;
		
		while(j >= 0 and pivo > vetor[j]){
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = pivo;
	}
}

int main(){
    int n1, n2;
    
    cin >> n1;
    
    int v[n1];

	for (int i=0; i < n1; i++){
		cin >> v[i];
	}
	
	cin >> n2;
	
	insertion(v, n1);

    cout << endl;

    int result = 0;
	
	for (int i=0; i < n2; i++)
		result += v[i];
	
	cout << result;

    return 0;
}