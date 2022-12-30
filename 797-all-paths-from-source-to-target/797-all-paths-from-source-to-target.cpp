class Solution {
public:
    
    void recur(int ind, vector<vector<int> >& graph, vector<vector<int> > &ans, vector<int>& path, int dest){
        path.push_back(ind);
        if(ind==dest){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        for(auto child: graph[ind]){
            recur(child,graph,ans,path,dest);
        }
        
        path.pop_back();
        
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> >ans;
        
        vector<int> path;
        
        int dest=graph.size()-1;
        
        recur(0,graph,ans,path,dest);        
        
        return ans;
    }
};