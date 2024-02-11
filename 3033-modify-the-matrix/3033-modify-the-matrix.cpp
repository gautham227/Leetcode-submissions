class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int> >ans = matrix;
        for(int i=0;i<matrix[0].size();i++){
            int ma=0;
            for(int j=0;j<matrix.size();j++){
                ma=max(ma, matrix[j][i]);
            }
            for(int j=0;j<matrix.size();j++){
                if(matrix[j][i]==-1)ans[j][i]=ma;
            }
        }
        return ans;
    }
};