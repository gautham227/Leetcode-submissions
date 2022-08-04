class Solution {
public:
    vector<int> fact;
    void pre(){
        int k=1;
        fact.push_back(1);
        for(int i=1;i<10;i++){
            k*=i;
            fact.push_back(k);
        }
        return;
    }
    
    string getPermutation(int n, int k) {
        pre();
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        string ans="";
        k--;
        while(k>0){
            int q=(k)/fact[n-1];
            ans.push_back('0'+v[q]);
            v.erase(v.begin()+q);
            k=k%fact[n-1];
            n--;
        }
        for(int i=0;i<v.size();i++){
            ans.push_back('0'+v[i]);
        }
        return ans;
    }
};