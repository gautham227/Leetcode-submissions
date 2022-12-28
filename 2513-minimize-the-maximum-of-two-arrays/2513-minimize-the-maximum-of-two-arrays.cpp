class Solution {
public:
    
    bool check(int val, int d1, int d2, int c1, int c2){
        long long lcm=(1ll*d1*d2)/(1ll*__gcd(d1,d2));
        // cout<<__gcd(d1,d2)<<endl;
        if(val-val/d1<c1 || val-val/d2<c2 || val-val/lcm<c1+c2)return false;
        return true;
    }
    
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int l=1, r=2000000000;
        
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(check(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        
        if(check(l, divisor1, divisor2, uniqueCnt1, uniqueCnt2))return l;
        return r;
    }
};
