class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int> > ans(n, vector<int>(m,-1));
        vector<int> rows1cnt, cols1cnt;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                cnt+=grid[i][j];
            }
            rows1cnt.push_back(cnt);
        }
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=grid[i][j];
            }
            cols1cnt.push_back(cnt);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=2*(rows1cnt[i]+cols1cnt[j])-m-n;
            }
        }
        return ans;
    }
};