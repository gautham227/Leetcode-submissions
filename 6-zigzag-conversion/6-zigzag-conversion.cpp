class Solution {
public:
    string convert(string s, int n) {
        
        if(n==1)return s;
        
        vector<string> v(n, "");
        
        int cur=0;
        
        for(int i=0;i<s.size();i++){
            
            if(cur==0){
                while(i<s.size()  && cur<n){
                    v[cur].push_back(s[i]);
                    cur++;
                    i++;
                }
                i--;
                cur=n-2;
            }
            
            else{
                v[cur].push_back(s[i]);
                cur--;
            }
            
        }
        
        string ans="";
        
        for(int i=0;i<n;i++){
            ans+=v[i];
        }
        
        return ans;
        
    }
};