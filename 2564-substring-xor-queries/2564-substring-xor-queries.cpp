class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int,vector<int> > mp;
        int n=s.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            int cur=s[i]-'0';
            if(mp.find(cur)==mp.end() || mp[cur][1]-mp[cur][0]>0)mp[cur]={i,i};
            for(int j=i+1;j<min(i+31,n);j++){
                if(cur>1e9)break;
                cur*=2;
                cur+=(s[j]-'0');
                if(mp.find(cur)==mp.end() || mp[cur][1]-mp[cur][0]>j-i)mp[cur]={i,j};
            }
        }
        vector<vector<int> >ans;
        
        for(int i=0;i<queries.size();i++){
            if(mp.find(queries[i][0]^queries[i][1])!=mp.end()){
                ans.push_back(mp[queries[i][0]^queries[i][1]]);
            }
            else{
                ans.push_back({-1,-1});
            }
        }
        
        return ans;
    }
};