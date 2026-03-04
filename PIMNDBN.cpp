#include <iostream>
#include <string>
using namespace std;

class PartitioningIntoMinimumNumberOfDeciBinaryNumbers {
public:
    int minPartitions(string n) {
        int max = 0;
        for (int i = 0; i < n.length(); i++) {
            max = std::max(max, n[i] - '0');
        }
        return max;
    }
};

int main() {
    PartitioningIntoMinimumNumberOfDeciBinaryNumbers pimndbn;
    cout << pimndbn.minPartitions("32") << endl;
    return 0;
}

/*
LeetCode 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

//Intuition:  We need to find the maximum digit in the string.
Approach:
We need to find the maximum digit in the string.
Optimal Approach:
We can find the maximum digit in the string in O(n) time.

Replace with:
Complexity :
Time Complexity: O(n)
Space Complexity: O(1)

Example 1:

Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
Example 2:

Input: n = "82734"
Output: 8
Example 3:

Input: n = "27346209830709182346"
Output: 9
 

Constraints:

1 <= n.length <= 105
n consists of only digits.
n does not contain any leading zeros and represents a positive integer.

 */

 /*
Explanation of the Logic:

The goal of this problem is to determine the minimum number of
deci-binary numbers needed to sum up to the given decimal number.

A deci-binary number:
- Contains only digits 0 or 1
- Has no leading zeros
- Example: 1, 10, 101, 1100

Important Observation:
Each deci-binary number can contribute at most 1 to any digit position.
That means if a digit in the given number is 'd', we need at least 'd'
separate deci-binary numbers to build that digit.

Example:
If n = "32"

Digit 3 means:
We need 3 deci-binary numbers contributing 1 at that position.

Digit 2 means:
We need 2 deci-binary numbers contributing 1 at that position.

Since we must satisfy ALL digit positions,
we take the maximum digit in the number.

So:
Minimum deci-binary numbers required = Maximum digit in n

Algorithm Steps:
1. Initialize an integer variable 'max' to 0.
2. Traverse each character in the string.
3. Convert the character to its numeric value using (n[i] - '0').
4. Update max using max = std::max(max, current_digit).
5. After the loop ends, return max.

Why This Works:
Because deci-binary numbers only contain 0 or 1,
we are essentially stacking layers of 1s.
The number of layers needed is determined by
the highest digit in the given number.

Time Complexity: O(n)
Space Complexity: O(1)
*/