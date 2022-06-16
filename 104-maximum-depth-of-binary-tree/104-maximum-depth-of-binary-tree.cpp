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
    int depth(TreeNode* root){
        if(root == NULL) return 0;
        int lh = depth(root->left) + 1;
        int rh = depth(root->right) + 1;
        return std::max(lh, rh);
    }
    int maxDepth(TreeNode* root) {
        return depth(root);
   
    }
};