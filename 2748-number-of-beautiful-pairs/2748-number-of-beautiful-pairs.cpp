class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int num1=nums[i];
                while(num1>9){
                    num1/=10;
                }
                
                if(__gcd(num1, nums[j]%10)==1)ans++;
            }
        }
        
        return ans;
        
    }
};