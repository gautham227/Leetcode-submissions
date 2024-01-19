class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> cntr(101,0);
        for(int i=0;i<nums.size();i++)cntr[nums[i]]++;
        int ma=0;
        for(auto ele: cntr)ma=max(ma, ele);
        int ans=0;
        for(auto ele: cntr)if(ele==ma)ans+=ma;
        return ans;
    }
};