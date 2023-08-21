class Solution {
public:
    int minimumSum(int n, int k) {
        int sum=0;
        for(int i=0;i<min(k/2,n);i++){
            sum+=i+1;
        }
        n-=min(k/2,n);;
        for(int i=k;i<k+n;i++){
            sum+=i;
        }
        return sum;
    }
};