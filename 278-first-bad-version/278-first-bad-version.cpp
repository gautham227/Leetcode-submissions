// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1, r=n;
        while(r-l>1){
            int mid=l+(r-l)/2;
            bool cur=isBadVersion(mid);
            if(cur){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        
        if(isBadVersion(l))return l;
        return r;
        
    }
};