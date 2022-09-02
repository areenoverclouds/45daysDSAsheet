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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double> ans;
        queue<TreeNode*> level;
        level.push(root);
        while(!level.empty()){
            int size = level.size();
            int n = size;
            double sum = 0;
            while(size--){
                TreeNode* cur = level.front();
                level.pop();
                sum += cur->val;
                if(cur->left) level.push(cur->left);
                if(cur->right) level.push(cur->right);
            }
            ans.push_back((double)sum/n);
        }
        return ans;
    }
};