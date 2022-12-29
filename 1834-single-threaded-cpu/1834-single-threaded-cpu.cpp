class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& t) {
        
        int n=t.size();
        
        for(int i=0;i<n;i++){
            t[i].push_back(i);
        }
        
        sort(t.begin(), t.end());
        
        multiset<vector<int> >s;
        vector<int> ans;
        
        int ind=0;
        long long time=0;
        time=t[0][0];
        while(ind!=n || !s.empty()){
            
            while(ind<n && t[ind][0]<=time){
                s.insert({t[ind][1], t[ind][2]});
                ind++;
            }
            
            if(s.empty()){
                time=t[ind][0];
                continue;
            }
            
            ans.push_back((*(s.begin()))[1]);
            time+=(*(s.begin()))[0];
            s.erase(s.begin());
        }
        
        return ans;
    }
};