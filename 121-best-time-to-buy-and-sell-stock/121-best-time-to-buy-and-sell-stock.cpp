class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mval=-1;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            mval=max(mval,prices[i]);
            ans=max(ans, mval-prices[i]);
        }
        return ans;
    }
};