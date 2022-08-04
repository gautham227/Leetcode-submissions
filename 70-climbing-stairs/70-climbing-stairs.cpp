class Solution {
public:
    int climbStairs(int n) {
        if(n<2)return 1;
        long long prev=1, prev1=1, cur;
        for(long long i=2;i<=n;i++){
            cur=prev+prev1;
            prev1=prev;
            prev=cur;
        }
        return (int)prev;
    }
};