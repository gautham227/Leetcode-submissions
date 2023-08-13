typedef long long ll;

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

class Solution {
public:
    
    int mod = 1000000000+7;
    
    ll binexp(ll a,ll b){
        ll ans=1;
        while(b){
            if(b&1){
                ans=(ans*a)%mod;
            }
            a=(a*a)%mod;
            b=b>>1;
        }
        return ans;
    }
    
    int primeFactors(int n){
        int ans=0;
        if(n%2==0)ans++;
        while (n % 2 == 0)
        {
            n = n/2;
        }
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            if(n%i==0)ans++;
            while (n % i == 0)
            {
                n = n/i;
            }
        }
        if (n > 2)ans++;
        return ans;
    }
    
    vector<int> prevGreater(vector<int>& arr, int n){
        vector<int> p;
        stack<int> s;
        s.push(0);
        p.push_back(-1);
        for (int i = 1; i < n; i++) {
            while (s.empty() == false && arr[s.top()] < arr[i])
                s.pop();
            s.empty() ? p.push_back(-1) : p.push_back(s.top());

            s.push(i);
        }
            return p;
    }
    
    vector<int> ngreele(vector<int>& arr, int n)
    {
        stack<int> s;
        s.push(0);
        vector<int> nge(n,0);
        for (int i = 1; i < n; i++) {

            if (s.empty()) {
                s.push(i);
                continue;
            }
            while (s.empty() == false && arr[s.top()] < arr[i]) {
                nge[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while (s.empty() == false) {
            nge[s.top()]=n;
            s.pop();
        }
        return nge;
    }
    
    long long total(long long cur){
        return cur*(cur+1)/2;
    }

    
    int maximumScore(vector<int>& nums, int k) {
        vector<int> pf;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x= primeFactors(nums[i]);
            pf.push_back(primeFactors(nums[i]));
        }
        
        vector<int> pg=prevGreater(pf,n);
        vector<int> ng=ngreele(pf,n);
        
        priority_queue<pair<long long,long long> >pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i]*1ll, total(1ll*ng[i]-pg[i]-1)-total(1ll*i-1-pg[i])-total(1ll*ng[i]-i-1)});
        }
        
        long long ans=1;
        while(k>0){
            ans=mod_mul(ans, binexp(pq.top().first, min(1ll*k, 1ll*pq.top().second)), mod);
            k-=(pq.top()).second;
            pq.pop();
        }
        
        return ans;
        
    }
};