#include <iostream>
#include <vector>
using namespace std;

class TrapRainWater {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxWater = 0;
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            if (arr[left] < arr[right]) {
                if (arr[left] >= leftMax) {
                    leftMax = arr[left];
                } else {
                    maxWater += leftMax - arr[left];
                }
                left++;
            } else {
                if (arr[right] >= rightMax) {
                    rightMax = arr[right];
                } else {
                    maxWater += rightMax - arr[right];
                }
                right--;
            }
        }
        return maxWater;
    }
};

int main() {
    TrapRainWater trw;
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trw.maxWater(arr) << endl;
    return 0;
}

/*
intution:
We need to find the minimum number of swaps required to make each row have at least n - 1 - i zeros in the end.

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

code:
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxWater = 0;
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            if (arr[left] < arr[right]) {
                if (arr[left] >= leftMax) {
                    leftMax = arr[left];
                } else {
                    maxWater += leftMax - arr[left];
                }
                left++;
            } else {
                if (arr[right] >= rightMax) {
                    rightMax = arr[right];
                } else {
                    maxWater += rightMax - arr[right];
                }
                right--;
            }
        }
        return maxWater;
    }
};

Time Complexity: O(n)
Space Complexity: O(1)

*/