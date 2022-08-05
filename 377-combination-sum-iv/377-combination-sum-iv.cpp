class Solution {
public:
    int sum4(vector<int> nums,int target, vector<int> &dp){
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        dp[target] = 0;
        for(auto num : nums){
            if(num <= target) dp[target] += sum4(nums, target - num, dp);
        }
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return sum4(nums, target, dp);
    }
};