class Solution {
public:
    
    bool check(vector<int>& arr, int mid){
        return arr[mid]>arr[mid-1];
    }
    
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=1, r=arr.size()-2;
        
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])return mid;
            if(check(arr, mid)){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
        if(check(arr, r))return r;
        return l;
    }
};