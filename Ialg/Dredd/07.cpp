#include <iostream>

struct emprego{
    int id;
    int verificador;
    float quantidade;
};

using namespace std;


int main(){
    float s, s_total;
    int  n1, n2, n3,i, j, aux = 0, medir01 = 0, medir02 = 0;

    cin >> s;
    
    emprego* trab;

    cin >> n1;

    while(n1 > 0){
        
        aux++;
        int i = aux-1;

        emprego *vet = new emprego[aux];

        for(i=0; i<aux-1; i++)
        vet[i] = trab[i];

        trab = vet;
		
		trab[i].id = n1;
		trab[i].verificador = 1;

        cin >> trab[i].quantidade;
        cin >> n1;
    }

    cin >> n2;

    cin >> n3;

	for ( i=0; i<aux; i++ )
		if ( trab[i].verificador  == 1){

			s_total = s + trab[i].quantidade*0.06;

			for ( j=i+1; j < aux; j++ )
				if ( trab[j].id == trab[i].id ){

					s_total += trab[j].quantidade*0.06;
					trab[j].verificador = 2;
				}
			
			cout << trab[i].id << " " << s_total << endl;
		}
	
	cout << endl;

	for ( i=0; i < aux and medir02 < 3; i++ )
		if(trab[i].id == n2){
			if(medir01 == n3){
				cout << trab[i].quantidade << " ";
				medir02++;
				n3++;
			}
			medir01++;
		}
	
    delete[] trab;

    return 0;
}