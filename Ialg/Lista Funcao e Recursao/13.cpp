#include <iostream>

using namespace std;


int f(int n1) {

    int h(int n1);

    if (n1 > 0 && n1 % 2 == 0) {

        return 2 * h(n1) + f(n1 - 1);

    }

    else if (n1 > 0 && n1 % 2 != 0) {

        return 2 * h(n1) - f(n1 - 1);

    }

    else
        return 1;


}


int h(int n1) {

    if (n1 > 0) {

        return h(n1 - 1) + f(n1 - 1);

    }

    else
        return 0;

}



int main()
{
    int n;

    cin >> n;

    cout << f(n);

}

