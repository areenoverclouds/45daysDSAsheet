class Solution {
public:
    int dp[601][101][101];
    int ans = 0;
    int maxSubset(vector<string> &strs, int m, int n, int pos){
        if(pos == strs.size()) return 0;
        if(m == 0 && n == 0) return 0;
        
        int zeros = 0, ones = 0;
        for(auto it: strs[pos]){
            if(it == '0') zeros++;
            else ones++;
        }
        
        if(dp[pos][m][n] != -1) return dp[pos][m][n];
        
        int with, without;
        if(zeros > m || ones > n) return dp[pos][m][n] = maxSubset(strs, m, n, pos+1); 
        
        // take  
        with = 1 + maxSubset(strs, m-zeros, n-ones, pos+1);
        // don't take
        without =  maxSubset(strs, m, n, pos+1);
        
        return dp[pos][m][n] = std::max(with , without);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return maxSubset(strs, m, n, 0);
    }
};