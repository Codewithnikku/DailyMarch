#include <iostream>
#include <string>
using namespace std;

class MinimumChangeToMakeAlternatingBinaryString {
public:
    int minOperations(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != (i % 2 == 0 ? '0' : '1')){
                count++;
            }
        }
        return min(count, n - count);
    }
};

int main() {
    MinimumChangeToMakeAlternatingBinaryString mctmabs;
    string s = "0100";
    cout << mctmabs.minOperations(s) << endl;
    return 0;
}

/*
LeetCode 1758. Minimum Changes To Make Alternating Binary String
Intuition:
We need to find the minimum number of changes required to make the binary string alternating.
Approach:
We can use a simple approach to solve this problem.
We can iterate over the string and check if the current character is equal to the character that should be at that position.
If not, we can increment the count.
We can return the minimum of the count and the number of changes required to make the string alternating if we start with '0' and '1'.
Optimal Approach:
We can use a simple approach to solve this problem.
We can iterate over the string and check if the current character is equal to the character that should be at that position.
If not, we can increment the count.
We can return the minimum of the count and the number of changes required to make the string alternating if we start with '0' and '1'.

code steps:
    step 1: Initialize n = s.size(), count = 0
    step 2: For i = 0 to n - 1:
        step 2.1: If s[i] != (i % 2 == 0 ? '0' : '1'): // if the current character is not equal to the character that should be at that position
            step 2.1.1: count++
    step 3: Return min(count, n - count) // minimum of count and n - count is the answer

    Complexity:
        Time: O(n)
        Space: O(1)
*/