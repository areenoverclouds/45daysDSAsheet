/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, int> m;
    void countPaths(TreeNode* root, int &ans){
        if(!root) return;
        m[root->val]++;
        if(!root->left && !root->right){
            int count = 0;
            for(auto it:m) if(it.second % 2 != 0) count++;
            if(count <= 1) ans++;
        }
        countPaths(root->left, ans);
        countPaths(root->right, ans);
        m[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        countPaths(root, ans);
        return ans;
    }
};