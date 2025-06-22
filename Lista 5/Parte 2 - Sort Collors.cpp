#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    void sortColors(vector<int>& nums) {
        int tamanho = nums.size();
        vector<int> conts (tamanho, 0); //2 2 2

        for (int digito: nums) {
            conts[digito]++;
        }

        int idx=0;
        for (int digito = 0; digito < tamanho; ++digito) {
            while (conts[digito] > 0) {
                nums[idx] = digito;
                idx++;
                conts[digito]--;
            }
        }

    }
};

int main() {
    vector<int> test1 = {2, 0, 2, 1, 1, 0};
    vector<int> test2 = {2, 0, 1};
    vector<int> test3 = {1, 1, 0, 2, 0, 2, 1, 2, 0, 1, 1, 0, 2, 0, 2};

    Solution().sortColors(test1); for (int v : test1) cout << v << " "; cout << endl;
    Solution().sortColors(test2); for (int v : test2) cout << v << " "; cout << endl;
    Solution().sortColors(test3); for (int v : test3) cout << v << " "; cout << endl;

    return 0;
}