#include <iostream>
using namespace std;

class checkIfBinaryStringHasAtMostOneSegmentOfOnes {
public:
    bool checkOnesSegment(string s) {
        bool seenZeroAfterOne = false;

        for(char c : s){
            if(c == '0'){
                seenZeroAfterOne = true;
            }
            else if(c == '1' && seenZeroAfterOne){
                return false;
            }
        }

        return true;
    }
};

int main(){
    checkIfBinaryStringHasAtMostOneSegmentOfOnes check;
    string s = "1001";
    cout << check.checkOnesSegment(s) << endl;
    return 0;
}

/*
LeetCode 1784. Check if Binary String Has at Most One Segment of Ones
Intuition:
We need to check if the binary string has at most one segment of ones.
Approach:
We can use a simple approach to solve this problem.
We can iterate over the string and check if we have seen a '0' after a '1'.
If we have seen a '0' after a '1', we can return false.
If we have not seen a '0' after a '1', we can return true.
Optimal Approach:
We can use a simple approach to solve this problem.
We can iterate over the string and check if we have seen a '0' after a '1'.
If we have seen a '0' after a '1', we can return false.
If we have not seen a '0' after a '1', we can return true.

code steps:
    step 1: Initialize seenZeroAfterOne = false
    step 2: For each character c in s:
        step 2.1: If c == '0':
            step 2.1.1: seenZeroAfterOne = true
        step 2.2: Else if c == '1' and seenZeroAfterOne:
            step 2.2.1: Return false
    step 3: Return true

    Time Complexity: O(n)
    Space Complexity: O(1)
*/