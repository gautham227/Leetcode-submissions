class Solution {
public:
    
    int maximizeWin(vector<int>& p, int k) {
        vector<int> dp(1e5+1, 0);
        int n=p.size();
        int ind=0;
        int ans=0;
        for(int i=0;i<n;i++){
            while(p[ind]<p[i]-k){
                ind++;
            }
            dp[i+1]=max(dp[i],i-ind+1);
            ans=max(ans, (int)i-ind+1+dp[ind]);
        }
        return ans;
    }
};