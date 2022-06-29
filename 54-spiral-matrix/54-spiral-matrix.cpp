class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i, j, colst = 0, colend = matrix[0].size()-1;
        int rowst = 0, rowend = matrix.size()-1;
        int times = 0, elements = matrix.size()*matrix[0].size();
        vector<int> ans;
        while(rowst <= rowend){
            cout<<rowst<<' '<<rowend<<' '<<colst<<' '<<colend<<'\n';
            // to right
            for(j = colst; j <= colend; j++){
                ans.push_back(matrix[rowst][j]);
                times++;
            }
            rowst++; 
            if(times >= elements) break;
            
            // to down
            for(j = rowst; j <= rowend; j++){
                ans.push_back(matrix[j][colend]);
                times++;
            }
            colend--; 
            if(times >= elements) break;
            
            // to left
            for(j = colend; j >= colst; j--){
                ans.push_back(matrix[rowend][j]);
                 times++;
            }
            rowend--;
            if(times >= elements) break;
            
            // to up
            for(j = rowend; j >= rowst; j--){
                ans.push_back(matrix[j][colst]);
                times++;
            }
            colst++; 
            if(times >= elements) break;
        }
        return ans;
    }
};