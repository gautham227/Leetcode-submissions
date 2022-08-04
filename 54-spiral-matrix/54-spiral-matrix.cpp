class Solution {
public:
    vector<int> v;
    bool mov(int i, int j,vector<vector<int>>& ans,int cur){
        if(i>=ans.size()|| j>=ans[0].size() || i<0 || j<0 || ans[i][j]==-1000)return false;
        v.push_back(ans[i][j]);
        ans[i][j]=-1000;
        bool x;
        if(cur==0){
            x=mov(i,j+1,ans,cur);
        }
        else if(cur==1){
            x=mov(i+1,j,ans,cur);
        }
        else if(cur==2){
            x=mov(i,j-1,ans,cur);
        }
        else{
            x=mov(i-1,j,ans,cur);
        }
        if(x==0){
            if(cur==0){
                x=mov(i+1,j,ans,cur+1);
            }
            else if(cur==1){
                x=mov(i,j-1,ans,cur+1);
            }
            else if(cur==2){
                x=mov(i-1,j,ans,cur+1);
            }
            else{
                x=mov(i,j+1,ans,0);
            }
        }
        return true;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        mov(0,0,matrix,0);
        return v;
    }
};