class Solution {
public:
    int n;
    
    int recur(int ind, int la, string& s, vector<vector<int > >& dp, int &k){
        if(ind>=n)return 0;
        if(dp[ind][la]!=-1)return dp[ind][la];
        int l=-1, r=-1;
        if(abs(s[ind]-'a'-la)<=k){
            dp[ind][la]=max(1+recur(ind+1,s[ind]-'a',s,dp,k), recur(ind+1,la,s,dp,k));
        }
        else{
            dp[ind][la]=recur(ind+1,la,s,dp,k);
        }
        return dp[ind][la];
    }
    
    int longestIdealString(string s, int k) {
        n=s.size();
        vector<vector<int> > dp(n+1,vector<int>(26,-1));
        int ans=0;
        for(int i=0;i<26;i++){ans=max(ans,recur(0,i,s,dp,k));}
        return ans;
    }
};