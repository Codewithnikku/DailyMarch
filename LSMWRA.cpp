class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int res = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0)
                    height[j] = 0;
                else
                    height[j] += 1;
            }

            vector<int> sortedHeight = height;
            sort(sortedHeight.begin(), sortedHeight.end(), greater<int>());

            for(int j = 0; j < n; j++) {
                res = max(res, sortedHeight[j] * (j + 1));
            }
        }
        return res;
    }
};