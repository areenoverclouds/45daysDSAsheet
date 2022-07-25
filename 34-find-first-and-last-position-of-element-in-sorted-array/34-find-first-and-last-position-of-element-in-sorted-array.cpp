class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto u = upper_bound(nums.begin(), nums.end(), target);
        auto l = lower_bound(nums.begin(), nums.end(), target);
        if(u == l && u == nums.end()) return {-1, -1};
        else if(u == l && nums[int(l - nums.begin())] != target) return {-1, -1};
        return {int(l - nums.begin()), int(u - nums.begin())-1};
    }
};