class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> cntr;
        for(int i=0;i<nums.size();i++)cntr[nums[i]]++;
        int ma=0;
        for(auto ele: cntr)ma=max(ma, ele.second);
        int ans=0;
        for(auto ele: cntr)if(ele.second==ma)ans+=ma;
        return ans;
    }
};