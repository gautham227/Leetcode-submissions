class Solution {
public:
    vector<int> dp;
    int recur(int bitmask, int n){
        if(bitmask==(1<<n)-1)return 1;
        if(dp[bitmask]!=-1)return dp[bitmask];
        int ind=__builtin_popcount(bitmask)+1;
        int ans=0;
        for(int i=0;i<n;i++){
            if((bitmask&(1<<i))==0 && ((i+1)%ind==0 || ind%(i+1)==0)){
                ans+=recur(bitmask|(1<<i), n);
            }
        }
        return dp[bitmask]=ans;
    }
    int countArrangement(int n) {
        dp.resize(1<<n,-1);
        return recur(0,n);
    }
};