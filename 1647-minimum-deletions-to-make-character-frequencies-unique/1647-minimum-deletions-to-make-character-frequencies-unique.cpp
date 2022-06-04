class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        int i, ans = 0;
        
        //fill the frequency array
        for(i=0; i<s.size(); i++){
            freq[s[i] - 'a']++;
        }
        
        //sort in descending order
        sort(freq.rbegin(), freq.rend());
        
        //counting duplicate frequencies in ans
        for(i=1; i<freq.size(); i++){
            if(freq[i] == 0) break;
            
            while(freq[i] >= freq[i-1]){
                freq[i]--;
                ans++;
            }
            
            if(freq[i] <= 0) freq[i] = 1;
        }
        
        return ans;
    }
};