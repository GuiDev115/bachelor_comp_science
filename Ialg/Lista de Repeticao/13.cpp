#include <iostream>
using namespace std;

int main()
{
    int quest, alternativa = 0, i = 0, x = 1, z = 0, aux = 0, result = 0;

    do {
        cin >> quest;
        while (z != quest)
        {
            alternativa = 0;
            i = 0;
            x = 1;
            aux = 0;
            result = 0;
            while (i != 5)
            {
                cin >> alternativa;
                if (alternativa > 127)
                {
                    alternativa = -1;
                    x++;
                }
                else if (alternativa <= 127 and alternativa >= 0 and aux == result)
                {
                    result = x;
                }
                else (result = -10);
                i++;
            }
            if (result == 1)
            {
                cout << "A" << endl;
            }
            else if (result == 2)
            {
                cout << "B" << endl;
            }
            else if (result == 3)
            {
                cout << "C" << endl;
            }
            else if (result == 4)
            {
                cout << "D" << endl;
            }
            else if (result == 5)
            {
                cout << "E" << endl;
            }
            else if (result == -10)
            {
                cout << "*" << endl;
            }
            z++;
        }
        z = 0;
    } while (quest != 0);
}