const int mod = 1000000007;
class Solution {
public:
    double binexp(double a,long long b){
        double ans=1;
        while(b>0.0000001){
            if(b&1){
                ans=(ans*a);
            }
            a=(a*a);
            b=b>>1;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if(x==1){return 1;}
        if(n<0){
            x=(double)1/x;
        }
        double ans = binexp(x,abs(n));
        return ans;
    }
};