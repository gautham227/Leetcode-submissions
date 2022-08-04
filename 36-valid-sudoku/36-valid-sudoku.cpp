class Solution {
public:
    vector<int> rm(vector<int> & v){
        for(int i=0;i<9;i++){
            v[i]=1;
        }
        return v;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> v(9,0);
        for(int i=0;i<9;i++){
            rm(v);
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(v[board[i][j]-'1']){
                        v[board[i][j]-'1']--;
                    }
                    else return false;
                }
            }
        }
        for(int i=0;i<9;i++){
            rm(v);
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(v[board[j][i]-'1']){
                        v[board[j][i]-'1']--;
                    }
                    else return false;
                }
            }
        }
        vector<vector<int> >vi(9,vector<int>(9,1));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int k=i/3*3+j/3;
                if(board[i][j]!='.'){
                    if(vi[k][board[i][j]-'1']){
                        vi[k][board[i][j]-'1']--;
                    }
                    else return false;
                }
            }
        }
        return true;
        
    }
};