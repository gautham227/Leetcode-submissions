class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1), prev(n);
        for(int i=0;i<n;i++){
            prev[i]=i;
        }
        
        int ind=0;
        int maxv=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    dp[i]=max(dp[i], 1+dp[j]);
                    if(dp[i]==1+dp[j]){
                        prev[i]=j;
                    }
                }
            }
            if(dp[i]>maxv){
                maxv=dp[i];
                ind=i;
            }
        }
        vector<int> ans;
        while(prev[ind]!=ind){
            ans.push_back(nums[ind]);
            ind=prev[ind];
        }
        ans.push_back(nums[ind]);
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};