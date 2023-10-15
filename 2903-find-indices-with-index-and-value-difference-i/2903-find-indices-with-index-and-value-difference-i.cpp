class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(j-i>=indexDifference && abs(nums[j]-nums[i])>=valueDifference){
                    if(v.size()==0){
                        v.push_back(i);
                        v.push_back(j);
                    }
                }
            }
        }
        if(v.size()==0)return {-1,-1};
        return v;
    }
};