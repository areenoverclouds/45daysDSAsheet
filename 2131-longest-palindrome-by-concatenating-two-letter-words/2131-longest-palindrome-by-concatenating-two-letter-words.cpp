class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        map<string, int> have;
        map<string, int> haveth;
        
        for(auto w: words){
            if(w[0] == w[1]) haveth[w]++;
            else have[w]++;
        }
        
        int len = 0, mids = 0;
        
        for(auto word: words){
            if(word[0] == word[1]);
            else{
                string rev = word;
                reverse(rev.begin(), rev.end());
                auto ele = have.find(rev);
                auto cur = have.find(word);
                if(ele != have.end() && ele->second > 0 && cur->second > 0){
                    len += 4;
                    ele->second--;
                    cur->second--;
                }
            }
        }
        
        for(auto ele: haveth){
            if(ele.second % 2 == 0) len += ele.second * 2;
            else if(ele.second == 1){
                mids = 2;
            }
            else{
                len += (ele.second - 1) * 2;
                mids = 2;
            }
        }
        
        return len + mids;
    }
};