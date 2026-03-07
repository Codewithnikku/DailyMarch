#include <iostream>
using namespace std;

class minFlipsToMakeAlternatingBinaryString {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;

        int ans = n;
        int mis0 = 0;

        for(int i = 0; i < 2*n; i++) {

            char expected = (i % 2 == 0) ? '0' : '1';

            if(t[i] != expected) mis0++;

            if(i >= n) {
                int left = i - n;
                char exp_left = (left % 2 == 0) ? '0' : '1';
                if(t[left] != exp_left) mis0--;
            }

            if(i >= n - 1) {
                int mis1 = n - mis0;
                ans = min(ans, min(mis0, mis1));
            }
        }

        return ans; 
    }
};


int main(){
    minFlipsToMakeAlternatingBinaryString minFlipsToMakeAlternatingBinaryString;
    string s = "0100";
    cout << minFlipsToMakeAlternatingBinaryString.minFlips(s) << endl;
    return 0;
}


/*
LeetCode 1888. Minimum Number of Flips to Make the Binary String Alternating
Intuition:
We need to find the minimum number of flips required to make the binary string alternating.
Approach:
We can use a sliding window approach to solve this problem.
We can maintain a window that contains at most two distinct integers.
We can keep track of the minimum number of flips required.
Optimal Approach:
We can use a sliding window approach to solve this problem in O(n) time.
We can maintain a window that contains at most two distinct integers.
We can keep track of the minimum number of flips required.

code steps:
    step 1: Initialize n = s.size(), t = s + s, ans = n, mis0 = 0
    step 2: For i = 0 to 2*n - 1:
        step 2.1: char expected = (i % 2 == 0) ? '0' : '1'
        step 2.2: If t[i] != expected:
            step 2.2.1: mis0++
        step 2.3: If i >= n:
            step 2.3.1: int left = i - n
            step 2.3.2: char exp_left = (left % 2 == 0) ? '0' : '1'
            step 2.3.3: If t[left] != exp_left:
                step 2.3.3.1: mis0--
        step 2.4: If i >= n - 1:
            step 2.4.1: int mis1 = n - mis0
            step 2.4.2: ans = min(ans, min(mis0, mis1))
        step 2.5: Return ans
    
        Time Complexity: O(n)
        Space Complexity: O(1)
*/
