#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    int numero, invertido;
    int primeiro, ultimo, digitos;

    cin >> numero;

    ultimo = numero % 10;
    digitos = log10(numero);
    primeiro = numero / pow(10, digitos);

    invertido = ultimo;
    invertido = invertido * pow(10, digitos);
    invertido = invertido + numero % ((int)pow(10, digitos));
    invertido = invertido - ultimo;
    invertido = invertido + primeiro;

    cout << invertido << endl;
}