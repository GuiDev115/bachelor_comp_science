#include<stdio.h>
#include <iostream>

using namespace std;

int fibbonacci(int n) {

    int i, a, b, c;

    i = 1;
    a = 0;
    b = 1;

    while (i < n)
    {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
        i++;
    }

    return a;

}

int main()
{
    int n, i = 0;
    cin >> n;

    cout << fibbonacci(n) << " ";
    
    return 0;
}