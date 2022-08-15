class Solution {
public:
    int romanToInt(string s) {
        int i, num;
        num=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='M')
                num+=1000;
            if(s[i]=='D')
                    num+=500;
            
            if(s[i]=='C'){
                if(i+1 < s.size() && (s[i+1]=='M' || s[i+1]=='D'))
                    num-=100;
                else
                    num+=100;
            }
            if(s[i]=='L')
                num+=50;
            if(s[i]=='X'){
                if(i+1 < s.size() && (s[i+1]=='L' || s[i+1]=='C'))
                    num-=10;
                else
                    num+=10;
            }
            if(s[i]=='V')
                num+=5;
            if(s[i]=='I'){
                if(i+1 < s.size() && (s[i+1]=='V' || s[i+1]=='X'))
                    num-=1;
                else
                    num+=1;
            }
        }
        
        return num;
    }
};