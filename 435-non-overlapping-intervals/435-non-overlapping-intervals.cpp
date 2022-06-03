class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intv) {
        sort(intv.begin(),intv.end());
        int count = 0, l = 0, r = 1, n = intv.size();
        while(r < n){
            if(intv[l][1] <= intv[r][0]) //no overlap
            {
                l = r; r++;
            }
            else if(intv[l][1] <= intv[r][1]) //half overlap
            {
                count++;
                r++;
            }
            else //total overlap
            {
                count++;
                l = r;
                r++;
            }
        }
        return count;
    }
};