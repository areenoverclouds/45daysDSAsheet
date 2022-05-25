class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, nz, j = 0, flag = 0;
        for(i=0;i<nums.size();i++){
            if(j >= nums.size()) return;
            if(nums[i] == 0){
                if(!flag) j = i;
                flag = 1;
                while(nums[j] == 0 && (j+1) < nums.size()) j++;
                if((j+1) >= nums.size() && nums[j] == 0) return;
                nums[i] = nums[j];
                nums[j] = 0;
                j++;
            }
        }
    }
};