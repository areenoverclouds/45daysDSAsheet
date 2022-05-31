class Solution {
public:
    bool isValid(string s) {
        int i;
        stack<char> st;
        
        for(i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if(!st.empty() && ((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[')))
                    st.pop();
                else
                    return false;
            
        }
        
        if(st.empty())
            return true;
        
        return false;
    }
};