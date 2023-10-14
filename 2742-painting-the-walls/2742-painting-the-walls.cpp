class Solution {
public:
    
    int dp[501][501];
    
    int recur(int ind, int walls, vector<int>& c, vector<int>& t){
        if(walls<=0)return 0;
        if(ind>=c.size())return 1000000000;
        if(dp[ind][walls]!=-1)return dp[ind][walls];
        int ans=INT_MAX;
        ans=min(c[ind]+recur(ind+1,walls-t[ind]-1,c,t), recur(ind+1,walls,c,t));
        return dp[ind][walls]=ans;
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                dp[i][j]=-1;
            }
        }
        return recur(0,cost.size(), cost,time);
    }
};