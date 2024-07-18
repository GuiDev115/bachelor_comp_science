#include <iostream>

using namespace std;

void lista(int n, int repeat[]) {

    int i;

    cout << "[";

    for (i = 0; i < n; i++) {

        if (i == n - 1)
            cout << repeat[i];

        else
            cout << repeat[i] << ", ";
    }

    cout << "]" << endl;
}

int main()
{
    int i, n;

    cin >> n;

    int lido[n];

    for (i = 0; i < n; i++)
        cin >> lido[i];


    lista(n, lido);

    return 0;

}
