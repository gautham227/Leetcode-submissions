class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(); // no of rows
        int m=matrix[0].size(); // no of columns
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j]^=matrix[i][j-1];
            }
        }
        
        vector<int> arr; // let arr be an array
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    arr.push_back(matrix[i][j]);
                    continue;
                }
                matrix[i][j]^=matrix[i-1][j];
                arr.push_back(matrix[i][j]);
            }
        }
        
        sort(arr.begin(), arr.end());
        // here as it is 0 based indexing we have to return k-1 th element
        return arr[arr.size()-k];
        
    }
};