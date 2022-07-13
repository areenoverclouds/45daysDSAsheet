/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root) q.push(root);
        while(!q.empty()){
          int size = q.size();
            vector<int> level;
            while(size--){
                auto ele = q.front();
                q.pop();
                level.push_back(ele->val);
                for(auto it: ele->children){
                    q.push(it);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};