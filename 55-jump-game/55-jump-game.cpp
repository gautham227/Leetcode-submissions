class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ma=0;
        for(int i=0;i<nums.size();i++){
            if(ma<i)break;
            ma=max(ma,i+nums[i]);
        }
        return (ma>=nums.size()-1);
    }
};