#include <iostream>
#include <string.h>

using namespace std;

int main()
{

    int vetor[20], i, k = 0, l = 0;

    for(i = 0; i < 20; i++)
        cin >> vetor[i];
    
    for(i = 0; i < 20; i++){
    if (vetor[i]%2 == 0)
        k++;
    

    else{
        l++;
    }
    }


    int vetor_par[k], vetor_impar[l];
    int k2 = 0;
    int l2 = 0;

    for(i = 0; i < 20; i++){
    if (vetor[i]%2 == 0){
        vetor_par[k2] = vetor[i];
        k2++;
    }
    else{
        vetor_impar[l2] = vetor[i];
        l2++;
    }
    }

    cout << endl;
        
    for(i = 0; i < k2; i++)
        cout << vetor_par[i] << " ";

    cout << endl;

    for(i = 0; i < l2; i++)
        cout << vetor_impar[i] << " ";

}
