//Feito por: GUILHERME FABRICIO BRITO DA ROSA
//TURMA: 10A

#include <iostream>

using namespace std;

struct aluno
{
  string nome;
  int id;
};


int main(){
  int n, x, i, posicao = -1, pos_inicial = 0, meio;

  cin >> n;

  int pos_final = n - 1;

  aluno *disc = new aluno[n];

  for ( i = 0; i < n; i++){
        cin >> disc[i].id;
        cin >> disc[i].nome;
    }

  cin >> x;

  while (pos_inicial <= pos_final) {
  	meio = (pos_inicial + pos_final)/2;
    cout << endl << disc[meio].id;
    
  	if (x == disc[meio].id){
     	posicao = meio; 
     	pos_inicial = pos_final + 1;
  	} 
    
    else{ 
     	if (x > disc[meio].id) 
        pos_inicial = meio + 1;

     	else 
        pos_final = meio - 1;
  	}
   }

  cout << endl << disc[posicao].nome;

  return 0;
}