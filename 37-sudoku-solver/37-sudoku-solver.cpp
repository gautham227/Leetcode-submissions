class Solution {
public:
    vector<pair<int,int> >pos;
    bool check(vector<vector<char>>& v,int row, int column,char c){
        for(int i=0;i<9;i++){
            if(v[row][i]==c)return false;
            if(v[i][column]==c)return false;
            if(v[3*(row/3)+i/3][3*(column/3)+i%3]==c)return false;
        }
        return true;
    }
    bool recur(vector<vector<char>>& v,int ind){
        if(ind==pos.size())return true;
        int x=pos[ind].first;
        int y=pos[ind].second;
        for(int i=0;i<9;i++){
            if(check(v,x,y,'1'+i)){
                v[x][y]='1'+i;
                if(recur(v,ind+1)){
                    return true;
                }
                else{
                    v[x][y]='.';
                }
            }
        }
        return false;      
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    pos.push_back({i,j});
                }
            }
        }
        recur(board,0);
    }
};