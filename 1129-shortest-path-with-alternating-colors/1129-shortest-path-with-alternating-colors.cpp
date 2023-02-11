class Solution {
public:
    
    void bfs(int v, vector<int>& dist, vector<int>& vis1,vector<int>&vis2, int cur1, vector<vector<int>>& adj1, vector<vector<int>>& adj2, int n){
        queue<vector<int> > q;
        q.push({v,0});
        vis1[v]=1;
        dist[v]=0;
        while(!q.empty()){
            int cur=q.front()[0];
            int l=q.front()[1];
            // cout<<cur<<" "<<l<<endl;
            q.pop();
            if(l%2==cur1){
                for(int child : adj1[cur]){
                    if(vis2[child]==1){
                        continue;
                    }
                    q.push({child,l+1});
                    vis2[child]=1;
                    dist[child]=min(dist[child],l+1);
                }   
            }
            else{
               for(int child : adj2[cur]){
                    if(vis1[child]==1){
                        continue;
                    }
                    q.push({child,l+1});
                    vis1[child]=1;
                    dist[child]=min(dist[child],l+1);
                }  
            }
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int> >adj1(n), adj2(n);
        for(auto ele: redEdges){
            adj1[ele[0]].push_back(ele[1]);
            // adj1[ele[1]].push_back(ele[0]);
        }
        for(auto ele: blueEdges){
            adj2[ele[0]].push_back(ele[1]);
            // adj2[ele[1]].push_back(ele[0]);
        }
        vector<int> vis1(n, 0), vis2(n,0), dist1(n, INT_MAX), dist2(n, INT_MAX);
        bfs(0,dist1,vis1,vis2,0,adj1,adj2,n);
        for(int i=0;i<n;i++){
            vis1[i]=0;
            vis2[i]=0;
        }
        bfs(0,dist2,vis1,vis2,1,adj1,adj2,n);
        vector<int> ans(n, INT_MAX);
        for(int i=0;i<n;i++){
            int c=min(dist1[i], dist2[i]);
            if(c==INT_MAX)ans[i]=-1;
            else ans[i]=c;
        }
        return ans;
    }
};