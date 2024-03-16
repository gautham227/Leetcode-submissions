class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int cnt=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)cnt++;
            else cnt--;
            if(mp.find(cnt)!=mp.end())ans=max(ans,i-mp[cnt]);
            else mp[cnt]=i;
        }
        return ans;
    }
};