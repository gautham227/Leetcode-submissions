class Solution {
public:
    
    int recur(int ind,int type, vector<int> & nums1, vector<int> & nums2, vector<vector<int> >& dp){
        if(ind==0)return dp[ind][type-1]=1;
        if(dp[ind][type-1]!=-1)return dp[ind][type-1];
        int cur=1;
        if(type==1){
            if(nums1[ind]>=nums1[ind-1]){
                cur=max(cur, 1+recur(ind-1,1,nums1, nums2, dp));
            }
            if(nums1[ind]>=nums2[ind-1]){
                cur=max(cur, 1+recur(ind-1,2,nums1, nums2, dp));
            }
        }
        if(type==2){
            if(nums2[ind]>=nums1[ind-1]){
                cur=max(cur, 1+recur(ind-1,1,nums1, nums2, dp));
            }
            if(nums2[ind]>=nums2[ind-1]){
                cur=max(cur, 1+recur(ind-1,2,nums1, nums2, dp));
            }
        }
        
        return dp[ind][type-1]=cur;
    }
    
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        // cout<<n<<endl;
        vector<vector<int> >dp(n+1, vector<int> (2, -1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                // int cur = recur(i,j+1,nums1,nums2, dp);
                // cout<<i<<" "<<j<<" "<<cur<<endl;
                ans=max(ans,recur(i,j+1,nums1,nums2, dp));
                // cout<<i<<" "<<j<<endl;
            }
        }
        
        return ans;
        
    }
};