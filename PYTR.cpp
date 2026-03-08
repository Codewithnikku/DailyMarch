class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        // use while loop and ternary operator
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = n - 1; i >= 2; i--) {
            int j = 0, k = i - 1;
            while (j < k) {
                if (arr[j] * arr[j] + arr[k] * arr[k] == arr[i] * arr[i]) {
                    return true;
                } else if (arr[j] * arr[j] + arr[k] * arr[k] < arr[i] * arr[i]) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return false;
    }
};