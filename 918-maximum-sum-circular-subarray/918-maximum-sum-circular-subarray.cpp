class Solution {
public:
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int ma = 0, mi = 0, sum = 0, mas = nums[0], mis = nums[0];
        for (int num : nums) {
            ma = max(ma, 0) + num;
            mas = max(mas, ma);
            mi = min(mi, 0) + num;
            mis = min(mis, mi);
            sum += num;
        }
        if(sum==mis)return mas;
        int ans=max(mas, sum - mis);
        return ans;
    }
};