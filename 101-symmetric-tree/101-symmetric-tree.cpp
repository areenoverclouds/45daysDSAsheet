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
    bool mirror(TreeNode* l, TreeNode* r){
        if(!l && !r) return true;
        if(!l || !r) return false;
        
        if(l->val != r->val) return false;
        
        return mirror(l->left, r->right) && mirror(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        return mirror(root->left, root->right);
    }
};