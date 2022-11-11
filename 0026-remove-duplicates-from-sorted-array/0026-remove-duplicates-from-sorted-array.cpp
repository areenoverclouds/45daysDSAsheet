class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int> all;
        all.insert(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(all.find(nums[i]) != all.end()){
                nums.erase(nums.begin()+i);
                i--;
            }
            all.insert(nums[i]);
        }
        return nums.size();
        
        /*int i, j = 1;
        int count = 1;
        for(i=1;i<nums.size();i++){
            j = i;
            while(nums[j] <= nums[i-1]){
                j++;
                if((j) >= nums.size())
                    return count;
            }
            nums[i] = nums[j];
            count++;
        }
        return count;*/
    }
};