#include <iostream>
using namespace std;

int removedor ( string vetor[], int q )
{

    int count = 0;
    int k = 0;

    for (int i = 0; i < q; i++)
        if ( vetor[i] == vetor[i + 1] )
        {
            vetor[i] = "";
            count++;
        }

    for ( int i = 0; i < q; i++)
        if ( vetor[i] != "" )
        {
            swap ( vetor[k], vetor[i] );
            k++;
        }
    
    return (q - count);
        
}   

int main()
{

    int q = 0;
    int removido = 0;

    cin >> q;

    string vetor[q];

    for ( int i = 0; i < q; i++)
        cin >> vetor[i];

    cout << removedor ( vetor, q ) << endl;

    removido = removedor ( vetor, q );

    for ( int i = 0; i < removido - 1; i++)
        cout << vetor[i] << endl;
    

}

