class Solution {
public:
    void merge(vector<int>&arr,int l,int mid,int r){
    int l1=mid-l+1;
    int l2=r-mid;
    int L[l1+1],R[l2+1];
    for (int i = 0; i < l1; i++)
    {
        L[i]=arr[l+i];
    }
    for (int i = 0; i < l2; i++)
    {
        R[i]=arr[mid+1+i];
    }
    L[l1]=10000000;
    R[l2]=10000000;
    int c1=0,c2=0;
    for (int i = l; i <=r ; i++)
    {
        if(L[c1]<=R[c2]){
            arr[i]=L[c1];
            c1++;
        }
        else{
            arr[i]=R[c2];
            c2++;
        }
    }
}

void merge_sort(vector<int>& arr,int l,int r){
    if(r>l){
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums,0,nums.size()-1);
        return nums;
    }
};