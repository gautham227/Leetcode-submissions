typedef long long ll;

class Solution {
public:
    
    bool check(ll no, vector<int>& piles, int h){
        ll cnt=0;
        for(auto ele: piles)cnt+=1ll*(1ll*ele+no-1)/(1ll*no);
        return (cnt<=h);
    }
    
    int minEatingSpeed(vector<int>& piles, int hrs) {
        ll l=1;
        ll h=1000000000000000;
        while(h-l>1){
            ll mid=l+(h-l)/2;
            if(check(mid,piles,hrs))h=mid;
            else l=mid+1;
        }
        if(check(l,piles,hrs))return l;
        return h;
    }
};