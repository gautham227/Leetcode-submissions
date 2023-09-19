class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(int i=0;i<nums.size();i++){
            if(!mp[nums[i]])mp[nums[i]]=true;
            else return nums[i];
        }
        return -1;
    }
};