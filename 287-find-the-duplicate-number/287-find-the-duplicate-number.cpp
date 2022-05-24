class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i;
        
        //sorting
       /* sort(nums.begin(),nums.end());
        for(i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1])
                return nums[i];
        }
        return nums[i];
        
        //xor
        //not on more than 2 duplicates
        int x = 0, y = 0;
        for(i=0;i<nums.size();i++){
            x = x xor nums[i];
            y = y xor i;
        }
        return abs(x-y);
        */
        //floyds cycle but here
        int slow = nums[0], fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow; 
        
        //add
        //not for more than 1 duplicate
        int add = 0;
        for(i=0;i<nums.size();i++) add += nums[i];
        int sum = (nums.size() * (nums.size()-1)) / 2;
        return (add - sum);
    }
};