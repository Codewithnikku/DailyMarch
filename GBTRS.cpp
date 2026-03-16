#include <iostream>
#include <vector>
#include <set>
using namespace std;



class GBTRS
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

int main()
{
    GBTRS gbtrs;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = gbtrs.getBiggestThree(grid);
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}