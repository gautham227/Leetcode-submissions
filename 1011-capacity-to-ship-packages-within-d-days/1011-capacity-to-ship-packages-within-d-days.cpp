class Solution {
public:
    
    bool check(int val, vector<int>& w, int d){
        int cnt=1;
        int ind=0;
        int cur=0;
        while(ind<w.size()){
            if(cur+w[ind]>val){
                cnt++;
                cur=0;
            }
            cur+=w[ind];
            ind++;
        }
        if(cnt<=d)return true;
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l=INT_MIN;
        for(auto ele: weights)l=max(l,ele);
        int r=1e9;
        
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(check(mid,weights,days)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        
        if(check(l,weights,days))return l;
        return r;
        
    }
};