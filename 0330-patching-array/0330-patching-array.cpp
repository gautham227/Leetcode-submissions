class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long tot=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            while(tot < n && nums[i]>tot+1){
                tot+=(tot+1);
                ans++;
            }
            if(nums[i]<=tot+1){
                tot+=nums[i];
            }
        }
        while(n>tot){
            tot+=(tot+1);
            ans++;
        }
        return ans;
    }
};