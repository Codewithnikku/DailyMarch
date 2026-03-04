#include <iostream>
#include <vector>
using namespace std;

class MinimumSwapsToArrangeBinaryGrid {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) count++;
            zeros[i] = count;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int needed = n - i - 1;
            int j = i;
            while (j < n && zeros[j] < needed) j++;
            if (j == n) return -1;
            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                j--;
                swaps++;
            }
        }

        return swaps;
    }
};

int main() {
    MinimumSwapsToArrangeBinaryGrid msabg;
    vector<vector<int>> grid = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};
    cout << msabg.minSwaps(grid) << endl;
    return 0;
}

/*
LeetCode 1536. Minimum Swaps to Arrange a Binary Grid

Intuition:
We need to find the minimum number of swaps required to make each row have at least n - 1 - i zeros in the end.

Algorithm:
1. Initialize n = grid.length.
2. Initialize zeros = new int[n].
3. Iterate over the grid.
4. For each row i, iterate over the columns j in reverse order.
5. If grid[i][j] == 0, increment zeros[i].
6. Otherwise, break.
7. Initialize swaps = 0.
8. Iterate over the rows i.
9. For each row i, if zeros[i] >= n - 1 - i, continue.
10. Otherwise, find the first row j such that zeros[j] >= n - 1 - i.
11. If j == n, return -1.
12. Otherwise, while j > i, swap zeros[j] and zeros[j - 1], and increment swaps.
13. Return swaps.

Approach:
We need to find the minimum number of swaps required to make each row have at least n - 1 - i zeros in the end.
steps:
1. Initialize n = grid.length.
2. Initialize zeros = new int[n].
3. Iterate over the grid.
4. For each row i, iterate over the columns j in reverse order.
5. If grid[i][j] == 0, increment zeros[i].
6. Otherwise, break.
7. Initialize swaps = 0.
8. Iterate over the rows i.
9. For each row i, if zeros[i] >= n - 1 - i, continue.
10. Otherwise, find the first row j such that zeros[j] >= n - 1 - i.
11. If j == n, return -1.
12. Otherwise, while j > i, swap zeros[j] and zeros[j - 1], and increment swaps.
13. Return swaps.

code []
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) count++;
            zeros[i] = count;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int needed = n - i - 1;
            int j = i;
            while (j < n && zeros[j] < needed) j++;
            if (j == n) return -1;
            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                j--;
                swaps++;
            }
        }

        return swaps;
    }
Time Complexity: O(n^2)
Space Complexity: O(n)
*/ 