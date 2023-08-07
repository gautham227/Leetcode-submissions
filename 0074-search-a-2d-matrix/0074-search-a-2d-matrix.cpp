class Solution {
public:
    // bool ans=false;
    bool bs(vector<vector<int>>& matrix,int low, int high, int target){
        if(high>=low){
            int mid=low+(high-low)/2;
            if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]==target){
                return true;
            }
            else if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]>target){
                return bs(matrix,low,mid-1,target);
            }
            else{
                return bs(matrix,mid+1,high,target);
            }
            
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return bs(matrix, 0,matrix.size()*matrix[0].size()-1, target);
    }
};