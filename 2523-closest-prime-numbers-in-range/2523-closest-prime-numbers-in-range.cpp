class Solution {
public:
    
    int N=1000004;
    bool sieve[1000006];
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
    
    vector<int> closestPrimes(int left, int right) {
        vector<int> v1;
        sieveoferas();
        for(int i=left;i<=right;i++){
            if(sieve[i])v1.push_back(i);
        }
        
        if(v1.size()<2)return {-1,-1};
        
        int ansl=-1, ansr=-1;
        int mi=INT_MAX;
        
        for(int i=1;i<v1.size();i++){
            if((v1[i]-v1[i-1])<mi){
                ansl=v1[i-1];
                ansr=v1[i];
                mi=v1[i]-v1[i-1];
            }
        }
        
        return {ansl, ansr};
    }
};