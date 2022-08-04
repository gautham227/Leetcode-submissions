class Solution {
public:
    int vis[2001];
    vector<int> adj[2001];
    
    bool cycle(int node)
    {
        if(vis[node]==2)return true;
        vis[node]=2;
        for(int child:adj[node])
        {
            if(vis[child]==1)continue;
            if(cycle(child)==true) return true;
        }
        vis[node]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int f=0;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]!=1){
                bool x=cycle(i);
                if(x){
                    f=1;
                    break;
                }   
            }
        }
        if(f)return false;
        return true;
    }
};