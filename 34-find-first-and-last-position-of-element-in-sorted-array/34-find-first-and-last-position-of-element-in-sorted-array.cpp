#define pb push_back
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!binary_search(nums.begin(),nums.end(),target)){
            return {-1,-1};
        }
        vector<int> v;
        v.pb(lower_bound(nums.begin(),nums.end(),target)-nums.begin());
        v.pb(upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1);
        return v;
    }
};