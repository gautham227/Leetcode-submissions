class Solution {
public:
    
    bool check(int no, string&s, int k){
        int cnt=1;
        long long last=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            last*=10;
            last+=1ll*(s[i]-'0');
            if(last>1ll*k){
                cnt++;
                last=1ll*(s[i]-'0');
            }
        }
        return (cnt<=no);
    }
    
    int minimumPartition(string s, int k) {
        int n=s.size();
        for(int i=0;i<n;i++){
            if((s[i]-'0')>k)return -1;
        }
        
        int l=1, r=n;
        
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(check(mid,s,k)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        if(check(l,s,k)){
            return l;
        }
        return r;
    }
};