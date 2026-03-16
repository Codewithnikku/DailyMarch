/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void dfs(Node* root, long long currSum, int k, 
             unordered_map<long long,int>& mp, int &count) {
        
        if (!root) return;
        
        currSum += root->data;
        
        // Check if there exists a prefix sum we can remove
        if (mp.find(currSum - k) != mp.end()) {
            count += mp[currSum - k];
        }
        
        mp[currSum]++;
        
        dfs(root->left, currSum, k, mp, count);
        dfs(root->right, currSum, k, mp, count);
        
        mp[currSum]--; // Backtrack
    }

    int countAllPaths(Node *root, int k) {
        unordered_map<long long,int> mp;
        mp[0] = 1;
        
        int count = 0;
        dfs(root, 0, k, mp, count);
        
        return count;
    }
};