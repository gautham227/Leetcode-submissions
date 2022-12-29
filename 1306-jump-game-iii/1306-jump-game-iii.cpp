class Solution {
public:
    
    bool recur(int ind, vector<int> & arr, vector<bool>& vis){
        // cout<<ind<<endl;
        if(vis[ind])return false;
        vis[ind]=true;
        if(arr[ind]==0)return true;
        bool l = false, r = false;
        if(ind-arr[ind]>=0)l=recur(ind-arr[ind],arr,vis);
        if(ind+arr[ind]<arr.size())r=recur(ind+arr[ind],arr,vis);
        return l||r;
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(),false);
        return recur(start,arr,vis);
    }
};