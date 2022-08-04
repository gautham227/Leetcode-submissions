class Solution {
public:
    //0 means R, 1 means D, 2 means L and 3 means U
    bool mov(int i, int j,vector<vector<int>>& ans,int cur, int no ){
        if(i>=ans.size()|| j>=ans.size() || i<0 || j<0 || ans[i][j]!=-1)return false;
        ans[i][j]=no;
        bool x;
        if(cur==0){
            x=mov(i,j+1,ans,cur,no+1);
        }
        else if(cur==1){
            x=mov(i+1,j,ans,cur,no+1);
        }
        else if(cur==2){
            x=mov(i,j-1,ans,cur,no+1);
        }
        else{
            x=mov(i-1,j,ans,cur,no+1);
        }
        if(x==0){
            if(cur==0){
                x=mov(i+1,j,ans,cur+1,no+1);
            }
            else if(cur==1){
                x=mov(i,j-1,ans,cur+1,no+1);
            }
            else if(cur==2){
                x=mov(i-1,j,ans,cur+1,no+1);
            }
            else{
                x=mov(i,j+1,ans,0,no+1);
            }
        }
        return true;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> >ans(n, vector<int>(n, -1));
        int cur=0;
        mov(0,0,ans,cur, 1);
        return ans;
    }
};