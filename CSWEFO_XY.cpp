#include <iostream>
#include <vector>
using namespace std;

class CountSubmatricsWithEqualFrequencyOf_X__Y {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        vector<vector<int>> px(m, vector<int>(n, 0));
        vector<vector<int>> py(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                px[i][j] = (grid[i][j] == 'X');
                py[i][j] = (grid[i][j] == 'Y');

                if (i > 0) {
                    px[i][j] += px[i - 1][j];
                    py[i][j] += py[i - 1][j];
                }

                if (j > 0) {
                    px[i][j] += px[i][j - 1];
                    py[i][j] += py[i][j - 1];
                }

                if (i > 0 && j > 0) {
                    px[i][j] -= px[i - 1][j - 1];
                    py[i][j] -= py[i - 1][j - 1];
                }

                if (px[i][j] == py[i][j] && px[i][j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {{'X','Y','.'},{'Y','.','.'}};
    cout << sol.numberOfSubmatrices(grid) << endl;
    return 0;
}

/*
Intuition:
We can use prefix sum to calculate the number of X's and Y's in a submatrix.
If the number of X's and Y's are equal, then we have found a valid submatrix.

Approach & Code steps :

1. Initialize a 2D vector px of size m x n to store the prefix sum of X's.
2. Initialize a 2D vector py of size m x n to store the prefix sum of Y's.
3. Iterate over the grid and calculate the prefix sum of X's and Y's.
4. Iterate over the grid again and check if the number of X's and Y's in the submatrix is equal.
5. If the number of X's and Y's are equal, then increment the answer.
6. Return the answer.

complexity analysis:
time complexity: O(mn)
space complexity: O(mn)


*/