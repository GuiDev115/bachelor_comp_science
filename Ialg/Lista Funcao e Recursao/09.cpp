#include <iostream>

int fatorial(int n) {

    if (n == 1)
        return 1;

    else if (n == 2)
        return 2;

    else if (n == 0)
        return 1;

    else
        return n * fatorial(n - 2);


}

using namespace std;

int main()
{
    int n;

    cin >> n;

    cout << fatorial(n);
}