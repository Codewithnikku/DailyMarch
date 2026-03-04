#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class LongestSubarrayWithAtmostTwoDistinctIntegers {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i = 0, j = 0;
        int maxLen = 0;
        unordered_map<int, int> freq;
        while (j < n) {
            freq[arr[j]]++;
            while (freq.size() > 2) {
                freq[arr[i]]--;
                if (freq[arr[i]] == 0) {
                    freq.erase(arr[i]);
                }
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};

int main() {
    LongestSubarrayWithAtmostTwoDistinctIntegers lswatdi;
    vector<int> arr = {1, 2, 1, 3, 4};
    cout << lswatdi.totalElements(arr) << endl;
    return 0;
}


/*
LeetCode 1493. Longest Subarray of 1's After Deleting One Element

Intuition:
We need to find the longest subarray of 1's after deleting one element.
Approach:
We can use a sliding window approach to solve this problem.
We can maintain a window that contains at most two distinct integers.
We can keep track of the maximum length of the window.
Optimal Approach:
We can use a sliding window approach to solve this problem in O(n) time.
We can maintain a window that contains at most two distinct integers.
We can keep track of the maximum length of the window.

Approach:
We can use a sliding window approach to solve this problem.
We can maintain a window that contains at most two distinct integers.
We can keep track of the maximum length of the window.

Code Explaination:
    step 1: Initialize i = 0, j = 0, maxLen = 0, freq = {}
    step 2: While j < n:
        step 2.1: freq[arr[j]]++
        step 2.2: While freq.size() > 2:
            step 2.2.1: freq[arr[i]]--
            step 2.2.2: If freq[arr[i]] == 0:
                step 2.2.2.1: freq.erase(arr[i])
            step 2.2.3: i++
        step 2.3: maxLen = max(maxLen, j - i + 1)
        step 2.4: j++
    step 3: Return maxLen

    Complexity Analysis:
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
