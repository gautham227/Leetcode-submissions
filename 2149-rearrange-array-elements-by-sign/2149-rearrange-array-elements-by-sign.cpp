class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v1,v2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                v1.push_back(nums[i]);
            }
            else{
                v2.push_back(nums[i]);
            }
        }
        for(int i=0;i<v1.size();i++){
            nums[2*i]=v1[i];
            nums[2*i+1]=v2[i];
        }
        return nums;
    }
};