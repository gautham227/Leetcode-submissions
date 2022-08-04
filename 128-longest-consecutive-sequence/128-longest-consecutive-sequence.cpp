class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int last=nums[0];
        int ans=1, clen=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==last+1){
                clen++;
                last=nums[i];
                ans=max(ans,clen);
            }
            else{
                clen=1;
                last=nums[i];
            }
            while(i!=nums.size()-1){
                if(nums[i]==nums[i+1]){
                    i++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};