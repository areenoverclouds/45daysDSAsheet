class Solution {
public:
    bool search(vector<int> &v, int target){
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
        int i;
        for(i = 0; i < m.size(); i++){
            if(search(m[i], target)) return true;
        }
        return false;
    }
};