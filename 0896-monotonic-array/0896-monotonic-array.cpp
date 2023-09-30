class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag=false;
        flag|=is_sorted(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        flag|=is_sorted(nums.begin(), nums.end());
        
        return flag;
        
    }
};