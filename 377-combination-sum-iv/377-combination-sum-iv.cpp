class Solution {
public:
    int dp[1001];
    int n;
    int recur(int req, vector<int>& nums){
        if(req==0)return 1;
        if(req<0)return 0;
        if(dp[req]!=-1)return dp[req];
        
        int cur=0;
        
        for(int i=0;i<n;i++){
            cur+=recur(req-nums[i],nums);
        }
        
        return dp[req]=cur;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof dp);
        n=nums.size();
        return recur(target,nums);
    }
};