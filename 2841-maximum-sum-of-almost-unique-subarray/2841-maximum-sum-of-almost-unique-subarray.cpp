class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        map<long long,int> mp;
        long long fans=0;
        long long ans=0;
        for(int i=0;i<k-1;i++){
            ans+=nums[i];
            mp[nums[i]]++;
        }
        for(int i=k-1;i<nums.size();i++){
            ans+=nums[i];
            mp[nums[i]]++;
            if(mp.size()>=m){
                fans=max(fans,ans);
            }
            mp[nums[i-k+1]]--;
            if(mp[nums[i-k+1]]==0){
                mp.erase(mp.find(nums[i-k+1]));
            }
            ans-=nums[i-k+1];
        }
        return fans;
    }
};