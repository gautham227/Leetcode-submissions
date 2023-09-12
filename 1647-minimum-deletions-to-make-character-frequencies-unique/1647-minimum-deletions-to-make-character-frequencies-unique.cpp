class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++){
            v[s[i]-'a']++;
        }
        
        unordered_set<int> ele;
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==0)continue;
            while(v[i]>0 && ele.find(v[i])!=ele.end()){
                v[i]--;
                ans++;
            }
            if(v[i]!=0)ele.insert(v[i]);
        }
        return ans;
    }
};