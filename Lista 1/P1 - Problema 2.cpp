#include <iostream>
#include <vector>

using namespace std;

int maior(const vector<int> &arr) {
    vector<int> vet = arr;

    int size = vet.size();
    int num = vet[0];

    if (size == 1) {
        return vet[0];
    } else {
        vet.erase(vet.begin());

        if (num > maior(vet)) {
            return num;
        }
        else {
            return maior(vet);
        }
    }
}

int main() {
    vector<int> arr = {10, 1, 5, 3, 12, 7, 4, 6};
    cout << maior(arr) << endl;
    return 0;
}