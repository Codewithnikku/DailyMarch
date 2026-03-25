class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long total = 0;

        for (auto &row : grid)
            for (int val : row)
                total += val;

        if (total % 2) return false;

        long long target = total / 2;

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                sum += grid[i][j];
            if (sum == target) return true;
        }

        sum = 0;
        for (int j = 0; j < m; j++) {
            long long colSum = 0;
            for (int i = 0; i < n; i++)
                colSum += grid[i][j];
            sum += colSum;
            if (sum == target) return true;
        }

        return false;
    }
};

/*
# Intuition
We need to check whether the grid can be divided into two parts such that both parts have equal sum.
Instead of comparing individual elements, we focus on total sums of partitions formed by straight cuts.

# Approach
1. Compute the total sum of all elements in the grid.
2. If the total sum is odd, equal partition is impossible.
3. Set target = total / 2.
4. Try horizontal cuts:
   - Accumulate row-wise sum.
   - If at any row the sum equals target, return true.
5. Try vertical cuts:
   - Accumulate column-wise sum.
   - If at any column the sum equals target, return true.
6. If no valid partition is found, return false.

# Complexity
- Time Complexity: O(n * m)
  We traverse the grid a constant number of times.
- Space Complexity: O(1)
  No extra space is used apart from variables.

# Key Points
- Only straight cuts (horizontal or vertical) are allowed.
- Prefix accumulation avoids recomputation.
- Works efficiently even for large grids.
*/