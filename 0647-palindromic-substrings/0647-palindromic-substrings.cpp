class Solution {
public:
    
    int recur(int l, int r, string& s, vector<vector<int> >& dp){
        if(l>=r)return 1;
        if(dp[l][r]!=-1)return dp[l][r];
        if(s[l]==s[r]){
            return dp[l][r]=recur(l+1,r-1,s,dp);
        }
        return dp[l][r]=0;
    }
    
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int> >dp(n, vector<int>(n,-1));
        int ans=0;
        for(int l=0;l<n;l++){
            for(int r=l;r<n;r++){
                ans+=recur(l,r,s,dp);
            }
        }
        return ans;
    }
};