bool cmp(vector<int> &pointA, vector<int> &pointB){
        int distA = pointA[0]*pointA[0] + pointA[1]*pointA[1];
        int distB = pointB[0]*pointB[0] + pointB[1]*pointB[1];
        return (distA < distB);
    }

class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), cmp);
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(points[i]);    
        }
        return ans;
    }
};