class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i;
        
        //sorting
        sort(nums.begin(),nums.end());
        for(i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1])
                return nums[i];
        }
        return nums[i];
        
        //xor
        
        
        //add
        int add = 0;
        for(i=0;i<nums.size();i++) add += nums[i];
        int sum = nums.size() * (nums.size()+1) / 2;
        return (add-sum);
    }
};