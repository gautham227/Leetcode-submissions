class Solution {
public:
    
    vector<int> toposort(vector<vector<int> >adj){
        int n=adj.size();
        vector<int> indegree(n,0);
        
        // finding the indegree of all the vertices
        
        for(int i=0;i<n;i++){
            for(auto ele: adj[i]){
                indegree[ele]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        vector<int> topsort;
        
        // traversing the queue and finding the toposort
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto ele: adj[top]){
                indegree[ele]--;
                if(indegree[ele]==0)q.push(ele);
            }
            topsort.push_back(top);
        }
        
        return topsort;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int> >adj(numCourses);
        
        // creating the adjacency list
        for(int i=0;i<prereq.size();i++){
            adj[prereq[i][1]].push_back(prereq[i][0]);
        }
        
        vector<int> toposortedarray=toposort(adj);
        
        return (toposortedarray.size()==numCourses);
        
    }
};