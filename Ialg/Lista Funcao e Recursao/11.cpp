#include<iostream>
using namespace std;

int fibo(int num, int no1, int no2)
{

    int soma = 0;

    if (num == 1)
        return no1;
    else if (num == 2)
        return no2;
    else
        return soma = fibo(num - 1, no1, no2) + fibo(num - 2, no1, no2);


}

int main()
{

    int n1, n2, num = 1, i = 1;

    cin >> n1 >> n2;
    cin >> num;

    while (i <= num)
    {
        cout << fibo(i, n1, n2) << " ";
        i++;
    }

}