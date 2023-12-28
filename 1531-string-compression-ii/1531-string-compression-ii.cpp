struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

class Solution {
public:
    
    unordered_map<long long, int> dp;
    
    long long hash(int ind, int left, int count, int last){
        long long cur=1ll*ind;
        cur*=1000;
        cur+=left;
        cur*=1000;
        cur+=count;
        cur*=1000;
        cur+=last;
        return cur;
    }
    
    int ansfn(int cnt1){
        if(cnt1<=1)return cnt1;
        int val=1;
        while(cnt1>0){
            val++;
            cnt1/=10;
        }
        return val;
    }
    
    int recur(int ind, int left, int count, int last, string &s){
        if(ind>=s.size()){return ansfn(count);}
        long long hval=hash(ind,left,count,last);
        if(dp.find(hval)!=dp.end())return dp[hval];
        int ans=INT_MAX;
        if(left>0)ans=min(ans,recur(ind+1,left-1,count,last,s));
        if(s[ind]-'0'==last){
            ans=min(ans,recur(ind+1,left,count+1,last,s));
        }
        else{
            ans=min(ans,ansfn(count)+recur(ind+1,left,1,s[ind]-'0',s));
        }
        return dp[hval]=ans;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        return recur(0,k,0,27,s);
    }
};