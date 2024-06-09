class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto ele: nums)mini=min(mini, ele);
        for(auto ele: nums){
            if(ele%mini>0)return 1;
        }
        int ans=0;
        for(auto ele: nums){
            if(ele==mini)ans++;
        }
        return (ans+1)/2;
    }
};