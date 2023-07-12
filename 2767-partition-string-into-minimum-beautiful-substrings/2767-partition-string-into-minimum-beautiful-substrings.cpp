class Solution {
public:
    
    bool check(int val){
        while(val>=5 && val%5==0)val/=5;
        return (val==1);
    }
    
    int recur(string& s, int ind){
        if(ind>=s.size())return 0;
        if(s[ind]=='0')return 100000005;
        int ans=100000000;
        int val=0;
        for(int i=ind;i<s.size();i++){
            val*=2;
            if(s[i]=='1'){
                val++;
            }
            // cout<<val<<" "<<check(val)<<endl;
            if(check(val))ans=min(ans, 1+recur(s, i+1));
        }
        // cout<<ans<<endl;
        return ans;
    }
    
    int minimumBeautifulSubstrings(string s) {
        int ans=recur(s,0);
        if(ans>20)return -1;
        return ans;
    }
};