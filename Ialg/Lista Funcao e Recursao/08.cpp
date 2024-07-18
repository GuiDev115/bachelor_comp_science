#include <iostream>

using namespace std;

float calculo(float n1) {
    float i = 0, result = 0, result01 = 0;

    while (i <= n1) {

        result = i * (i + 1) / (i + 3);

        result01 = result01 + result;

        i++;

    }

    return result01;


}

int main()
{
    float parcela;

    cin >> parcela;

    cout << calculo(parcela);
}