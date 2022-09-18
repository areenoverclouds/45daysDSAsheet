class Solution {
public:
    int trap(vector<int>& a) {
        stack<int> st;
        int i, cur, len, ans=0;
        for(i=0;i<a.size();i++){
            while(!st.empty() && a[st.top()] < a[i]){
                cur=st.top();
                st.pop();
                
                if(st.empty())
                  break;
                
                len=i-st.top()-1;
                ans+=(min(a[st.top()],a[i])-a[cur] )* len;
            }
             
            st.push(i);
               
        }
        return ans;
    }
};