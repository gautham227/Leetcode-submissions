class Solution {
public:
    unordered_map<int, multiset<int> >adj;
    void dfs(int ind, vector<int>& ans){
        if(adj.find(ind)==adj.end())return;
        for(auto ele: adj[ind]){
            if(adj[ele].size()!=1){
                ans.push_back(ele);
                adj[ind].erase(adj[ind].find(ele));
                adj[ele].erase(adj[ele].find(ind));
                if(adj[ind].size()==0){
                    adj.erase(adj.find(ind));
                }
                if(adj[ele].size()==0){
                    adj.erase(adj.find(ele));
                }
                dfs(ele, ans);
                break;
            }
            else if(adj[ele].size()==1 && adj.size()==2){
                ans.push_back(ele);
                adj[ind].erase(adj[ind].find(ele));
                adj[ele].erase(adj[ele].find(ind));
                if(adj[ind].size()==0){
                    adj.erase(adj.find(ind));
                }
                if(adj[ele].size()==0){
                    adj.erase(adj.find(ele));
                }
                return;
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        adj.clear();
        for(auto ele: adjacentPairs){
            adj[ele[0]].insert(ele[1]);
            adj[ele[1]].insert(ele[0]);
        }
        int st=adj.begin()->first;
        for(auto &ele: adj){
            if(ele.second.size()%2==1){
                st=ele.first;
            }
        }
        // cout<<st<<endl;
        vector<int> ans;
        ans.push_back(st);
        
        dfs(st, ans);
        return ans;
    }
};