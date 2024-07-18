#include <iostream>


using namespace std;

void imprime (int v[], int t, int p1, int p2, bool troca) {
	if (troca)
    { 
		for (int i = 0; i < t; i++)
        {
			if (i==p1 or i==p2)
				cout<<v[i]<<" t\t";
			else
				cout<<v[i]<<"\t";
		}
		
	}
    else 
    { //nao troca
		for (int i=0; i < t; i++)
        {
			if (i == p1 or i == p2)
				cout<< v[i] <<" *\t";
			else
				cout<< v[i] <<"\t";
        }
	}
	cout << endl;
}

void bubble(int v[], int tam) {

    for (int i = 0; i < tam-1; i++) {
        for (int j = 0; j < tam-1-i; j++) {
            if (v[j] > v[j+1])
            {
				imprime(v, tam, j, j+1, true);

               swap(v[j],v[j+1]);
            } 
            else 
				imprime(v, tam, j, j+1, false);
        }
    }
}

int main(){
    int tam, i;
    cin>>tam;
    
    int v[tam];
    for (i=0; i < tam; i++)
		cin >> v[i];
	
	bubble(v,tam); 
	imprime(v,tam,-1,-1,false);

    return 0;
}