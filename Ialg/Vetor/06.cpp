#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n, i, contarpalavra;

    cin >> n;

    string vetor[n];

    for (i = 0; i < n; i++)
        cin >> vetor[i];

    cout << endl;

    for (i = 0; i < n; i++)
        cout << vetor[i] << endl;

    for (i = 0; i < n; i++)
    cout << vetor[i].length() << endl;

	//cout << contarpalavra;

}	