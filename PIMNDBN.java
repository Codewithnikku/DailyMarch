class PartitioningIntoMinimumOfDeciBinaryNumbers {
    public int minPartitions(String n) {
        int max = 0;
        for (int i = 0; i < n.length(); i++) {
            max = Math.max(max, n.charAt(i) - '0');
        }
        return max;
    }
}

public class PIMNDBN {
    public static void main(String[] args) {
        System.out.println(new PartitioningIntoMinimumOfDeciBinaryNumbers().minPartitions("32"));
    }
}


/*
LeetCode 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

intution:  We need to find the maximum digit in the string.
 
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

Approach:
We need to find the maximum digit in the string.
Optimal Approach:
We can find the maximum digit in the string in O(n) time.

Algorithm:
1. Initialize max = 0.
2. Iterate over the string n.
3. For each character c in n, update max = Math.max(max, c - '0').
4. Return max.

pseudo code:
1. Initialize max = 0.
2. Iterate over the string n.
3. For each character c in n, update max = Math.max(max, c - '0').
4. Return max.
    int minPartitions(String n) {
        int max = 0;
        for (int i = 0; i < n.length(); i++) {
            max = Math.max(max, n.charAt(i) - '0');
        }
        return max;
    }

    Time Complexity: O(n)
    Space Complexity: O(1)
 */