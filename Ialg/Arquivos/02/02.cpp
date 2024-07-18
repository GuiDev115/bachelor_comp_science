#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string nome;
	
	cin >> nome;
	
	ifstream arquivo(nome);
	
	if (arquivo) {
		string conteudo;
		
		arquivo >> conteudo;
		
		cout << conteudo;
		
		arquivo.close();
	}

  return 0;
}