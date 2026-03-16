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

#include <iostream>
#include <unordered_map>
using namespace std;

class KSP {
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

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    KSP ksp;
    int k = 5;
    int count = ksp.countAllPaths(root, k);
    cout << "Number of paths with sum " << k << " is: " << count << endl;
    
    return 0;
}