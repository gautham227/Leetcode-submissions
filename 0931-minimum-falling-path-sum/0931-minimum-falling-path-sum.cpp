class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> prev(matrix.size(), INT_MAX);
        vector<int> cur(matrix.size(), INT_MAX);
        vector<int> mov{-1,0,1};
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                if(i==0){
                    cur[j]=matrix[i][j];
                    continue;
                }
                for(int k=0;k<mov.size();k++){
                    if(j+mov[k]>=0 && j+mov[k]<matrix.size()){
                        cur[j]=min(cur[j],matrix[i][j]+prev[j+mov[k]]);
                    }
                }
            }
            prev=cur;
            for(int j=0;j<prev.size();j++){
                cur[j]=INT_MAX;
            }
        }
        return *min_element(prev.begin(), prev.end());
    }
};