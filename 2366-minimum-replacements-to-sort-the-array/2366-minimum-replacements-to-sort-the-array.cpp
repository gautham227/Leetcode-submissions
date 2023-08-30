class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        long long n=nums.size();
        reverse(nums.begin(),nums.end());
        long long ma=1e18;
        for(int i=0;i<n;i++){
            if(nums[i]>ma){
                long long rem=nums[i]%ma;
                long long cnt=nums[i]/ma;
                if(rem>0)cnt++;
                ans+=cnt-1;
                ma=min(ma,1ll*nums[i]/cnt);
            }
            else{
                ma=min(ma,1ll*nums[i]);
            }
        }
        return ans;
    }
};