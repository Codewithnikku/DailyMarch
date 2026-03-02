class TrappingRainWater {
    public int maxWater(int arr[]) {
        // code here
        int n = arr.length;
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            int lmax = arr[i];
            for (int j = 0; j < i; j++) {
                lmax = Math.max(lmax, arr[j]);
            }
            int rmax = arr[i];
            for (int j = i + 1; j < n; j++) {
                rmax = Math.max(rmax, arr[j]);
            }
            res += Math.min(lmax, rmax) - arr[i];
        }
        return res;    
    }
}


public class TRW {
    public static void main(String[] args) {
        int[] arr = {3, 0, 2, 0, 4};
        TrappingRainWater trw = new TrappingRainWater();
        System.out.println(trw.maxWater(arr));
    }
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
    public int minSwaps(int[][] grid) {
        int n = grid.length;
        int[] zeros = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    zeros[i]++;
                } else {
                    break;
                }
            }
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (zeros[i] >= n - 1 - i) {
                continue;
            }
            int j = i;
            while (j < n && zeros[j] < n - 1 - i) {
                j++;
            }
            if (j == n) {
                return -1;
            }
            while (j > i) {
                int temp = zeros[j];
                zeros[j] = zeros[j - 1];
                zeros[j - 1] = temp;
                swaps++;
                j--;
            }
        }
        return swaps;
    }
}

Time Complexity: O(n^2)
Space Complexity: O(n)

*/