class Solution {
public:
    
    //based on kahns algo
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int p=q.front();
            q.pop();
            ans.push_back(p);
            for(auto x: adj[p]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
            
        }
        if(ans.size()<n)return {};
        return ans;
    }
};