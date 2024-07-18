#include <iostream>
#include <fstream>

using namespace std;

int main(){
	string n1 = "numeros";
	ifstream arquivo(n1); 
	
	ofstream par("pares");
	ofstream impar("impares");
	
	int n2;

	while (arquivo >> n2){
		if (n2 % 2 == 0)
			par << n2 << " ";
		
        else
			impar << n2 << " ";
		
	}
    
	arquivo.close();
	par.close();
	impar.close();

	return 0;
}