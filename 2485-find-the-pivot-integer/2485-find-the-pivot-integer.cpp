class Solution {
public:
    int s(int i){
        return i*(i+1)/2;
    }
    int pivotInteger(int n) {
        int l=1, r=n;
        while(r-l>1){
            int mid=(r+l)/2;
            if(2*s(mid)>s(n)+mid)r=mid-1;
            else l=mid;
        }
        if(s(l)*2==s(n)+l)return l;
        if(s(r)*2==s(n)+r)return r;
        return -1;
    }
};