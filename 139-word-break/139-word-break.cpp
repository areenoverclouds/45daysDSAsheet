class Solution {
public:
int dp[301];
int breakit(set<string> s, int i, string target){
    if(i >= target.size()) return 1;
    if(dp[i] != -1) return dp[i];
    string temp = "";
    for(int j = i; j < target.size(); j++){
        temp += target[j];
        if(s.find(temp) != s.end()){
            if(breakit(s, j+1, target)) return dp[i] = 1;
        }
    }
    return dp[i] = 0;
}
bool wordBreak(string target, vector<string> arr) {
    set<string> s;
    memset(dp, -1, sizeof(dp));
    for(auto it : arr) s.insert(it);
    return breakit(s, 0, target);
}
};