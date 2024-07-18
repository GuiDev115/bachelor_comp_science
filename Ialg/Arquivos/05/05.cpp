#include <iostream>
#include <fstream>

using namespace std;

string code(string content){
	int n2 = content.length(), letraId;
	char letra;
	
	for(int i=0; i < n2; i++){
		if(content[i] != ' '){
			if (content[i] == 'X'){
				content[i] = 'A';
			}
            else if (content[i] == 'Y'){
				content[i] = 'B';
			}
            else if (content[i] == 'Z'){
				content[i] = 'C';
			}
            else{
				letraId = content[i];
				letraId += 3;
				letra = letraId;
				content[i] = letra;
			}
		}
	}
	return content;
	
}

int main(){
	string n1, content;
	
	cin >> n1;
	
	ifstream arquivo(n1);
	
	ofstream saida("cifrado");
	
	while (getline(arquivo, content))
		saida << code(content) << endl;
	
	
	arquivo.close();
	saida.close();

	return 0;
}