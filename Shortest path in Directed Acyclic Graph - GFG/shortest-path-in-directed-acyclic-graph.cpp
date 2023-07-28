//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
     void topo(int ind, vector<int> & vis, stack<int> & st, vector<vector<pair<int, int> > >& adj){
         vis[ind]=1;
         
         for(auto ele: adj[ind]){
             if(vis[ele.first]==0)topo(ele.first, vis, st, adj);
         }
         
         st.push(ind);
     }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int> > >adj(N);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        
        stack<int> st;
        vector<int> vis(N,0);
        for(int i=0;i<N;i++){
            if(vis[i]==0)topo(i, vis, st, adj);
        }
        
        vector<int> topo_sort;
        
        while(!st.empty()){
            topo_sort.push_back(st.top());
            st.pop();
        }
        
        vector<int> dist(N, 1000000000+5);
        
        dist[0]=0;
        
        for(int i=0;i<N;i++){
            for(auto ele: adj[topo_sort[i]]){
                dist[ele.first]=min(dist[ele.first], dist[topo_sort[i]]+ele.second);
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1000000000+5)dist[i]=-1;
        }
        
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends