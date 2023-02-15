class Solution {
public:

    bool check(int val, vector<int> & nums, int k){
        int cnt=0;
        int last=-2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=val && last<i-1){
                cnt++;
                last=i;
            }
        }
        return (cnt>=k);
    }

    int minCapability(vector<int>& nums, int k) {
        int l=0, r=0;
        for(auto ele: nums)r=max(r,ele);

        while(r-l>1){
            int mid=l+(r-l)/2;
            if(check(mid,nums,k))r=mid;
            else l=mid+1;
        }

        if(check(l,nums,k))return l;
        return r;
    }
};