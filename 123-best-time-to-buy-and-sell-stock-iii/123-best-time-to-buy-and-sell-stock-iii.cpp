class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prev(5,0), cur(5,0);
        prev[3]=prices[n-1];prev[1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=4;j++){
                if(j%2==0){
                    cur[j]=max(prev[j], -prices[i]+prev[j-1]);
                }
                else{
                    cur[j]=max(prev[j], prices[i]+prev[j-1]);
                }
            }
            prev=cur;
        }
        return prev[4];
    }
};