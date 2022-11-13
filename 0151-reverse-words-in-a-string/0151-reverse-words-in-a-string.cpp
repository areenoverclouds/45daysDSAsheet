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
        while(words[words.size()-1] == " ") words.pop_back();
        reverse(words.begin(), words.end());
        temp = "";
        for(auto w: words) temp += w;
        int st = 0;
        while(temp[st] == ' ') st++;
        return temp.substr(st, temp.size());
    }
};