class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]-k]++;
            mp[nums[i]+k+1]--;
        }
        
        int ans=0;
        int count=0;
        for(auto ele: mp){
            ans+=ele.second;
            count=max(ans, count);
        }
        
        return count;
        
    }
};