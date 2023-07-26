class Solution {
public:
    
    bool check(vector<int> & dist, double hour, int cur){
        double time=0;
        for(int i=0;i<dist.size()-1;i++){
            time+=(int)(dist[i]+cur-1)/cur;
        }
        time+=(double) dist[dist.size()-1]/(double)cur;
        return (time<=hour);
    }
    
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1, r=10000005;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(check(dist, hour, mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        
        if(check(dist, hour, l))return l;
        if(r>10000000)return -1;
        return r;
    }
};