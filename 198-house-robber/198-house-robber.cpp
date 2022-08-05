class Solution {
public:
    int pickordont(vector<int> &nums, int cur, vector<int> &dp){
        if(cur == 0) return nums[cur];
        if(cur < 0) return 0;
        
        if(dp[cur] != -1) return dp[cur];
        
        int pick = nums[cur] + pickordont(nums, cur-2, dp);
        int dont = pickordont(nums, cur-1, dp);
        
        return dp[cur] = max(pick, dont);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), -1);
        return pickordont(nums, nums.size()-1, dp);
    }
};