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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root) q.push(root);
        int t = 1;
        while(!q.empty()){
            int level_size = q.size();
            vector<int> level;
            while(level_size-- > 0){
                TreeNode* cur = q.front(); 
                q.pop();
                level.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            //for(auto it : level) cout<<it<<' ';
           // cout << '\n';
            if(t%2 == 0){
                reverse(level.begin(), level.end());
            }
            t++;
            ans.push_back(level);
        }
        return ans;
    }
};