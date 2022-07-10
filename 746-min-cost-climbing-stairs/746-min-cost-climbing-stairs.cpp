class Solution {
public:
    vector<int> dp;
    int solve (vector<int>& cost, int n) {
        if (n < 2) return cost[n];
        
        if (dp[n] != -1) return dp[n];
        
        return dp[n] = cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n + 1, -1);
        return min(solve(cost, n - 1), solve(cost, n - 2));
    
    }
};