#include <iostream>

using namespace std;

int main(){
	
	int i, j, n1, orig, dest;

	float mat[4][4], dist;
	
	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
			cin >> mat[i][j];
	
	cin >> n1;
	
	int v[n1];
	
	for (i=0; i<n1; i++)
		cin >> v[i];

	for (i=0; i< n1 - 1; i++ ){
		orig = v[i];
		dest = v[i+1];
		dist += + mat[orig][dest];
	}

	cout << endl;
	cout << dist;
	
}