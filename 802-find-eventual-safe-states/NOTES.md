```
vector<int> toposort(int n, vector<vector<int>>& graph) {
vector<int> adj[n];
vector<int> indegree(n,0);
for(int i=0;i<graph.size();i++){
for(auto ele: graph[i]){
adj[ele].push_back(i);
indegree[i]++;
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
```
​
code for toposort given an adj matrix