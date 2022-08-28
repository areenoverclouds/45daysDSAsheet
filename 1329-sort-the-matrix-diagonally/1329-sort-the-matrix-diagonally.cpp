class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        int i, j, r, c;
        for(r = 0; r < m; r++){
            priority_queue<int, vector<int>, greater<int>> temp;
            for(j = 0,i = r; j < n && i < m ; j++,i++) temp.push(mat[i][j]);
            j = 0; i = r;
            while(!temp.empty() && j < n && i < m){
                mat[i][j] = temp.top();
                temp.pop();
                i++; j++;
            }
                    
        }
        for(c = 1; c < n; c++){
            priority_queue<int, vector<int>, greater<int>> temp;
            for(i = 0, j = c; j < n && i < m; i++, j++) temp.push(mat[i][j]);
            i = 0; j = c;
            while(!temp.empty() && i < m && j < n){
                mat[i][j] = temp.top();
                temp.pop();
                i++; j++;
            }
        }
        return mat;
    }
};