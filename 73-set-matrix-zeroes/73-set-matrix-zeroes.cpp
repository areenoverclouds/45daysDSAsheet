class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> toseti, tosetj;
        int i, j;
        
        for(i=0;i<matrix.size();i++){
            vector<int> cols = matrix[i];
            for(j=0;j<cols.size();j++){
                if(cols[j] == 0){
                    toseti.insert(i);
                    tosetj.insert(j);
                }
            }
        }
        
       // for(auto itr = toseti.begin(); itr!=toseti.end(); itr++)
       //     cout<<*itr;
        cout<<*toseti.find(i);
        for(i=0;i<matrix.size();i++){
            vector<int> cols = matrix[i];
            if(toseti.find(i) != toseti.end()){
                for(j=0;j<cols.size();j++) matrix[i][j] = 0;
            }
            else{
                for(j=0;j<cols.size();j++){
                    if(tosetj.find(j) != tosetj.end()) matrix[i][j] = 0;
                }
            }
        }
    }
};