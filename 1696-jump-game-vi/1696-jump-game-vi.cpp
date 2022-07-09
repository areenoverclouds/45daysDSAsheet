class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n=nums.size();

        pq.push({nums[0],0});
        
        int largest = nums[0];
                
        for(int i=1;i<n;i++){
            largest = 0;
            
            while(!pq.empty()){
                while(pq.top().second < max(0,i-k))
                    pq.pop();
                largest = nums[i]+pq.top().first;
                break;
            }
            pq.push({largest,i});
        }
        return largest;
    }
};