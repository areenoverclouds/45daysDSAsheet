class Solution {
public:
    int convert(string &w1, string &w2, int i, int j, vector<vector<int>>& dp){
        if(i == w1.size()) return w2.size() - j;
        if(j == w2.size()) return w1.size() - i;
        int ins, del, rep;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(w1[i] == w2[j]){
            dp[i][j] = convert(w1, w2, i+1, j+1, dp);
        }
        else{
            ins = 1 + convert(w1, w2, i, j+1, dp);
            del = 1 + convert(w1, w2, i+1, j, dp);
            rep = 1 + convert(w1, w2, i+1, j+1, dp);
            dp[i][j] = std::min({ins, del, rep});
        }
        
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        if(word1.size() == 0) return word2.size();
        if(word2.size() == 0) return word1.size();
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return convert(word1, word2, 0, 0, dp);
    }
};