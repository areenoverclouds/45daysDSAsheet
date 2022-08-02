class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int i, j, ans = 0;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                dp[i][j] = matrix[i][j];
            }
        } 
        for(i = 1; i < m; i++){
            for(j = 1; j < n; j++){
                int val = std::min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                if(dp[i][j]) dp[i][j] += val;
            }
        }
        for(i = 0; i < m; i++) for(j = 0; j < n; j++) ans += dp[i][j];
        return ans;
    }
};