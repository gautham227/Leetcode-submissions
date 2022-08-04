class Solution {
public:
    int mySqrt(int x) {
        long long w=x;
        long long ans;
        for(long long i=0;i<66000;i++){
            if (i*i<=w && (i+1)*(i+1)>w){
                ans=i;
                break;
            }
        }
        return ans;
    }
};