class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if((sum&1)>0)return false; 
        bitset<20005> bs;
        // bitset<20005> help;
        bs.set(0);
        for(int i=0;i<nums.size();i++){
            bs|=(bs<<nums[i]);
        }
        return (bs[sum/2]);
    }
};