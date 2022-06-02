class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(k == num.size()) return "0";
        if(k == 0) return num;
        
        stack<char> st;
        string ans = "";
        int i, flag = 0;
        st.push(num[0]);
        
        for(i=1;i<num.size();i++){

            while(!st.empty() && (st.top() > num[i]) && k){
                st.pop();
                k--;
            }
            
            st.push(num[i]);
            
            if(st.size() == 1 && num[i] == '0') st.pop();
            
        }
        
        while(k-- && !st.empty()) st.pop();
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        for(i=ans.size()-1; i>=0; i--){
            if(ans[i] == '0') ans.pop_back();
            else break;
        }
        reverse(ans.begin(), ans.end());
        if(ans == "") ans = "0";
        return ans;
    }
};