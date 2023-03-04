// Created by: G Gautham Krishna

#define srt(v) sort(v.begin(),v.end())

//type definitions

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

ll binexp(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        srt(ranges);
        ll cur=0;
        ll n=ranges.size();
        ll last=ranges[0][1];
        int lu=-1;
        for(int i=1;i<n;i++){
            if(ranges[i][0]>last)cur++;
            last=max(last,1ll*ranges[i][1]);
        }
        cur++;
        return binexp(2,cur,1000000007);
    }
};