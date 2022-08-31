class Solution {
public:
    int n, m;
void dfs(vector<vector<int>>& heights, vector<vector<bool>> &vis, int i, int j) {
    
    vis[i][j] = true;  
    if(i+1 < n && !vis[i+1][j] && heights[i+1][j] >= heights[i][j]) {
        dfs(heights, vis, i+1, j);  //Down
    }
    if(i-1 >= 0 && !vis[i-1][j] && heights[i-1][j] >= heights[i][j]) {
        dfs(heights, vis, i-1, j);  //Up
    }
    if(j+1 < m && !vis[i][j+1] && heights[i][j+1] >= heights[i][j]) {
        dfs(heights, vis, i, j+1);  //Right
    }
    if(j-1 >= 0 && !vis[i][j-1] && heights[i][j-1] >= heights[i][j]) {
        dfs(heights, vis, i, j-1);  //Left
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    n = heights.size();  //Rows
    m = heights[0].size();  //Columns
    
    vector<vector<bool>> pacific(n, vector<bool> (m, false));  
    vector<vector<bool>> atlantic(n, vector<bool> (m, false));
    
    for(int i=0; i<n; i++) {    
        dfs(heights, pacific, i, 0);   
        dfs(heights, atlantic, i, m-1);  
    }
    
    for(int i=0; i<m; i++) {  
        dfs(heights, pacific, 0, i);  
        dfs(heights, atlantic, n-1, i); 
    }
    
    vector<vector<int>> v;  
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(pacific[i][j] && atlantic[i][j]) { 
                v.push_back({i, j}); 
            }
        }
    }
    
    return v;  //Return the vector
}
};