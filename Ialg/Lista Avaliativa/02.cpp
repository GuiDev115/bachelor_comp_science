//Feito por: GUILHERME FABRICIO BRITO DA ROSA
//TURMA: 10A

#include <iostream>

using namespace std;

int main(){
    const int primo = 37, M = 15;
    long hash = 0;
    int n1, j, i;
    long hasht = 0;

    cin >> n1;
    string palavra[n1];

    for(i=0; i < n1; i++)
		  cin >> palavra[i];

    for(i=0; i < n1; i++){
      hash = 0;
      for (unsigned j = 0; j < palavra[i].length(); j++) 
         hash = (primo * hash + (int)palavra[i][j]) % M; 
         
      cout << hash << " ";
      hasht += hash;
      }
    cout << hasht;
    
}