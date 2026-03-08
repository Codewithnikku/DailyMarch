/*
Given: An array of string nums containing n unique binary strings each of length n.
Return a binary string n that does not appear in nums. If there are multiple answers you return them.

Example:
    Input: nums = ["01", "10"]
    Output: "11"
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res = "";
        for (int i = 0; i < n; i++) {
            res += nums[i][i] == '0' ? '1' : '0';
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> nums = {"01", "10"};
    cout << sol.findDifferentBinaryString(nums) << endl;
    return 0;
}