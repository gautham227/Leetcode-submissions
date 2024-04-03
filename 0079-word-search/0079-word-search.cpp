class Solution {
public:
    
    bool check(int x, int y, int n, int m){
        if(x<0 || y<0 || x>=n || y>=m)return false;
        return true;
    }
    
    bool dfs(int x, int y,int ind, vector<vector<bool> >& vis, vector<vector<char> >& b, string &word){
        if(ind==word.size()){
            return true;
        }
        vector<pair<int, int> >m {{-1,0},{0,-1},{1,0},{0,1}};
        for(auto ele: m){
            int xnew=x+ele.first;
            int ynew=y+ele.second;
            if(check(xnew,ynew,b.size(), b[0].size()) && (!vis[xnew][ynew]) && b[xnew][ynew]==word[ind]){
                vis[xnew][ynew]=true;
                if(dfs(xnew,ynew,ind+1,vis,b,word))return true;
                vis[xnew][ynew]=false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool> >vis(n, vector<bool>(m, false));
        bool ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=true;
                    ans|=dfs(i,j,1,vis,board,word);
                    vis[i][j]=false;
                }
            }
        }
        return ans;
    }
};