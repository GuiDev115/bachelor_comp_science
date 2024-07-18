#include <iostream>
using namespace std;

int BuscaBinaria(int V[], int pos_inicial, int pos_final, int K) {
   int meio = (pos_inicial + pos_final)/2;
   
   if (K == V[meio]) { 
  	return meio;
   }
   else if (pos_inicial > pos_final) { 
  	if (V[meio] < K) 
     
      return BuscaBinaria(V, meio-1, pos_final, K);

  	else 
       return BuscaBinaria(V, pos_inicial, meio+1, K);
   } 
   
   else 
  	return -1;
   
}


int main() {
   int K, N;
   cin >> N;
   int V[N];
   
   for (int i = 0; i < N; i++) 
    cin >> V[i];

   cin >> K;

   cout << endl;

   cout << BuscaBinaria(V, N-1, 0, K) << endl;
   return 0;
}

