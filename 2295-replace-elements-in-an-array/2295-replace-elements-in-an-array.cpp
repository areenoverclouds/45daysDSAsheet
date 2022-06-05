
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& opr) {
        map<int, int> mp;
        int i;
		//insert element and index in map
        for(i=0; i<nums.size(); i++){
            mp.insert(make_pair(nums[i], i));
        }
		
        for(i=0; i<opr.size(); i++){
            auto pos = mp.find(opr[i][0]);
            int put = opr[i][1], at = pos->second;
            nums[at] = put;
			//erase the current occurence in map
            mp.erase(pos->first);
			//add new pair in map
            mp.insert(make_pair(put, at));
        }
        return nums;
    }
};