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
    LongestSubarrayWithAtmostTwoDistinctIntegers lswatdi = new LongestSubarrayWithAtmostTwoDistinctIntegers();
    cout << lswatdi.totalElements(new int[] {1, 2, 1, 3, 4}) << endl;
    return 0;
}