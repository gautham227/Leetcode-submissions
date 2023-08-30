class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long ans=0;
        for(int i=1;n>0 && i<=target/2;i++){
            ans+=i;
            n--;
        }
        long long cur=target;
        while(n>0){
            ans+=cur;
            cur++;
            n--;
        }
        return ans;
    }
};