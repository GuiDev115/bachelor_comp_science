#include <iostream>

using namespace std;

int busca (int vetor[], int end, int begin, int n2){
	int mid;
	
	if(begin <= end){	

		mid = (begin + end) / 2;
		
		cout << vetor[mid] << " ";

			if(vetor[mid]<n2)
				return busca (vetor, end, mid+1, n2);
			
			else if(vetor[mid]>n2)
				return busca (vetor, mid-1, begin, n2);

			else
				return mid;
	}

	return -1;
}

int main (){
	int n1, n2;
	
	cin >> n1;

	int vetor[n1];

	for(int i=0; i < n1; i++)
		cin >> vetor[i];

	cin >> n2;
	cout << endl;

	busca(vetor, n1-1, 0, n2);

	return 0;
}