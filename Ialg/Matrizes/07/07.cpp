#include <iostream>

using namespace std;

int main(){

    int matriz[4][4];

    bool teste = false;

    for ( int i = 0; i < 4; i++)
    {
        int y = 0, x = 0;
        for ( int j = 0; j < 4; j++)
        {
            cin >> matriz[i][j];
            if (matriz[i][j] != 1 and matriz[i][j] != 0)
                teste = true;

            if (matriz[i][j] != 0)
                x++;
            
            
            if (matriz[i][j] == 0)
                y++;

            if (x > 1)
                teste = true;
            
            if (y > 3)
                teste = true;
            
        }
    }
    
    cout << endl;
            
    if ( teste == true )
        cout << "nao" << endl;
    else
        cout << "sim" << endl;
    
}