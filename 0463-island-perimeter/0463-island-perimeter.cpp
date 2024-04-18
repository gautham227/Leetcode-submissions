class Solution {
public:
    int peri=0;
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            peri++;
            return;
        }
        if(grid[i][j]==1){
            // vis[i][j]=1;
            grid[i][j]=2;
            // grid[i][j]=0;
            dfs(grid,i+1,j);
            dfs(grid,i-1,j);
            dfs(grid,i,j+1);
            dfs(grid,i,j-1);
        }
        else{
            if(grid[i][j]==2){
                return;
            }
            peri++;
            return;
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        // int vis[grid.size()][grid[0].size()]={0};
        int flag=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    flag=1;
                    dfs(grid,i,j);
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        return peri;
    }
};