#include <iostream>

struct empregado{
    int id, verif;
    float quant;
};

using namespace std;


int main(){
    float salario, salario_total;
    int  n1, i, j, lugar, id;
    int aux = 0, aux_01 = 0, aux_02 = 0;

    cin >> salario;
    
    empregado* job;

    cin >> n1;

    while(n1 > 0){
        
        aux++;
        int i = aux-1;

        empregado *new_Vetor = new empregado[aux];

        for(i=0; i<aux-1; i++)
        new_Vetor[i] = job[i];

        job = new_Vetor;
		
		job[i].id = n1;
		job[i].verif = 1;

        cin >> job[i].quant;
        cin >> n1;
    }

    cin >> id;

    cin >> lugar;

	for ( i=0; i<aux; i++ )
		if ( job[i].verif  == 1){

			salario_total = salario + job[i].quant*0.06;

			for ( j=i+1; j < aux; j++ )
				if ( job[j].id == job[i].id ){

					salario_total += job[j].quant*0.06;
					job[j].verif = 2;
				}
			
			cout << job[i].id << " " << salario_total << endl;
		}
	
	cout << endl;

	for ( i=0; i < aux and aux_02 < 3; i++ )
		if(job[i].id == id){
			if(aux_01 == lugar){
				cout << job[i].quant << " ";
				aux_02++;
				lugar++;
			}
			aux_01++;
		}
	
    delete[] job;

    return 0;
}