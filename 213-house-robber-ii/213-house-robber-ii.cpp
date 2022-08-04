class Solution {
public:
    
    int dp(vector<int>& nums, int st, int en){
        if(en-st==1)return nums[st];
        else if(en-st==2)return max(nums[st],nums[st+1]);
        int prev=nums[st];
        int prev1=max(nums[st+1],nums[st]);
        int curr;
        for(int i=st+2;i<en;i++){
            curr=max(prev1,prev+nums[i]);
            prev=prev1;
            prev1=curr;
        }
        
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        int en=nums.size();
        if(en==1)return nums[0];    
        return max(dp(nums,0,en-1),dp(nums,1,en));
    }
};