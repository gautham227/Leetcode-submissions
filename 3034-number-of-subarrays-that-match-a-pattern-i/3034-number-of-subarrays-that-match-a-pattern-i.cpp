class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans=0;
        int m=pattern.size();
        for(int st=0;st<nums.size();st++){
            if(st+m>=nums.size())break;
            bool flag=true;
            for(int cur=st+1;cur<=st+m;cur++){
                if(pattern[cur-st-1]==1){
                    if(nums[cur]<=nums[cur-1]){
                        flag=false;
                        break;
                    }
                }
                if(pattern[cur-st-1]==0){
                    if(nums[cur]!=nums[cur-1]){
                        flag=false;
                        break;
                    }
                }
                if(pattern[cur-st-1]==-1){
                    if(nums[cur]>=nums[cur-1]){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)ans++;
        }
        return ans;
    }
};