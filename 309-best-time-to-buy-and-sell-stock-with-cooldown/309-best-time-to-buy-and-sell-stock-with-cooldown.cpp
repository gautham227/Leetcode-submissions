class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> prev1(2,0), prev2(2,0), cur(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    cur[buy]=max(prices[ind]+prev2[0], prev1[buy]);
                }
                else{
                    cur[buy]=max(-prices[ind]+prev1[1], prev1[buy]);
                }
            }
            prev2=prev1;
            prev1=cur;
        }
        return prev1[0];
    }
};