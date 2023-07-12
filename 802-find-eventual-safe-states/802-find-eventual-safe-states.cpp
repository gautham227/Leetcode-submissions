class Solution {
public:
    
    // n is the no of elements and adj is the adjacency list
    vector<int> toposort(int n, vector<vector<int> >& adj) {
        vector<int> indegree(n,0);
        for(int i=0;i<adj.size();i++){
            for(auto node: adj[i]){
                indegree[node]++;
            }
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
        // if(ans.size()<n)return {};
        return ans;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<vector<int> >adj(n);
        
        for(int i=0;i<n;i++){
            for(auto node: graph[i]){
                adj[node].push_back(i);
            }
        }
        
        
        vector<int> topsorted = toposort(graph.size(), adj);
        
        set<int> ans;
        for(int ele: topsorted){
            bool flag=true;
            for(auto node: graph[ele]){
                if(ans.find(node)==ans.end())flag=false;
            }
            
            if(flag)ans.insert(ele);
            
        }
        
        vector<int> ret;
        for(auto ele: ans)ret.push_back(ele);
        
        return ret;
        
    }
};