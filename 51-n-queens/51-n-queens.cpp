class Solution {
public:
    vector<vector<string>> ans;
    int l[10], lb[20], lu[20];
    void recur(vector<string>& matrix, int n, int ind){
        if(ind==n){ans.push_back(matrix);return;}
        for(int i=0;i<n;i++){
            if(l[i]==0 && lb[i+ind]==0 && lu[n-1+i-ind]==0){
                matrix[i][ind]='Q';
                l[i]=1;lb[i+ind]=1;lu[n-1+i-ind]=1;
                recur(matrix,n,ind+1);
                matrix[i][ind]='.';
                l[i]=0;lb[i+ind]=0;lu[n-1+i-ind]=0;
            } 
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> matrix;
        string s="";
        for(int i=0;i<n;i++){
            s.push_back('.');
        }
        for(int i=0;i<n;i++){
            matrix.push_back(s);
        }
        recur(matrix,n,0);
        return ans;
    }
};