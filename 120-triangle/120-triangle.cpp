class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<int> cur(n,0);
        for(int i=0;i<n;i++){
            cur[i]=t[n-1][i];
            // cout<<dp[n-1][i]<<" ";
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                cur[j]=min(cur[j],cur[j+1])+t[i][j];
            }
        }
        return cur[0];
    }
};