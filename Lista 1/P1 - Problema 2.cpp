#include <iostream>
#include <vector>

using namespace std;

int maior(const vector<int> &arr) {

    vector<int> arrCpy = arr;
    int size = arrCpy.size();
    int num = arrCpy[0];

    if (size == 1) {
        return arrCpy[0];
    } else {
        arrCpy.erase(arrCpy.begin());

        if (num > maior(arrCpy)) {
            return num;
        }
        else {
            return maior(arrCpy);
        }
    }
}

int main() {
    vector<int> arr = {10, 1, 5, 3, 12, 7, 4, 6};
    cout << maior(arr) << endl;
    return 0;
}