class Solution {
public:
    int recur(int ind, int k,vector<int> &dp, vector<int>&arr){
        if(ind==arr.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int cur=INT_MIN;
        int ans=INT_MIN;
        for(int i=ind;i<min(ind+k,(int)arr.size());i++){
            cur=max(cur,arr[i]);
            ans=max(ans,(i-ind+1)*cur+recur(i+1,k,dp,arr));
            
        }
        return dp[ind]=ans;
    }
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        recur(0,k,dp,arr);
        return dp[0];
    }
};