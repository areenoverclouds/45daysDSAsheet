class Solution {
public:
int m,n;
    int target;
     int dp[105][25][105];
    int find_ans(int i,int prev,int cnbr,vector<int>&houses,vector<vector<int>>&cost)
    {
        if(i==m){
        
            if(cnbr>target or cnbr<target)return 1e8;
            
            return 0;
            
        }
        int &fans=dp[i][prev][cnbr];
        if(fans!=-1)return fans;
        if(houses[i]!=0){
            if(i==0 or houses[i]!=prev){
                return fans=find_ans(i+1,houses[i],cnbr+1,houses,cost);
            }
            else{
                return fans=find_ans(i+1,prev,cnbr,houses,cost);
            }
        }
        int ans=1e8;
        if(i!=0){
        int op1=find_ans(i+1,prev,cnbr,houses,cost);
             if(op1!=1e8){
                 ans=min(ans,cost[i][prev-1]+op1);
             }
        }
        for(int col=1;col<=n;col++){
            if(prev!=col){
                int op=find_ans(i+1,col,cnbr+1,houses,cost);
                if(op!=1e8){
                    ans=min(ans,cost[i][col-1]+op);
                }
            }
        }
        if(ans==1e8)return fans= 1e8;
        return fans= ans;
        
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->m=m;
        this->n=n;
        this->target=target;
        memset(dp,-1,sizeof dp);
        int ans= find_ans(0,0,0,houses,cost);
        if(ans==1e8)return -1;
        return ans;
    }
};