class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> y(3,0), ny(3,0);
        int yreq=2*(n/2)+(n/2+1);
        int greq=n*n-yreq;
        for(int i=0;i<n/2;i++){
            y[grid[i][i]]++;
            y[grid[i][n-1-i]]++;
        }
        for(int i=n/2;i<n;i++){
            y[grid[i][n/2]]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ny[grid[i][j]]++;
            }
        }
        for(int i=0;i<3;i++)ny[i]-=y[i];
        int ans=INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==j)continue;
                ans=min(ans, yreq-y[i]+greq-ny[j]);
            }
        }
        return ans;
    }
};