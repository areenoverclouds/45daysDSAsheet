class Solution {
public:
    string reverseWords(string s) {
        string ret = "", word = "";
        for(auto ch: s){
            if(ch == ' '){
                reverse(word.begin(), word.end());
                ret += word;
                ret.push_back(' ');
                word = "";
            }
            else{
                word.push_back(ch);
            }
        }
        reverse(word.begin(), word.end());
        ret += word;
        return ret;
    }
};