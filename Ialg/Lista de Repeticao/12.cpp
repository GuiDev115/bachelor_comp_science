#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i = 0, n = 0;
    double aux = 0, pi, prod = 1, result;

    cin >> n;

    while (i != n)
    {
        pi = sqrt(2 + aux) / 2;
        aux = pi * 2;
        prod *= pi;
        i++;
    }
    result = 2 / prod;

    cout << result;
}