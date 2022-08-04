class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                x=1;
                break;
            }
        }
        if(x)next_permutation(nums.begin(),nums.end());
        else{
            reverse(nums.begin(),nums.end());
        }
    }
};