#define ll long long

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        ll ans=0;
        ll cnt=1;
        ll last=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=last){
                cnt++;
                last=1-last;
            }
            else{
                ans+=cnt*(cnt+1)/2;
                cnt=1;
                last=nums[i];
            }
        }
        ans+=cnt*(cnt+1)/2;
        return ans;
    }
};