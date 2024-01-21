class Solution {
public:
    int rob(vector<int>& nums) {
        int cur=0,prev=0,prev1=0;
        for(int i=0;i<nums.size();i++){
            if(i==0){cur=nums[i];continue;}
            else if(i==1){prev=cur;cur=max(cur,nums[1]);continue;}
            else{
                prev1=prev;
                prev=cur;
                cur=max(prev,nums[i]+prev1);
            }
        }
        return cur;
    }
};