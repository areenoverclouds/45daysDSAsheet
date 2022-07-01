bool cmp(vector<int> &b1, vector<int> &b2){
    if(b1[1] != b2[1]) return b1[1] > b2[1];
    else return b1[0] < b2[0];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        sort(bt.begin(), bt.end(), cmp);
        int i, j, ans = 0;
        for(i = 0; i < bt.size(); i++){
            while(bt[i][0] > 0){
                ans += bt[i][1];
                bt[i][0]--;
                ts--;
                if(ts <= 0) break;
            }
            if(ts <= 0) break;
            //cout<<bt[i][0]<<' '<<bt[i][1]<<'\n';            
        }
        return ans;
    }
};