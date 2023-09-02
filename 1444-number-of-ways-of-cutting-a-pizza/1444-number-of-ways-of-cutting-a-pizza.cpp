class Solution {
public:
    int mod=1000000000+7;
    int recur(int r, int c, int k,vector<string>& pizza, vector<vector<vector<int> > > &dp){
        if(r>=pizza.size() || c>=pizza[0].size())return 0;
        if(dp[r][c][k]!=-1)return dp[r][c][k];
        if(k==1){
            for(int i=r;i<pizza.size();i++){
                for(int j=c;j<pizza[0].size();j++){
                    if(pizza[i][j]=='A')return dp[r][c][k]=1;
                }
            }
            return dp[r][c][k]=0;
        }
        int ans=0;
        int cnt=0;
        for(int i=r;i<pizza.size();i++){
            for(int j=c;j<pizza[0].size() && cnt==0;j++){
                if(pizza[i][j]=='A'){
                    cnt++;
                    break;
                }
            }
            if(cnt>0){
                ans+=recur(i+1,c,k-1,pizza,dp)%mod;
                ans%=mod;
            }
        }
        cnt=0;
        for(int i=c;i<pizza[0].size();i++){
            for(int j=r;j<pizza.size() && cnt==0;j++){
                if(pizza[j][i]=='A'){
                    cnt++;
                    break;
                }
            }
            if(cnt>0){
                ans+=recur(r,i+1,k-1,pizza,dp)%mod;
                ans%=mod;
            }
        }
        
        return dp[r][c][k]=ans;
    }
    
    
    int ways(vector<string>& pizza, int k) {
        vector<vector<vector<int> > >dp(51, vector<vector<int>>(51, vector<int>(11, -1)));
        return recur(0,0,k,pizza,dp);
    }
};