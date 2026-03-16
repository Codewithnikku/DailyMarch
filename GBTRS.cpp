class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        set<int, greater<int>> st;

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                st.insert(grid[r][c]);

                for (int k = 1; r + 2 * k < m && c - k >= 0 && c + k < n; k++)
                {
                    int sum = 0;

                    int x = r, y = c;

                    for (int i = 0; i < k; i++)
                    {
                        x++;
                        y--;
                        sum += grid[x][y];
                    }

                    for (int i = 0; i < k; i++)
                    {
                        x++;
                        y++;
                        sum += grid[x][y];
                    }

                    // up-right
                    for (int i = 0; i < k; i++)
                    {
                        x--;
                        y++;
                        sum += grid[x][y];
                    }

                    // up-left
                    for (int i = 0; i < k; i++)
                    {
                        x--;
                        y--;
                        sum += grid[x][y];
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (int x : st)
        {
            ans.push_back(x);
            if (ans.size() == 3)
                break;
        }
        return ans;
    }
};