class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        int i;
        for(i = 1; i < nums.size(); i++){
            if(nums[i] > ans[ans.size()-1]){
                ans.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }
};