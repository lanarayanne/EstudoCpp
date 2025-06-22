#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparar(const string &a, const string& b) {
    int tamanhoa=a.size();
    int tamanhob=b.size();

    if (tamanhoa == tamanhob) {
        return true;
    }
    return false;
}

vector<vector<string>> groupStrings(vector<string> &strs) { //recebeu todas as strings
    vector<vector<string>> res;
    vector<vector<string>> ord;
    vector<bool> adc(strs.size(), false);
    vector<int> tamanhos;

    for (int i = 0; i < strs.size(); i++) {
        if (adc[i]) {
            continue;
        }
        vector<string> grupo;
        grupo.push_back(strs[i]);
        adc[i] = true;

        for (int j = i+1; j < strs.size(); j++) {
            if (comparar(strs[i], strs[j])) {
                grupo.push_back(strs[j]);
                adc[j] = true;
            };
        }

        res.push_back(grupo);
    }

    for (int i = 0; i < res.size(); i++) {
        tamanhos.push_back(res[i][0].size());
        cout << tamanhos[i] << " ";
    }
    cout << endl;

    sort(tamanhos.begin(), tamanhos.end());

    // A lógica de ordenação agora vive dentro da função.

    sort(res.begin(), res.end(), [](const vector<string>& a, const vector<string>& b) {
        return a[0].size() < b[0].size();
    });

    return res;
}

int main() {

    vector<string> strs = {"Redes", "IFPE", "Algoritmos", "Android",
                           "Complexidade", "IF", "PE", "Recife",
                           "TADS", "2025", "BubbleSort", "Git",
                           "GitHub", "Subversion", "Gradle", "Docker"};

    vector<vector<string>> groups = groupStrings(strs);

    for (const auto &group : groups) {
        for (const auto &str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}