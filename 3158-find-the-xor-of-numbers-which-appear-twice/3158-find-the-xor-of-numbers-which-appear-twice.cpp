class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<bool> vis(55, false);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(vis[nums[i]]==false){
                vis[nums[i]]=true;
            }
            else{
                ans^=nums[i];
            }
        }
        return ans;
    }
};