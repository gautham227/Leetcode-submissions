class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        int ind1=k-1, ind2=k+1;
        ans=nums[k];
        int mini=nums[k];
        int len=1;
        while(ind1>=0 || ind2<n){
            len++;
            if(ind1<0){
                mini=min(mini, nums[ind2]);
                ans=max(ans, len*mini);
                ind2++;
            }
            else if(ind2>=n){
                mini=min(mini, nums[ind1]);
                ans=max(ans, len*mini);
                ind1--;
            }
            else if(nums[ind1]>nums[ind2]){
                mini=min(mini, nums[ind1]);
                ans=max(ans, len*mini);
                ind1--;
            }
            else{
                mini=min(mini, nums[ind2]);
                ans=max(ans, len*mini);
                ind2++;
            }
        }
        return ans;
    }
};