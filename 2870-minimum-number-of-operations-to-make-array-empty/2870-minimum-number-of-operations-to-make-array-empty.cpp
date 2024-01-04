class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto ele: nums)mp[ele]++;
        int ans=0;
        for(auto ele: mp){
            ans+=((ele.second+2)/3);
            if(ele.second==1)return -1;
        }
        return ans;
    }
};