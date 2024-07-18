#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (){
	string nome, frase;
	
	cin >> nome >> frase;
	
	ofstream arquivo(nome);
	
	arquivo << frase << endl;
	
	arquivo.close();
	
	return 0;
	}