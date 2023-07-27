class Solution {
public:
    bool check(long long val, vector<int> & b, long long comp){
        long long req=comp*val;
        
        for(auto ele: b){
            if(ele>val)req-=val;
            else req-=ele;
        }
        
        return (req<=0);
    }
    
    
        
    long long maxRunTime(int n, vector<int>& batteries) {
        long long su=0;
        
        for(auto ele: batteries)su+=ele;
        
        long long l=0, r=su;
        
        while(r-l>1){
            long long mid=l+(r-l)/2;
            if(check(mid, batteries, n)){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        
        if(check(r, batteries, n))return r;
        return l;
    }
};