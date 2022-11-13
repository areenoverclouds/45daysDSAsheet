class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";
        for(auto ch: s){
            if(ch == ' ' && temp != ""){
                words.push_back(temp);
                words.push_back(" ");
                temp = "";
            }
            else if(ch != ' ') temp += ch;
        }
        words.push_back(temp);
        temp = "";
        for(int i = words.size()-1; i >= 0; i--) temp += words[i];
        int st = 0;
        while(temp[st] == ' ') st++;
        return temp.substr(st, temp.size());
    }
};