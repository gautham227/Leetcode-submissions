class Solution {
public:
    int minimumSum(int n, int k) {
        // vector<int> cur;
        int sum=0;
        for(int i=0;i<min(k/2,n);i++){
            // cur.push_back(i+1);
            sum+=i+1;
        }
        n-=min(k/2,n);;
        for(int i=k;i<k+n;i++){
            // cur.push_back(i);
            sum+=i;
        }
        return sum;
    }
};