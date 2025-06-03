#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool contaminacao(const vector<vector<char>> &C, int i, int j) { //retorna true ou false, dependendo da expressao
	return ((i > 0 && i<C.size()) && (C[i - 1][j] == 'T'|| C[i + 1][j] == 'T')) ||
	       ((j > 0) && (C[i][j-1] == 'T'|| C[i][j+1] == 'T'))
	       ;
}

bool valida(const vector<vector<char>> &C, int i, int j) {
	return (i >= 0 && j >= 0 && i < C.size() && j < C[i].size()
	        && C[i][j] == 'A');
}

void solucao_pilha(vector<vector<char>> &C, int x, int y) {

	stack<pair<int, int>> pilha; //armazena um par de inteiros

	pilha.emplace(x, y); //insere um novo elemento no final da pilha

	while (!pilha.empty()) { //enquanto pilha nao esta vazia
		auto [i, j] = pilha.top(); //pega o elemento no topo da pilha, separa em 2
		pilha.pop(); //remove o elemento no topo

		if (C[i][j] == 'T' || contaminacao(C, i, j)) {

			C[i][j] = 'T';

			if (valida(C, i + 1, j)) pilha.emplace(i + 1, j);
			if (valida(C, i - 1, j)) pilha.emplace(i - 1, j);
			if (valida(C, i, j - 1)) pilha.emplace(i, j - 1);
			if (valida(C, i, j + 1)) pilha.emplace(i, j + 1);
		}
	}

}


int main() {
	int n, m, x, y;

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
				if (C[i][j] == 'T') {
					x = i;
					y = j;
				}
			}

		}
		solucao_pilha(C, x, y);

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