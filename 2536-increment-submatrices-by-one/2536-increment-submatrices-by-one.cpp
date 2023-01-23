class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int> >ans(n, vector<int>(n,0));
        for(auto ele: queries){
            for(int i=ele[0]; i<=ele[2]; i++){
                ans[i][ele[1]]++;
                if(ele[3]!=n-1)ans[i][ele[3]+1]--;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                ans[i][j]+=ans[i][j-1];
            }
        }
        
        return ans;
    }
};