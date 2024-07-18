#include <iostream>

using namespace std;

int main(){
	int n, local, n1, n2, i;
	
	cin >> n;
	
	int vetor1[n], vetor2[n];
	
	for (i=0; i < n; i++)
		cin >> vetor1[i];
	
	
	for (i=0; i < n; i++)
		cin >> vetor2[i];
		
	cin >> local;
	
	for (i=0; i != local; i++)
		if (vetor1[i] == local)
			n1 = i;
			
	for (i=n; i > 0; i--)
		if (vetor2[i] == local)
			n2 = i;	

    cout << endl;
	
	for (i=n1; i <= n2; i++)
		cout << vetor1[i] << endl;
	
	for (i=n1; i <= n2; i++)
		cout << vetor2[i] << endl;
	

	return 0;
}