#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

class smallestWindowContainingAllChars {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int n = s.size();
        int m = p.size();
        if (n < m) {
            return "";
        }
        int i = 0, j = 0;
        int minLen = INT_MAX;
        string minWindow = "";
        unordered_map<char, int> freq;
        for (int i = 0; i < m; i++) {
            freq[p[i]]++;
        }
        int count = freq.size();
        while (j < n) {
            if (freq.find(s[j]) != freq.end()) {
                freq[s[j]]--;
                if (freq[s[j]] == 0) {
                    count--;
                }
            }
            while (count == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    minWindow = s.substr(i, minLen);
                }
                if (freq.find(s[i]) != freq.end()) {
                    freq[s[i]]++;
                    if (freq[s[i]] > 0) {
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        return minWindow;
    }
};

int main() {
    smallestWindowContainingAllChars swcac;
    string s = "ADOBECODEBANC";
    string p = "ABC";
    cout << swcac.minWindow(s, p) << endl;
    return 0;
}

/*
Greeks For Greeks: Smallest Window Containing All Characters

Intuition:
We need to find the smallest window in the string s that contains all the characters of the string p.
Approach:
We can use a sliding window approach to solve this problem.
We can maintain a window that contains all the characters of the string p.
We can keep track of the minimum length of the window.
Optimal Approach:
We can use a sliding window approach to solve this problem in O(n) time.
We can maintain a window that contains all the characters of the string p.
We can keep track of the minimum length of the window.

Approach:
We can use a sliding window approach to solve this problem.
We can maintain a window that contains all the characters of the string p.
We can keep track of the minimum length of the window.

Code Explaination:
    step 1: Initialize i = 0, j = 0, minLen = INT_MAX, minWindow = "", freq = {}
    step 2: While j < n:
        step 2.1: freq[s[j]]++
        step 2.2: If freq[s[j]] == 0:
            step 2.2.1: count--
        step 2.3: While count == 0:
            step 2.3.1: If j - i + 1 < minLen:
                step 2.3.1.1: minLen = j - i + 1
                step 2.3.1.2: minWindow = s.substr(i, minLen)
            step 2.3.2: If freq[s[i]] > 0:
                step 2.3.2.1: count++
            step 2.3.3: freq[s[i]]++
            step 2.3.4: i++
        step 2.4: j++
    step 3: Return minWindow

    Time Complexity: O(n)
    Space Complexity: O(m)

*/