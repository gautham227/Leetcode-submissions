class Solution {
public:
    vector<int> cur;
    int last=-1;
    int dfs(int node, vector<int >& edg, vector<int> & vis,  vector<int>& ans){
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