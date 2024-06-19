class Solution {
public:
    
    bool check(int d, vector<int>& day, int k, int m){
        int cnt=0;
        int ans=0;
        for(int i=0;i<day.size();i++){
            if(day[i]<=d){
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt>=k){
                ans++;
                cnt-=k;
            }
        }
        return (ans>=m);
    }
    
    int minDays(vector<int>& day, int m, int k) {
        int n=day.size();
        if(1ll*n<1ll*m*k)return -1;
        int l=0, r=1000000000+5;
        while(r-l>0){
            int mid=l+(r-l)/2;
            if(check(mid, day, k ,m))r=mid;
            else l=mid+1;
        }
        return l;
    }
};