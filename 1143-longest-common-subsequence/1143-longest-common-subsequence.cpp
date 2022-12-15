class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        // int dp[n+1][m+1];
        int prev[m+1], cur[m+1];
        // memset(dp,0,sizeof(dp));
        memset(cur,0,sizeof(cur));
        memset(prev,0,sizeof(prev));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    if(text1[i]==text2[j])cur[j]=1;
                    else if(j!=0)cur[j]=cur[j-1];
                }
                else if(j==0){
                    if(text1[i]==text2[j])cur[j]=1;
                    else if(i!=0)cur[j]=prev[j];
                }
                else if(text1[i]==text2[j]){
                    cur[j]=1+prev[j-1];
                }
                else{
                    cur[j]=max(prev[j],cur[j-1]);
                }
            }
            for(int i=0;i<m;i++){
                prev[i]=cur[i];
            }
        }

        return prev[m-1];
    }
};