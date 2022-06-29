class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st = 0, mid = 0, end = nums.size()-1;
        while(mid <= end){
            if(nums[mid] == 0){
                swap(nums[mid], nums[st]);
                st++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[end]);
                end--;
              //  mid++;
            }
        }
    }
};