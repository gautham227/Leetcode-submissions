class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0;
        int n=nums.size();
        int curmaxi=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>curmaxi){
                curmaxi=nums[i];
            }
            else{
                int newele=curmaxi+1;
                ans+=newele-nums[i];
                curmaxi=max(curmaxi, newele);
            }
        }
        
        return ans;
        
    }
};