#include <iostream>

using namespace std;

int soma(int n1, int n2)
{

    if (n2 == 0)
        return n2;
    else
        return n1 + soma(n1, n2 - 1);

}

int main()
{

    int n1;
    int n2;

    cin >> n1 >> n2;

    cout << soma(n1, n2);


}