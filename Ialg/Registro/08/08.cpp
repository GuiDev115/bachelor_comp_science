#include <iostream>

using namespace std;

struct carta
{
    string  nome;
    string brinquedo;
};

struct brinquedos{
    string nome_brinquedo;
    int quantidade;
    int necessario;
};


int main(){                     
    int n,n2, i;

    cin >> n;

    carta cartinha[n];

    for (i = 0; i < n; i++){
        cin >> cartinha[i].nome;
        cin >> cartinha[i].brinquedo;
    }

    cin >> n2;

    brinquedos brinde[n];

    for (i = 0; i < n2; i++){
        cin >> brinde[i].nome_brinquedo;
        cin >> brinde[i].quantidade;
        brinde[i].necessario = 0;
    }

    for (i = 0; i < n; i++){
        int quant = 0;
            while ((quant < n2) and (brinde[quant].nome_brinquedo != cartinha[i].brinquedo)){
			quant++;
    }

    		if (brinde[quant].nome_brinquedo == cartinha[i].brinquedo){
			brinde[quant].necessario++;
		}
	}

    	
	for (i=0; i < n2; i++){
		if (brinde[i].quantidade < brinde[i].necessario){
			cout << brinde[i].nome_brinquedo << " ";
		}
	}
    return 0;

}