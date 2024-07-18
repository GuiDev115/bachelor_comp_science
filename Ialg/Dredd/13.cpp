#include <iostream>

using namespace std;

bool teste (string p, string f, int &kek){

	int aux_frase = (int)f.size(), aux_palavra = (int) p.size();
	
	int teste[aux_palavra], c, i, j, z, k;
	bool x;

	if( aux_palavra > aux_frase )
		return false;
	
	
	for(i=0; i <= aux_frase - aux_palavra; i++){
		if(f[i]==p[0]){
			kek=i;
			for(j=0; j < aux_palavra; j++)
				teste[j]=0;
			
			c=i;

			for(k=0; k < aux_palavra; k++)
				if(p[k]==f[c]){
					teste[k]=1;
					c++;
				}
			
			x=true;

			for(z=0; z < aux_palavra; z++){
				if(teste[z]==0){
					x=false;
				}
			}

			if(x){
				return true;
			}
        }
    }
    return false;
}

int main(){
	string n1, n2;
	int kek=0;

	cin >> n1 >> n2;

	cout << endl;
	
	if( teste (n2,n1,kek) )
		cout << kek;
	
	else
		cout << "-1";
	
	return 0;
}