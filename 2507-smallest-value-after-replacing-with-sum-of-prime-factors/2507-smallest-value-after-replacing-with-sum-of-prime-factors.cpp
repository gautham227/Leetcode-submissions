class Solution {
public:
    
    const int N=1000000;
    bool sieve[1000001];
    void sieveoferas(){ 
        for(int i=2;i<=N;i++){
            sieve[i]=true;
        }
        for(int i=2;i*i<=N;i++){
            if(sieve[i]==true){
                for(int j=i*i;j<=N;j+=i){
                    sieve[j]=false;
                }
            }
        }
    }
    
    int smallestValue(int n) {
        sieveoferas();
        set<int> s;
        vector<int> prime;
        for(int i=2;i<=100000;i++){
            if(sieve[i])prime.push_back(i);
        }
        
        int cnt=1;
        s.insert(n);
        while(sieve[n]!=true){
            cnt++;
            int ind=0;
            int cur=0;
            // cout<<n<<endl;
            while(prime[ind]<=n){
                // cout<<prime[ind]<<endl;
                while(n%(prime[ind])==0 && n>1){
                    cur+=prime[ind];
                    n/=prime[ind];
                }
                // cout<<n<<endl;
                ind++;
                    
            }
            n=cur;
            s.insert(n);
            if(s.size()!=cnt)break;
        }
        return n;
    }
};