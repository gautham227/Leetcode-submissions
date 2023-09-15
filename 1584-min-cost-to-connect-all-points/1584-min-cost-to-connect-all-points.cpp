typedef pair<int,int> pii;

class Solution {
public:
    
    int spanningTree(vector<vector<vector<int> > >adj)
{  
    int V=adj.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(V, false);
    int res = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int wt = p.first;
        int u = p.second;
        if(visited[u] == true){    
            continue;
        }
        res += wt;
        visited[u] = true;
        for(auto v : adj[u]){
            if(visited[v[0]] == false){
                pq.push({v[1], v[0]});
            }
        }
    }
    return res;
}
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<vector<int> > >adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                adj[i].push_back({j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
                adj[j].push_back({i,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
            }
        }
        return spanningTree(adj);
    }
};