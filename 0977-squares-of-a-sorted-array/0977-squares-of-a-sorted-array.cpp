class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> mp(10000+2,0);
        for(int i=0;i<nums.size();i++){
            mp[abs(nums[i])]++;
        }
        vector<int> ans;
        for(int i=0;i<10000+2;i++){
            for(int j=0;j<mp[i];j++){
                ans.push_back(i*i);
            }
        }
        return ans;
    }
};