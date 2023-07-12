class Solution {
public:
    
    int n,m;
    
    int recur(int x, int y, vector<vector<char> >& matrix, vector<vector<int> >& down, vector<vector<int> >& right, vector<vector<int> >& dp){
        if(x<0 || x>=n || y<0 || y>=m || matrix[x][y]=='0')return 0;
        if(dp[x][y]!=-1)return dp[x][y];
        
        return dp[x][y]=1+min(right[x][y], min(down[x][y], recur(x+1,y+1,matrix, down, right, dp)));
        
    }
    
    
    int maximalSquare(vector<vector<char>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        
        vector<vector<int> > down(n, vector<int>(m,0));
        vector<vector<int> > right(n, vector<int>(m,0));
        
        for(int i=0;i<m;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
                down[j][i]=count;
                if(matrix[j][i]=='1')count++;
                else count=0;
            }
        }
        
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=m-1;j>=0;j--){
                right[i][j]=count;
                if(matrix[i][j]=='1')count++;
                else count=0;
            }
        }
        
        vector<vector<int> >dp(n+1, vector<int>(m+1, -1));
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans, recur(i,j,matrix, down, right, dp));
                
            }
        }
        
        return ans*ans;
        
        
    }
};