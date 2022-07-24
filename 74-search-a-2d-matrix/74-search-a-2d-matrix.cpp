class Solution {
public:
    bool search(vector<int> v, int target){
        int st = 0, end = v.size()-1, mid;
        while(st <= end){
            mid = (st+end)/2;
            if(v[mid] == target) return true;
            else if(v[mid] < target) st = mid+1;
            else end = mid-1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int r = m.size(), c = m[0].size();
        int rowst = 0, rowend = r-1;
        while(rowst <= rowend){
            int rowmid = (rowst+rowend)/2;
            if(m[rowmid][0] <= target && m[rowmid][c-1] >= target){
                return search(m[rowmid], target);
            }
            else if(target > m[rowmid][c-1]) rowst = rowmid+1;
            else rowend = rowmid-1;
        }
        return false;
    }
};