#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int i = 0, j = 0;
        int maxLen = -1;
        unordered_map<char, int> mp;
        while(j < n){
            mp[s[j]]++;
            if(mp.size() < k){
                j++;
            }
            else if(mp.size() == k){
                maxLen = max(maxLen, j - i + 1);
                j++;
            }
            else if(mp.size() > k){
                while(mp.size() > k){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxLen;
    }
};

int main(){
    string s = "aabacbebebe";
    int k = 3;
    Solution obj;
    cout << obj.longestKSubstr(s, k) << endl;
    return 0;
}