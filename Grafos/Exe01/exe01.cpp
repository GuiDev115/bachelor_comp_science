#include <iostream>
#include <vector>

using namespace std;

void grau_vertice(vector<vector<int>>& LA, int u) {
    int grau_saida = LA[u].size();
    
    int grau_entrada = 0;
    for(auto& lista : LA) {
        for(int v : lista) {
            if(v == u) {
                grau_entrada++;
            }
        }
    }
    
    cout << "Vertice " << u << ": Grau de entrada = " << grau_entrada << ", Grau de saida = " << grau_saida << endl;
}

int main() {
    int u = 0;

    cout << "Grafo 1" << endl;
    vector<vector<int>> LA = {{1, 2, 3}, {0, 2, 3}, {0, 1, 3}, {0, 1, 2}};
    cout << "Digite o vertice u: ";
    cin >> u;
    grau_vertice(LA, u);
    return 0;
}