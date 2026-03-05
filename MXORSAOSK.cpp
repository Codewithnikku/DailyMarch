#include <bits/stdc++.h>
using namespace std;

class MaxXORSubArrayOfSizek{
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int max_xor = 0;
        int prefix_xor_sum = 0;
        unordered_map<int, int> prefix_xor_sum_map;
        for(int i = 0; i < n; i++){
            prefix_xor_sum ^= arr[i];
            if(prefix_xor_sum == k){
                max_xor = max(max_xor, i + 1);
            }
            if(prefix_xor_sum_map.find(prefix_xor_sum ^ k) != prefix_xor_sum_map.end()){
                max_xor = max(max_xor, i - prefix_xor_sum_map[prefix_xor_sum ^ k]);
            }
            if(prefix_xor_sum_map.find(prefix_xor_sum) == prefix_xor_sum_map.end()){
                prefix_xor_sum_map[prefix_xor_sum] = i;
            }
        }
        return max_xor;
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    MaxXORSubArrayOfSizek obj;
    cout << obj.maxSubarrayXOR(arr, k) << endl;
    return 0;
}

/*
Input:
n = 5, k = 2
arr = {1, 2, 3, 4, 5}
Output:
2

Intution:
We can use the prefix XOR sum to solve this problem.
We can store the prefix XOR sum in a hashmap.
We can iterate over the array and find the prefix XOR sum.
We can check if there is a prefix XOR sum such that prefix_xor_sum ^ k = 0.
If there is a prefix XOR sum such that prefix_xor_sum ^ k = 0, then we can update the max_xor.

Approach Steps:
1. Initialize max_xor = 0.
2. Initialize prefix_xor_sum = 0.
3. Create a hashmap to store the prefix XOR sum.
4. Iterate over the array.
5. Find the prefix XOR sum.
6. Check if there is a prefix XOR sum such that prefix_xor_sum ^ k = 0.
7. If there is a prefix XOR sum such that prefix_xor_sum ^ k = 0, then update max_xor.
8. Return max_xor.

Time Complexity: O(n)
Space Complexity: O(n)
*/