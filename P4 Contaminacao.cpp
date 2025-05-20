#include <iostream>
#include <vector>

using namespace std;
//i>0 && i<C.size()-1 && j>0 && j<C[i].size() -1 && C[i-1][j] == 'T' || C[i+1][j] == 'T' || C[i][j-1] == 'T' || C[i][j+1] == 'T'

void solucao_iterativa(vector<vector<char> > &C) {
    bool change;
    do {
        change = false;
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < C[i].size(); j++) { //lendo matriz chamada C
                if (C[i][j] != 'A') continue;

                if (i>0 && C[i-1][j] == 'T' || i<C.size()-1 && C[i+1][j] == 'T' || j>0 && C[i][j-1] == 'T' ||  j<C[i].size() -1 && C[i][j+1] == 'T') {
                    C[i][j] = 'T';
                    change = true;
                }
            }
        }
    }
    while (change);
}

void contaminacao(vector<vector<char>> &C, int i, int j) {
    if (i < 0 || i >= C.size() || j < 0 || j >= C[i].size()) return; //se passar o tamanho do vetor, retorna

    if (C[i][j] != 'A') return; //se for diferente de A retorna

    if (i>0 && C[i-1][j] == 'T' || i<C.size()-1 && C[i+1][j] == 'T' || j>0 && C[i][j-1] == 'T' ||  j<C[i].size() -1 && C[i][j+1] == 'T') {

        C[i][j] = 'T'; //cada vez que mudar para contaminado, chama a função contaminacao para as posições adjacentes <- baixo ->

        contaminacao(C, i, j - 1);
        contaminacao(C, i, j  + 1);
        contaminacao(C, i + 1, j);
        contaminacao(C, i - 1, j);
    }
}

void solucao_recursiva(vector<vector<char>> &C) {
    for (int j = 0; j < C[0].size(); j++) {
        for (int i = 0; i < C.size(); i++) {
            if (C[i][j] == 'T') { //chama a função recursiva quando achar a contaminacao
                contaminacao(C, i, j - 1);
                contaminacao(C,i, j  + 1);
                contaminacao(C, i+1, j);
                contaminacao(C, i-1, j);
                return;
            }
        }
    }
}

int main() {
    int n, m;

    vector<vector<vector<char>>> V; // vetor de matrizes

    while (true) {
        cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        vector<vector<char>> C(n, vector<char>(m)); //matriz

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> C[i][j];
            }
        }

        // solucao_iterativa(C);
        solucao_recursiva(C);

        V.push_back(C);
    }

    for (int k = 0; k < V.size(); ++k) {
        for (int i = 0; i < V[k].size(); ++i) {
            for (int j = 0; j < V[k][i].size(); ++j) {
                cout << V[k][i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
