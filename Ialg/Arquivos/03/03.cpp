#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    string nomeArquivo;
    int posArquivo;
    
    cin >> nomeArquivo >> posArquivo;
    
    ifstream entrada(nomeArquivo);
    
    char ctr;
    
    entrada.seekg(posArquivo);
    
    entrada >> ctr;
    cout << ctr;
    
    int caracteres = 0, palavras = 0;
    
    entrada.close();
    entrada.open(nomeArquivo);
    
    while ( entrada.get(ctr) ) {
        caracteres++;
    }
    
    entrada.close();
    entrada.open(nomeArquivo);
    
    string plr;
    
    while ( entrada >> plr ) {
        palavras++;
    }
    
    ofstream saida("resultado.txt");
    
    saida << caracteres << " " << palavras << endl;
    
    entrada.close();
    saida.close();
    
    return 0;
}