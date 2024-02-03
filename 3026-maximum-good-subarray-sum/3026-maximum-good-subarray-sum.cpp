typedef long long ll;

class Solution {
public:
    ll inf=1e18;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<long long, long long> mp;
        ll ans=-1*inf;
        ll n=nums.size();
        ll sum1=0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]+k)!=mp.end()){
                ans=max(ans, sum1+nums[i]-mp[nums[i]+k]);
            }
            if(mp.find(nums[i]-k)!=mp.end()){
                ans=max(ans, sum1+nums[i]-mp[nums[i]-k]);
            }
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=sum1;
            }
            mp[nums[i]]=min(mp[nums[i]], sum1);
            sum1+=nums[i];
        }
        if(ans==-1*inf)return 0;
        return ans;
    }
};