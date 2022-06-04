class Solution {
public:
    int minCost(string colors, vector<int>& nt) {
        stack<char> stc;
        stack<int> snt;
        int i, ans = 0;
        stc.push(colors[0]);
        snt.push(nt[0]);
        for(i=1; i<colors.size(); i++){
            if(!stc.empty() && stc.top() == colors[i]){
                if(snt.top() < nt[i]){
                    ans += snt.top();
                    snt.pop();
                    stc.pop();
                    stc.push(colors[i]);
                    snt.push(nt[i]);
                }
                else{
                    ans += nt[i];
                }
            }
            else{
                stc.push(colors[i]);
                snt.push(nt[i]);
            }
        }
        return ans;
    }
};