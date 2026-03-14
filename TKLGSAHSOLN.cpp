#include <iostream>
#include <vector>
using namespace std;

class TheKthLexicographicalStringOfAllHappyStringsOfLengthN {
public:
    string getHappyString(int n, int k) {
        string res = "";
        vector<string> happyStrings;
        dfs(n, res, happyStrings);
        if (k > happyStrings.size()) {
            return "";
        }
        return happyStrings[k - 1];
    }
private:
    void dfs(int n, string& res, vector<string>& happyStrings) {
        if (n == 0) {
            happyStrings.push_back(res);
            return;
        }
        for (char c = 'a'; c <= 'c'; c++) {
            if (res.empty() || c != res.back()) {
                res.push_back(c);
                dfs(n - 1, res, happyStrings);
                res.pop_back();
            }
        }
    }   
};

int main() {
    TheKthLexicographicalStringOfAllHappyStringsOfLengthN sol;
    cout << sol.getHappyString(3, 9) << endl;
    return 0;
}

/*
Leetcode 1415. The k-th Lexicographical String of All Happy Strings of Length n

A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

    Input: n = 1, k = 3
    Output: "c"
    Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

    Input: n = 1, k = 4
    Output: ""
    Explanation: There are only 3 happy strings of length 1.

    Intuition:
    We can use DFS to generate all happy strings of length n.
    Then, we sort the happy strings in lexicographical order.
    Finally, we return the kth string in the sorted list.
    
    Time Complexity: O(3^n)
    Space Complexity: O(3^n)

    Approach steps:
    1. Use DFS to generate all happy strings of length n.
    2. Sort the happy strings in lexicographical order.
    3. Return the kth string in the sorted list.
    4. If k is greater than the number of happy strings of length n, return an empty string.
    5. Otherwise, return the kth string in the sorted list.
    6. Note that we need to subtract 1 from k because the list is 0-indexed.
    7. Return the kth string in the sorted list.

    Code steps:
        1. Use DFS to generate all happy strings of length n.
        2. Sort the happy strings in lexicographical order.
        3. If k is greater than the number of happy strings of length n, return an empty string.
        4. Otherwise, return the kth string in the sorted list.
        5. Note that we need to subtract 1 from k because the list is 0-indexed.
        6. Return the kth string in the sorted list.
        7. Otherwise, return an empty string.

*/