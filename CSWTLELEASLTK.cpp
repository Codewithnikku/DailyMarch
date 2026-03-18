#include <iostream>
#include <vector>
#include <queue>
using namespace std;



class CountSubmatricesWithTopleftElementAndSumLessThanK {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> pref(m, vector<long long>(n, 0));
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[i][j] = grid[i][j];

                if (i > 0) pref[i][j] += pref[i - 1][j];
                if (j > 0) pref[i][j] += pref[i][j - 1];
                if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];

                if (pref[i][j] <= k) res++;
            }
        }

        return res;
    }
};

int main() {
    CountSubmatricesWithTopleftElementAndSumLessThanK cs;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 10;
    cout << cs.countSubmatrices(grid, k) << endl;
    return 0;
}