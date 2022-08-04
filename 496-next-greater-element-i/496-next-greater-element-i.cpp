class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        stack<int> st;
        vector<int> ans(nums1.size(), -1);
        for(int i = nums2.size()-1; i >= 0; i--){
            if(st.empty()){
                st.push(nums2[i]);
                continue;
            }
            while(!st.empty() && st.top() < nums2[i]) st.pop();
            if(!st.empty() && st.top() > nums2[i]){
                mp.insert({nums2[i], st.top()});
            }
            st.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++){
            auto it = mp.find(nums1[i]);
            if(it != mp.end()) ans[i] = it->second;
        }
        return ans;
    }
};