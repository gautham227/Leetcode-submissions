class Solution {
public:
    
    int dp[1001][1001];
    
    int recur(int ind, int rem, string & f, int len){
        if(ind>=f.size())return 0;
        if(dp[ind][rem]!=-1)return dp[ind][rem];
        int ans=f.size();
        if(f[ind]=='1'){
            ans=min(ans, 1+recur(ind+1, rem, f, len));
            if(rem>0)ans=min(ans, recur(ind+len, rem-1, f, len));
        }
        else{
            ans=min(ans, recur(ind+1, rem, f, len));
        }
        return dp[ind][rem]=ans;
    }
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        memset(dp, -1, sizeof(dp));
        return recur(0, numCarpets, floor, carpetLen);
    }
};