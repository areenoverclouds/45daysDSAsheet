class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //21-06-22
        //BUCKET SORT O(N)
        
        unordered_map<int, int> mp;
        for(auto i : nums) mp[i]++;
        
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto i : mp) bucket[i.second].push_back(i.first);
        
        reverse(bucket.begin(), bucket.end());
        vector<int> res;
        for(auto i : bucket){
            if(!k) break;
            for(auto j : i)
                res.push_back(j);
            k -= i.size();
        }
        
        return res;
        //----9/04/2022
        //map -> pq
        /*int i;
        unordered_map<int,int> mp;
        for(i=0;i<nums.size();i++) mp[nums[i]]++;
        
        multimap<int,int> rev;
        for(auto it : mp) rev.insert({it.second,it.first});
        vector<int> ans;
        
        if(k >= rev.size()){
            for(auto itr = rev.begin(); itr != rev.end(); itr++)
                ans.push_back(itr->second);
            return ans;
        }
        
        int size = rev.size()-k;
        
        map<int, int>::iterator itr;
        itr = rev.begin();
        
        while(size--) itr++;
        
        for(itr; itr != rev.end(); itr++)
            ans.push_back(itr->second);
        
        return ans;*/
        
        //----27/1/2022
        /*unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        priority_queue<pair<int,int>> pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;*/
    }
};
     