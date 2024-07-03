class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=2000000000+5;
        for(int i=0;i<4;i++){
            int ind1=min((int)nums.size()-1, i);
            int ind2=max(0, (int)nums.size()-(4-i));
            ans=min(ans,abs(nums[ind1]-nums[ind2]));
        }
        return ans;
    }
};