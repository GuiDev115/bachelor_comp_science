#include <iostream>
#include <cmath>

using namespace std;

struct clientela {
	string nome;
	float x, y, valor, distancia;
};

void insertion(clientela list[], int total){
	
	clientela pivo;
	int j, i;
	
	for(i=1; i < total; i++){
		pivo = list[i];
		j = i-1;
		
		while(pivo.distancia < list[j].distancia and j >= 0){
			list[j+1] = list[j];
			j--;
		}

		list[j+1] = pivo;
	}
}

int main(){
    int n1, total;
    float xP, yP, result=0;
    
    cin >> n1 >> xP >> yP >> total;
    
    clientela lista[total];
    
    for (int i=0; i < total; i++){
		cin >> lista[i].nome;
		cin >> lista[i].x;
		cin >> lista[i].y;
		cin >> lista[i].valor;
	}
	
	for (int i=0; i < total; i++)
		lista[i].distancia = sqrt(pow((xP - lista[i].x),2) + pow((yP - lista[i].y),2)); //pitagoras

	insertion(lista, total);
	
	 for (int i=0; i < n1; i++)
		result += lista[i].valor;

    cout << endl;
	
	cout << result << endl;

    return 0;
}