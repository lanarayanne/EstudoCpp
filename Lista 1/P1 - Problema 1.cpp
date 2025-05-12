#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &arr, int n) {
    int size = arr.size();
    for (int i = 0; i < n; i++) {
        int temp = arr[size - 1];
        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}

int main() {
    vector<int> arr = {-1,-100,3,99};
    int c;
    int n = 2;

    rotate(arr, n);

    for (auto v : arr) cout << v << " ";
    return 0;
}
