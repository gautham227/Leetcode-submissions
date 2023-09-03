// space optimisation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,1), cur(n);
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    cur[j]=prev[j];
                }
                else{
                    cur[j]=prev[j]+cur[j-1];
                }
            }
            prev=cur;
        }
        return prev[n-1];
    }
};