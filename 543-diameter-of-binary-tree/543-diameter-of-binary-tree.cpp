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
    int diameter(TreeNode* root){
        if(root == NULL) return 0;
        int lheight = diameter(root->left);
        int rheight = diameter(root->right);
        ans = std::max(ans, lheight + rheight + 1);
        return 1 + std::max(lheight, rheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        diameter(root);
        return ans-1;
    }
};