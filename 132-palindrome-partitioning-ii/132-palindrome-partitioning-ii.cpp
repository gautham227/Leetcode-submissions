class Solution {
    
public:
    
    bool ispal(int l, int r, string& s){
        while(l<r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }

    int recur(int l,int n, string& s,vector<int>&dp){
        if(l==n)return 0;
        if(dp[l]!=-1)return dp[l];
        int cnt=INT_MAX;
        for(int i=l;i<n;i++){
            if(ispal(l,i,s)){
                cnt=min(cnt,1+recur(i+1,n,s,dp));
            }
        }
        return dp[l]=cnt;
    }
    
    int minCut(string str) {
        int n=str.size();
        vector<int>dp(n+1,-1);
        return recur(0,n,str,dp)-1;
    }
};