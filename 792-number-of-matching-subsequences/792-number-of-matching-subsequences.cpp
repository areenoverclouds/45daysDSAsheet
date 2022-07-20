class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int i, ans = 0;
        vector<vector<int>> freq(26);
        for(i = 0; i < s.size(); i++) freq[s[i]-'a'].push_back(i);
        
        for(auto word : words){
            int flag = 1;
            int x = -1;
            for(char c : word){
                auto it = upper_bound(freq[c-'a'].begin(), freq[c-'a'].end(), x);
                if(it != freq[c-'a'].end()) x = *it;
                else{
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) ans++;
        }
        return ans;
    }
};