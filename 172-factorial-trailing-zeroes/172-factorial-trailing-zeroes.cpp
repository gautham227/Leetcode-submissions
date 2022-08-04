class Solution {
public:
    int no5(int n){
        int cnt=0;
        while(n%5==0){
            cnt++;
            n=n/5;
        }
        return cnt;
    }
    
    int trailingZeroes(int n) {
        int ans=0;
        for(int i=5;i<=n;i=i+5){
            ans=ans+no5(i);
        }
        return ans;
    }
};