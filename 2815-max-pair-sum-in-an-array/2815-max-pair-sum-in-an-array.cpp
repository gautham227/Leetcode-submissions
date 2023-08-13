class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int val1=nums[i];
                int val2=nums[j];
                int dig1=0, dig2=0;
                while(val1>0){
                    dig1=max(dig1, val1%10);
                    val1/=10;
                }
                while(val2>0){
                    dig2=max(dig2, val2%10);
                    val2/=10;
                }
                if(dig1==dig2){
                    ans=max(ans,nums[i]+nums[j]);
                }
            }
        }
        return ans;
    }
};