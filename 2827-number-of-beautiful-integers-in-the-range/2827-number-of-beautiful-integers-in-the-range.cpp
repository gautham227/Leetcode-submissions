class Solution {
public:
    // dp[ind][rem when div by k][odd][even][started][tight]
    int dp[10][21][10][10][2][2];
    
    int recur(int ind, int rem, int odd, int even, int st, int tight, string &s, int k){
        if(ind==s.size()){
            if(rem==0 && odd==even)return 1;
            return 0;
        }
        if(dp[ind][rem][odd][even][st][tight]!=-1)return dp[ind][rem][odd][even][st][tight];
        int upper=s[ind]-'0';
        if(tight==0)upper=9;
        int ans=0;
        for(int i=0;i<=upper;i++){
            ans+=recur(ind+1, (rem*10+i)%k, odd+(i%2==1), even+(i%2==0)-(i==0 && st==0), (st|(i!=0)), (tight&(i==upper)), s,k);
        }
        return dp[ind][rem][odd][even][st][tight]=ans;
    }
    
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string r=to_string(high);
        string l=to_string(low-1);
        memset(dp, -1, sizeof(dp));
        int ans=recur(0,0,0,0,0,1,r,k);
        memset(dp, -1, sizeof(dp));
        return ans-recur(0,0,0,0,0,1,l,k);
    }
};