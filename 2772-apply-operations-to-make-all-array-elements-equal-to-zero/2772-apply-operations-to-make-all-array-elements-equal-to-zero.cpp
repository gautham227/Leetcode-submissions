class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();
        int counter=0;
        bool ans=true;
        for(int i=0;i<n;i++){
            if(counter>nums[i])ans&=false;
            if(n-i<k && counter!=nums[i])ans&=false;
            nums[i]=nums[i]-counter;
            counter+=nums[i];
            if(i>=k-1)counter-=nums[i-k+1];
        }
        return ans;
    }
};