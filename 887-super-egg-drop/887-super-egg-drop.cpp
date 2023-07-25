class Solution {
public:
    
    int recur(int floors, int eggs, vector<vector<int > >& dp){
        if(eggs==1)return floors;
        if(floors<=1)return floors;
        if(dp[floors][eggs]!=-1)return dp[floors][eggs];
        int l=1, r=floors;
        
        while(r-l>1){
            int mid=l+(r-l)/2;
            int val1=recur(mid-1,eggs-1, dp);
            int val2=recur(floors-mid, eggs, dp);
            if(val1<val2){
                l=mid;
            }
            else if(val1>val2){
                r=mid;
            }
            else{
                l=mid;
                r=mid;
            }
        }
        
        int ans=INT_MAX;
        
        for(int i=l;i<=r;i++){
            ans=min(ans,1+max(recur(i-1,eggs-1,dp), recur(floors-i,eggs,dp)));
        }
        
        return dp[floors][eggs]=ans;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int> >dp(n+5, vector<int>(k+5,-1));
        return recur(n,k,dp);
    }
};