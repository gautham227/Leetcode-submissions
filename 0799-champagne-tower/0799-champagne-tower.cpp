class Solution {
public:
    double champagneTower(int poured, int r, int c) {
        vector<vector<double> > mat(103, vector<double>(103,0));
        mat[0][0]=(double)poured;
        for(int i=0;i<=101;i++){
            for(int j=0;j<=i;j++){
                double x=(mat[i][j]-1.0)/2;
                mat[i+1][j]+=max((double)0, x);
                mat[i+1][j+1]+=max((double)0, x);
            }
        }
        return min((double)1,mat[r][c]);
    }
};