#include <iostream>
#include <vector>
using namespace std;
string reordenar(string str) {

    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < str.size(); j++) {
            if (str[i] < str[j]) {
                int temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    return str;
}
int main() {
    cout << reordenar(string("casa")) << endl;
    cout << reordenar(string("escola")) << endl;
    cout << reordenar(string("ifpe")) << endl;
    cout << reordenar(string("banana")) << endl;
    return 0;
}