#include <iostream>

using namespace std;

void preencher(int n, int **T) {

  int i,j;

  T[0][0] = 1;
  for (i = 1; i < n; i++) {
    T[i][0] = 1;
    T[i][i] = 1;
    for (j = 1; j < i; j++) {
      T[i][j] = T[i-1][j] + T[i-1][j-1];
    }
  }
}

void imprimir(int n, int **T) {
  int i,j;

  for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) {
      cout <<  T[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  int n1,i,**T;

  cin >> n1;

  T = (int **) malloc(n1*sizeof(int *));
  
  for (i = 0; i < n1; i++) 
    T[i] = (int *) malloc((i+1)*sizeof(int));

  preencher(n1,T);
  imprimir(n1,T);

  return 0;
}