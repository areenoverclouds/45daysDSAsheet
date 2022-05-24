class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j = 1;
        int count = 0;
        for(i=1;i<nums.size();i++){
            j = i;
            while(nums[j] <= nums[i-1]){
                j++;
                if((j) >= nums.size())
                    return count+1;
            }
            nums[i] = nums[j];
            count++;
        }
        return count+1;
    }
};