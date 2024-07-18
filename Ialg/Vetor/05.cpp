#include <iostream>
#include <string>

using namespace std;

int main()
{
    string palavra;

    cin >> palavra;

    int result_vogal = 0, result_consoante = 0 ,i, size = palavra.size();

    for (i = 0; i < palavra.size(); i++) {

        if (palavra[i] == 'a' or palavra[i] == 'e' or palavra[i] == 'i' or palavra[i] == 'o' or palavra[i] == 'u')
            result_vogal++;
    }

    cout << result_vogal;

}
