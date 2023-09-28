class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> v1, v2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1)v2.push_back(nums[i]);
            else v1.push_back(nums[i]);
        }
        for(int i=0;i<v1.size();i++){
            nums[i]=v1[i];
        }
        for(int j=0;j<v2.size();j++){
            nums[j+v1.size()]=v2[j];
        }
        return nums;
    }
};