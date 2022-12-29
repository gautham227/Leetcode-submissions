class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        int dp[n+5];
        
        for(int i=0;i<n+5;i++){
            dp[i]=INT_MAX;
        }
        
        dp[0]=0;
        
        for(int i=0;i<n-1;i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j>n-1)break;
                dp[i+j]=min(dp[i+j], 1+dp[i]);
            }
        }
        
        return dp[n-1];
    }
};