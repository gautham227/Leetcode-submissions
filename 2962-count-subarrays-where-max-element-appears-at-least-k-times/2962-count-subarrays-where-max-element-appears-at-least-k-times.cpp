class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        long long st=0, en=0;
        long long cnt=0;
        long long maxi= *max_element(nums.begin(), nums.end());
        while(en<nums.size()){
            while(en<nums.size() && cnt<k){
                if(nums[en]==maxi){
                    cnt++;
                }
                en++;
                if(cnt!=k)ans+=(st);
            }
            if(cnt==k){
                while(cnt==k){
                    if(nums[st]==maxi)cnt--;
                    st++;
                }
                ans+=(st);
            }
            // cout<<st<<" "<<en<<" "<<cnt<<" "<<ans<<endl;
        }
        return ans;
    }
};