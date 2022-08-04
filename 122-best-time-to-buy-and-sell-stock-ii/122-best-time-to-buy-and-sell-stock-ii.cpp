class Solution {
public:
    int maxProfit(vector<int>& values) {
        int n=values.size();
        if(n==0)return 0;
        vector<long> prev(2), cur(2);
        prev[0]=0;prev[1]=values[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==0){
                    cur[j]=max(prev[j],-values[i]+prev[1]);
                }
                else{
                    cur[j]=max(prev[j],values[i]+prev[0]);
                }
            }
            prev=cur;
        }
        return prev[0];
    }
};