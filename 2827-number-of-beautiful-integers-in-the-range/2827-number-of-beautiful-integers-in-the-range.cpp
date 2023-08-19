class Solution {
public:
    
    int dp[10][21][10][10][2];
    int m;
    
    int fun(int pos, int sum, int odd, int even, int f, int n, string &s)
    {

        if (pos == n) {
            // cout<<sum<<" "<<odd<<" "<<even<<endl;
            if (sum == 0 && odd==even) {
                return 1;
            }
            return 0;
        }
        if (dp[pos][sum][odd][even][f] != -1)
            return dp[pos][sum][odd][even][f];
        int lmt = 9;
        if (!f)
            lmt = s[pos]-'0';

        int ans = 0;
        for (int i = 0; i <= lmt; i++) {
            int new_f = f;
            if (f == 0 and i < lmt)
                new_f = 1;
            int sum1 = sum;
            sum1 *= 10;
            sum1 += i;
            sum1 %= m;
            int odd1=odd;
            int even1=even;
            if(i%2==1){
                odd1++;
            }
            else{
                if(i!=0){
                    even1++;
                }
                else{
                    if(odd+even>0){
                        even1++;
                    }
                }
            }
            ans += fun(pos + 1, sum1,odd1,even1, new_f, n, s);
        }
        return dp[pos][sum][odd][even][f] = ans;
    }
    
    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp, -1, sizeof(dp));
        m=k;
        string s1=to_string(high);
        // cout<<s1<<endl;
        int ans=fun(0,0,0,0,0,s1.size(),s1);
        s1=to_string(low-1);
        // cout<<s1<<endl;
        memset(dp, -1, sizeof(dp));
        ans-=fun(0,0,0,0,0,s1.size(),s1);
        return ans;
    }
};