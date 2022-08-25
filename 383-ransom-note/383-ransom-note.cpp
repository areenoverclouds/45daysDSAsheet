class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i;
        int freq[26] ={0};
        
        for(i=0;i<magazine.size();i++)
            freq[magazine[i]-'a']++;
        
        for(i=0;i<ransomNote.size();i++){
            freq[ransomNote[i]-'a']--;
            
            if(freq[ransomNote[i]-'a'] < 0)
                return false;
        }
            
        return true;
    }
};