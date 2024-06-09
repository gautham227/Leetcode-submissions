#define maxv(a) *max_element(a.begin(), a.end())

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int> > dp(n+1, vector<int>(k+1, 1));
        unordered_map<int, int> mp;
        mp[nums[n-1]]=n-1;
        vector<int> mval(k+5, 1);
        for(int i=n-2;i>=0;i--){
            for(int j=k;j>=0;j--){
                if(j==0){
                    if(mp.find(nums[i])!=mp.end()){
                        dp[i][j]=max(dp[i][j], 1+ dp[mp[nums[i]]][j]);
                    }
                    else{
                        dp[i][j]=1;
                    }
                }
                else{
                    if(mp.find(nums[i])!=mp.end()){
                        dp[i][j]=max(dp[i][j], 1+ dp[mp[nums[i]]][j]);
                    }
                    dp[i][j]=max(dp[i][j],1+mval[j-1]);
                }
                mval[j]=max(mval[j], dp[i][j]);
            }
            mp[nums[i]]=i;
        }
        return maxv(mval);
    }
};