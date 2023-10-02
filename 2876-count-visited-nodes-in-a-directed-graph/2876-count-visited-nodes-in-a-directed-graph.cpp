class Solution {
public:
    vector<int> c;
 
    // bool cycle(int node,int par, vector<int>& vis, vector<vector<int> >& adj, vector<int>& cur)
    // {
    //     vis[node]=true;
    //     cur.pb(node);
    //     for(int child:adj[node])
    //     {
    //         if(!vis[child]){
    //             if(cycle(child,node,vis,adj,cur)==true) {cur.pop_back();return true;}
    //         }
    //         else if(child!=par) {cur.pb(child); c=cur;cur.pop_back();return true;}
    //     }
    //     cur.pop_back();
    //     return false;
    // }
    vector<int> cur;
    int last=-1;
    int dfs(int node, vector<int >& edg, vector<int> & vis,  vector<int>& ans){
        // if(s1.find(node)!=s1.end())return s1.size();
        if(vis[node]){last=node;return 0;}
        if(ans[node]!=-1)return ans[node];
        cur.push_back(node);
        vis[node]=1;
        int cur1=1+dfs(edg[node], edg, vis, ans);
        vis[node]=0;
        return cur1;
        
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        // vector<vector<int> >adj(n);
        // for(int i=0;i<edges.size();i++){
        //     adj[i].push_back(edges[i]);
        // }
        vector<int> ans(n, -1);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                cur.clear();
                last=-1;
                ans[i]=dfs(i, edges, vis, ans);
                int cnt=0;
                bool flag=false;
                for(int j=0;j<cur.size();j++){
                    if(cur[j]==last)flag=true;
                    if(!flag){
                        cnt++;
                    }
                    else{
                        ans[cur[j]]=ans[i]-cnt;
                    }
                }
            }
        }
        return ans;
    }
};