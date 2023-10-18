class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int> >out(n);
        vector<set<int> >in(n);
        for(int i=0;i<relations.size();i++){
            int x=relations[i][0];
            int y=relations[i][1];
            x--;
            y--;
            out[x].push_back(y);
            in[y].insert(x);
        }
        vector<int> ans(n,0);
        queue<int> processed;
        for(int i=0;i<n;i++){
            if(in[i].size()==0){
                processed.push(i);
                ans[i]=0;
            }
        }
        while(processed.size()>0){
            int x=processed.front();
            processed.pop();
            for(auto ele: out[x]){
                ans[ele]=max(ans[ele],time[x]+ans[x]);
                in[ele].erase(in[ele].find(x));
                if(in[ele].size()==0){
                    processed.push(ele);
                }
            }
        }
        int ans1=0;
        for(int i=0;i<n;i++){
            ans1=max(ans1, ans[i]+time[i]);
        }
        return ans1;
    }
};