class FindKthBitInNthBinaryString {
    public char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';
        }
        int len = (1 << n) - 1;
        if (k == (len + 1) / 2) {
            return '1';
        } else if (k < (len + 1) / 2) {
            return findKthBit(n - 1, k);
        } else {
            int mirror = len - k + 1;
            char mirrorBit = findKthBit(n - 1, mirror);
            return (mirrorBit == '0') ? '1' : '0';
        }
    }
}

public class FKBNBS {
    public static void main(String[] args) {
        FindKthBitInNthBinaryString fkbnbs = new FindKthBitInNthBinaryString();
        System.out.println(fkbnbs.findKthBit(3, 1));
    }
}

/*
LeetCode 1545. Find Kth Bit in Nth Binary String

intution:
We can observe that the nth binary string is obtained by appending '1', then the reverse of the (n - 1)th binary string, with all bits inverted.
For example, the 3rd binary string is "0111001".

Approach:
We need to find the kth bit in the nth binary string.
We can use the following approach:
1. If n == 1, return '0'.
2. If k == (len + 1) / 2, return '1'.
3. If k < (len + 1) / 2, return the kth bit in the (n - 1)th binary string.
4. Otherwise, return the complement of the (len - k + 1)th bit in the (n - 1)th binary string.

Algorithm:
1. Initialize len = (1 << n) - 1.
2. If k == (len + 1) / 2, return '1'.
3. If k < (len + 1) / 2, return the kth bit in the (n - 1)th binary string.
4. Otherwise, return the complement of the (len - k + 1)th bit in the (n - 1)th binary string.

pseudocode:
1. Initialize len = (1 << n) - 1.
2. If k == (len + 1) / 2, return '1'.
3. If k < (len + 1) / 2, return the kth bit in the (n - 1)th binary string.
4. Otherwise, return the complement of the (len - k + 1)th bit in the (n - 1)th binary string.

Time Complexity: O(n)
Space Complexity: O(n)
*/