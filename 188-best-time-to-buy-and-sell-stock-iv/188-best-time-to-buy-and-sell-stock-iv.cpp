class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> prev(2*k+1,0), cur(2*k+1,0);
        int n=prices.size();
        for(int ind=n-1;ind>=0;ind--){
            for(int transac=1;transac<=2*k;transac++){
                if(ind==n-1){
                    if(transac%2==1){
                        cur[transac]=prices[ind];
                    }
                    else{
                        cur[transac]=0;
                    }
                    continue;
                }
                if(transac%2==0){
                    cur[transac]=max(-prices[ind]+prev[transac-1], prev[transac]);
                }
                else{
                    cur[transac]=max(prices[ind]+prev[transac-1], prev[transac]);
                }
            }
            prev=cur;
        }
        return prev[2*k];
    }
};