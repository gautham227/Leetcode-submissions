#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    grid[i][j]=1-grid[i][j];
                }
            }
        }
        ans+=n*(1<<(m-1));
        for(int j=1;j<m;j++){
            int cntr=0;
            for(int i=0;i<n;i++){
                cntr+=grid[i][j];
            }
            ans+=(1<<(m-1-j))*max(cntr, n-cntr);
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();