#include <iostream>

using namespace std;

float milha (float km1) {

    float milha;

    milha = km1 * 1.852;

    return milha;

}

float dist(float kmh1, float t1) {

    float milha(float km1);

    float dist;

    dist = milha(kmh1) * t1;

    return dist;
    

}

int main()
{
    
    float km, kmh, t;

    cin >> km >> kmh >> t;

    cout << milha(km) << " ";
    cout << dist(kmh, t);

}

