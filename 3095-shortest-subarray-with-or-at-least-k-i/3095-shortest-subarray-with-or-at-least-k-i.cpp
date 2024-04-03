class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int val=0;
                for(int k=i;k<=j;k++){
                    val|=nums[k];
                }
                if(val>=k){
                    ans=min(ans,j-i+1);
                }
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};