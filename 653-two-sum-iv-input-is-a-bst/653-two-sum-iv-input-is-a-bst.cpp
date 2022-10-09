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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int>m;
        return DFS(root, m, k);
    }
    
    bool DFS(TreeNode* root, unordered_map<int, int>& m, int k){
        if(!root) return false;
        if(m.count(k - root->val)) return true;
        m[root->val]++;
        return DFS(root->left, m, k) || DFS(root->right, m, k);
    }
};