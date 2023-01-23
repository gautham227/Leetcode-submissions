class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum1=accumulate(nums.begin(), nums.end(), 0);
        int sum2=0;
        for(auto ele: nums){
            int ele1=ele;
            while(ele1>0){
                sum2+=ele1%10;
                ele1/=10;
            }
        }
        return abs(sum1-sum2);
    }
};