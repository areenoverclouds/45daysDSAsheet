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
    int ans = 0;
    void sum(TreeNode* root, int lr){
        if(!root) return;
        if(!root->left && !root->right && lr){
            ans += root->val;
        }
        
        sum(root->left, 1);
        sum(root->right, 0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum(root, 0);
        return ans;
    }
};