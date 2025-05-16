#include <iostream>
#include <vector>
using namespace std;

#define TERRA(i, j) (grid[i][j] == 1)
#define AGUA(i, j) ((i < 0) || (i >= m) || (j < 0) || (j >= n) || grid[i][j] == 0)

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int perimeter = 0;
        const int m = grid.size();
        const int n = grid[0].size();

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (TERRA(i, j) && AGUA(i, j - 1)) {
                    perimeter++;
                 }
                if (TERRA(i, j) && AGUA(i, j + 1)) {
                    perimeter++;
                }
                if (TERRA(i, j) && AGUA(i - 1, j)) {
                    perimeter++;
                }
                if (TERRA(i, j) && AGUA(i + 1, j)) {
                    perimeter++;
                }
            }
        }

        return perimeter;
    }

};

int main() {
    vector<vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0},
    };

    cout << Solution().islandPerimeter(grid) << endl; // res = 16

    return 0;
}