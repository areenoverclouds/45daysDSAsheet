class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end) return 0;
        unordered_set<string> st(bank.begin(), bank.end());
        if(st.count(end) == 0) return -1;
        int count = 1;
        vector<char> mut_opt = {'A', 'C', 'G', 'T'};

        queue<string> q;
        q.push(start);
        
        while(!q.empty()){
            int n = q.size();
            for(int j = 0 ; j < n; j++){
                string s = q.front();
                q.pop();
                for(int i = 0 ; i < s.size(); i++){ 
                    char org = s[i];
                    for(int k = 0 ; k < mut_opt.size(); k++){
                        if(org != mut_opt[k]) s[i] = mut_opt[k];
                        if(s == end)return count;
                        if(st.count(s) > 0){
                            q.push(s);
                            st.erase(s);
                        }
                    }
                    s[i] = org;
                }
            }
            count++;
        }
        return -1;
    }
};