#include <iostream>
using namespace std;

int remove ( string v[], int n1 ){

    int aux = 0, x = 0;

    for (int i = 0; i < n1; i++){
        if ( v[i] == v[i + 1] ){
            v[i] = "";
            aux++;
        }
    }

    for ( int i = 0; i < n1; i++){
        if ( v[i] != "" ){
            swap ( v[x], v[i] );
            x++;
        }
    }
    
    return (n1 - aux);
        
}

int main(){

    int n1, aux;

    cin >> n1;

    string v[n1];

    for ( int i = 0; i < n1; i++)
        cin >> v[i];

    cout << endl;

    cout << remove ( v, n1 ) << endl;

    aux = remove ( v, n1 );

    for ( int i = 0; i < aux; i++)
        cout << v[i] << endl;
    

}

