#include <iostream>

using namespace std;

int main(){

    string word, word1;
    int i;

    getline(cin, word);
    getline(cin, word1);

    int n1 = int (word.size()), n2 = int (word1.size());

    int total = n1 + n2;

    string *v = new string[total];

    cout << endl;

    for (i = 0; i < n1; i++)
        v[i] = word[i];

    for ( int i = 0; i < n2; i++)
        v[i + n1] = word1[i];

    for ( int i = 0; i < total; i++)
        cout << v[i];   

}
