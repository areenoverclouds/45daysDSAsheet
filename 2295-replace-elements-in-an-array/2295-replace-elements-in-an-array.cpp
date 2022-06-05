
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& opr) {
        map<int, int> mp;
        int i;
        for(i=0;i<nums.size();i++){
            mp.insert(make_pair(nums[i], i));
        }
        for(i=0;i<opr.size();i++){
            auto pos = mp.find(opr[i][0]);
            int put = opr[i][1], to = pos->second;
            nums[to] = put;
            mp.erase(pos->first);
            mp.insert(make_pair(put, to));
        }
        return nums;
    }
};