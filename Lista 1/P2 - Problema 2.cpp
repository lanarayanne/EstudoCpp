#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string binario(int num, int n) {
    string tmp;
    string bin;

    while (num/2 > 0) {
        if (num%2 == 0) {
            tmp.push_back('0');
        } else {
            tmp.push_back('1');
        }
        num = num/2;
    }

    if (num != 0) {
        tmp.push_back('1');
    }

    int j = tmp.size() - 1;

    for (int i = 0; i < n ; i++) {
        bin.push_back('0');
    }

    for (int i = 0; i <tmp.size() ; i++) {
        bin.erase(bin.begin());
        bin.push_back(tmp.at(j));
        j--;
    }

    return bin;

}

void gerar(vector<string> &seqs, int n, string tmp) {
    static int atual = 0;
    double total = pow(2,n);

    if (atual == total) {
        atual = 0;
        return;
    }

    seqs.push_back(binario(atual, n));
    atual++;
    gerar(seqs, n, tmp);
}


vector<string> gerar(int n) {
    vector<string> seqs;
    gerar(seqs, n, string(""));
    return seqs;
}

int main() {
    for (auto &s : gerar(3)) {
        cout << s << endl;
    }
}