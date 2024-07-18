#include <iostream>
using namespace std;

int main()
{
    char vetor[8], matriz[10][8];
    int i, j;
    float result = 0, porcento, aprovado = 0;

    for (i = 0; i < 8; i++)
        cin >> vetor[i];
	
	for (i = 0; i < 10; i++ )
		for (j = 0; j < 8; j++ )
			cin >> matriz[i][j];

    for (i = 0; i < 10; i++){

		for (j = 0; j < 8; j++){

			if (vetor[j] == matriz[i][j])
                result++;
        }

        porcento = ( result / 8 ) * 100;

        cout << porcento << endl;

        if ( porcento > 60 )
            aprovado++;
        
        porcento = 0;
        result = 0;
    }

    aprovado = (aprovado /10) *100;
    
    cout << endl;
    cout << aprovado;

}