#include <iostream>
#include <vector>
using namespace std;

void rotate1(vector<int> &arr, int n) {
    int size = arr.size();
    int last= size-1;
    int temp;

    for (int i = 0; i < n; i++) {
        temp = arr[last];
        for (int j = last; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}

void rotate(vector<int> &arr, int n) {
    int size = arr.size();
    vector<int> tmp = arr;

    for (int i = 0; i < size ; i++) {
        arr[i] = tmp[(i - n + size) % size];
    }
}

int main() {
    vector<int> arr = {3, 5, 8, 10, 1, 7, 9, 4};
    int c;
    int n = 3;

    rotate(arr, n);

    for (auto v : arr) cout << v << " ";
    return 0;
}
