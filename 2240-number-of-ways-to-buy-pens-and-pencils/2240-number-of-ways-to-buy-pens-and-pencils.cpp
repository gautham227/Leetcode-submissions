class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
        long long mpenc=total/cost1;
        long long rem;
        for(int i=0;i<=mpenc;i++){
            rem=total-i*cost1;
            ans+=rem/cost2+1;
        }
        return ans;
    }
};