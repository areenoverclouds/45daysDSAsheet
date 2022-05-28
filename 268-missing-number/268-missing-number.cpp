class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums) sum += i;
        int diff = (nums.size()*(nums.size()+1))/2 - sum;
        return (diff >= 0) ? diff : nums.size();
    }
};