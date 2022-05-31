class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int,int> mp;
		
        for(int i=0; i<nums.size(); i++)
            mp.insert(pair<int, int>(nums[i], i));
       
	    auto it1 = mp.begin();
        for(; it1 != mp.end(); it1++){
	       //check if (target - current element) is present
            if (mp.find(target - it1->first) != mp.end() && 
			    //make sure it is not the current element itself
			    mp.find(target - it1->first) != it1)
				break;
        }
        return {it1->second, mp.find(target - it1->first)->second};
    }
};