#include <iostream>

using namespace std;

void selectionsort(int number[], int stop){
    int posMenor, i, j;

    for (int i=0; i < stop-1; ++i) {
    posMenor = i;
    for (int j=i+1; j < stop; ++j) {
        if (number[j] > number[posMenor])
            posMenor = j;
    }
    swap (number[i], number[posMenor]);
}
}

int main(){
    int n1, i, stop;

    cin >> n1;

    int number[n1];

    for(i=0; i < n1; i++){
        cin >> number[i];
    }

    cin >> stop;
    stop = stop +1;

    selectionsort(number, stop);

    cout << endl;

    for(i=0; i < n1; i++){
        cout << number[i] << " ";
    }
}