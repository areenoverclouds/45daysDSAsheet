class Solution {
public:
    int numWays(string s, int cur, vector<int> &dp){
        if(cur >= s.size()) return 1;
        if(s[cur] == '0') return 0;
        
        if(dp[cur] != -1) return dp[cur];
        
        dp[cur] = numWays(s, cur+1, dp);
        if(cur+1 < s.size() && ((s[cur] == '1') || 
                                (s[cur] == '2' && s[cur+1] < '7')))
            dp[cur] += numWays(s, cur+2, dp);
        
        return dp[cur];
    }
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        vector<int> dp(101, -1);
        return numWays(s, 0, dp);
    }
};