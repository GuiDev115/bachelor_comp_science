#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

int main ( ){
	int i, j;
	char matriz[3][3];
	
	for(i=0; i < 3; i++)
        for(j=0; j < 3; j++)
            cin >> matriz[i][j];

			if((matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2] && matriz[0][0] != 'X')||
			   (matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] != 'X')||
			   (matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0] && matriz[0][0] != 'X')||
			   (matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1] && matriz[0][1] != 'X')||
			   (matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2] && matriz[0][2] != 'X')||
			   (matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2] && matriz[1][0] != 'X')||
			   (matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2] && matriz[2][0] != 'X')||
			   (matriz[2][0] == matriz[1][1] && matriz[2][0] == matriz[0][2] && matriz[2][0] != 'X')){
					
				cout << endl << "O" << endl;

                if(matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2] && matriz[0][0] != 'X')
                    cout << "0 0" << endl << "1 0" << endl << "2 0";
                
                else if((matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] != 'X'))
                    cout << "0 0" << endl << "1 1" << endl << "2 2";

                else if((matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0] && matriz[0][0] != 'X'))
                    cout << "0 0" << endl << "1 0" << endl << "2 0";

                else if((matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1] && matriz[0][1] != 'X'))
                    cout << "0 1" << endl << "1 1" << endl << "2 1";

                else if((matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2] && matriz[0][2] != 'X'))
                    cout << "0 2" << endl << "1 2" << endl << "0 2";

                else if((matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2] && matriz[1][0] != 'X'))
                    cout << "1 0" << endl << "1 1" << endl << "1 2";

                else if((matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2] && matriz[2][0] != 'X'))
                    cout << "2 0" << endl << "2 1" << endl << "2 0";
                
                else
                    cout << "2 0" << endl << "1 1" << endl << "2 0";
               } 
			

            else if((matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2] && matriz[0][0] != 'O')||
			   (matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] != 'O')||
			   (matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0] && matriz[0][0] != 'O')||
			   (matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1] && matriz[0][1] != 'O')||
			   (matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2] && matriz[0][2] != 'O')||
			   (matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2] && matriz[1][0] != 'O')||
			   (matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2] && matriz[2][0] != 'O')||
			   (matriz[2][0] == matriz[1][1] && matriz[2][0] == matriz[0][2] && matriz[2][0] != 'O')){
					
				cout << endl << "X" << endl;	
                
                if(matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2] && matriz[0][0] != 'O')
                    cout << "0 0" << endl << "1 0" << endl << "2 0";
                
                else if((matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] != 'O'))
                    cout << "0 0" << endl << "1 1" << endl << "2 2";

                else if((matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0] && matriz[0][0] != 'O'))
                    cout << "0 0" << endl << "1 0" << endl << "2 0";

                else if((matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1] && matriz[0][1] != 'O'))
                    cout << "0 1" << endl << "1 1" << endl << "2 1";

                else if((matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2] && matriz[0][2] != 'O'))
                    cout << "0 2" << endl << "1 2" << endl << "0 2";

                else if((matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2] && matriz[1][0] != 'O'))
                    cout << "1 0" << endl << "1 1" << endl <<"1 2";

                else if((matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2] && matriz[2][0] != 'O'))
                    cout << "2 0" << endl << "2 1" << endl  << "2 0";
                
                else
                    cout << "2 0" << endl << "1 1" << endl << "2 0"; 
			}
			
            else {
                cout << endl << "-1";
            }
		
		
}