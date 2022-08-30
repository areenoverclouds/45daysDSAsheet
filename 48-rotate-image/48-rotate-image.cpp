class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int i, j;
        int n = v.size(), m = v[0].size();
        
        for(i = 0; i < n/2; i++){
            vector<int> temp = v[i];
            v[i] = v[n-1-i];
            v[n-1-i] = temp;
        }
        
        // transpose
        vector<vector<int>> trap = v;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                trap[j][i] = v[i][j];
            }
        }
        
        v = trap;
    }
};