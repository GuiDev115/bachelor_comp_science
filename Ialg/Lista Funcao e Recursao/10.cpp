#include <iostream>

using namespace std;

int tribonacci(int n1) {

    int soma = 0;

    if (n1 == 1)
        return 1;

    else if (n1 == 2)
        return 1;

    else if (n1 == 3)
        return 2;

    else
        return soma = tribonacci(n1 - 1) + tribonacci(n1 - 2) + tribonacci(n1 - 3);
}

int main()
{
    int serial, i = 1;

    cin >> serial;

    while (i <= serial) {
        cout << tribonacci(i) << " ";
        i++;
    }
}