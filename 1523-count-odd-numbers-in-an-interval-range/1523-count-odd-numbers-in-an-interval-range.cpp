class Solution {
public:
    int countOdds(int low, int high) {
        int x=low%2;
        int y=high%2;
        int n=high-low;
        if(x==1 && y==1){
            return (n)/2+1;
        }
        else if(x==0 && y==0){
            return n/2;
        }
        int ans=n/2;
        if(n%2)ans++;
        return ans;
    }
};