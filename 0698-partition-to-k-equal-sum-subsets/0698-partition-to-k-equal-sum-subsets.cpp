class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0)return false;
        int reqd=sum/k;
        int dp[(1<<n)+1];
        memset(dp, -1, sizeof(dp));
        dp[0]=reqd;

        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if((i&(1<<j))==0 && dp[(i|(1<<j))]<0){
                    if(dp[i]-nums[j]>0){
                        dp[(i|(1<<j))]=dp[i]-nums[j];
                    }
                    else if(dp[i]-nums[j]==0){
                        dp[(i|(1<<j))]=reqd;
                    }
                }
            }
        }
        return  (dp[(1<<n)-1]==reqd);
    }
};