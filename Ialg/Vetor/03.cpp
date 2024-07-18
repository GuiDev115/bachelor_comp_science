#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i , aux = 1;
    char vetor1[10], vetor2[10];
    
    for (i = 0; i < 10; i++)
		cin >> vetor1[i];

	
	for (i = 0; i < 10; i++)
		cin >> vetor2[i];
		
	cout << endl;
		
	for (i = 0; i < 5; i++){
		aux = 1 + (2*i);
		cout << vetor2[9 - i] << " " << vetor1[aux] << " ";

	}
	
	cout << endl;
	aux = 0;
	
	for (i = 0; i < 5; i++){
		
		cout << vetor2[i] << " ";
		
	}
	
	for (i = 0; i < 5; i++){
	aux = 8 - (2*i);
	cout << vetor1[aux] << " ";
	
}
	

}