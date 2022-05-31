class Solution {
public:
    bool validPalindrome(string s) {
        int i;
        string st1 = s, st2 = s;
        for(i=0;i<s.size()/2;i++){
            if(s[i] != s[s.size()-1-i]){
                st1.erase(st1.begin()+st1.size()-1-i);
                st2.erase(st2.begin()+i);
                break;
            }
        }
        
        int flag = 1;
        for(i=0;i<st1.size()/2;i++){
            if(st1[i] != st1[st1.size()-1-i]){
                flag = 0;
                break;
            }
        }
        if(flag) return true;
        
        flag = 1;
        for(i=0;i<st2.size()/2;i++){
            if(st2[i] != st2[st2.size()-1-i]){
                flag = 0;
                break;
            }
        }
        
        if(flag) return true;
        return false;
    }
};