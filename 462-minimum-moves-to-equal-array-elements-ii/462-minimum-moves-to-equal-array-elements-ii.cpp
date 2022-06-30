class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int val = nums[nums.size()/2];
        int moves = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < val){
                moves += (val - nums[i]);
            }
            else if(nums[i] > val){
                moves += (nums[i] - val);
            }
        }
        return moves;
    }
};