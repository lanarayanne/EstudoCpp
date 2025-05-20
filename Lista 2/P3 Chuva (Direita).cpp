#include <iostream>
#include <vector>

using namespace std;

//||(j < C[i].size() - 1 && i < C.size() - 1 && C[i][j + 1] == 'o' && C[i + 1][j + 1] == '#')
//||(j < C[i].size() - 1 && i < C.size() - 1 && C[i][j + 1] == 'o' && C[i + 1][j + 1] == '#')

void solucao_iterativa(vector<vector<char>> &C) {
    bool change;
    do {
        change = false;
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < C[i].size(); j++) { //lendo matriz chamada C
                if (C[i][j] != '.') continue;

                if ((i > 0 && C[i - 1][j] == 'o') ||
                    (j > 0 && i < C.size() - 1 && C[i][j - 1] == 'o' && C[i + 1][j - 1] == '#') ) {
                    C[i][j] = 'o';
                    change = true;
                }
            }
        }
    }
    while (change);
}

void chuva(vector<vector<char>> &C, int i, int j) {
    if (i < 0 || i >= C.size() || j < 0 || j >= C[i].size()) return; //se passar o tamanho do vetor, retorna

    if (C[i][j] != '.') return; //se for diferente . retorna

    if ((i > 0 && C[i - 1][j] == 'o') ||
        (j > 0 && i < C.size() - 1 && C[i][j - 1] == 'o' && C[i + 1][j - 1] == '#') ) {

        C[i][j] = 'o'; //cada vez que mudar para ser chuva, chama a função chuva para as posições adjacentes <- baixo ->

        chuva(C, i, j - 1);
        chuva(C, i, j  + 1);
        chuva(C, i + 1, j);
    }
}

void solucao_recursiva(vector<vector<char>> &C) {
    for (int j = 0; j < C[0].size(); j++) { //le a matriz
        if (C[0][j] == 'o') { //chama a função recursiva quando achar a chuva
            chuva(C, 0, j - 1);
            chuva(C,0, j  + 1);
            chuva(C, 1, j);
            return;
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<char>> C(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> C[i][j];
        }
    }

    // solucao_iterativa(C);

    solucao_recursiva(C);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << C[i][j];
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}