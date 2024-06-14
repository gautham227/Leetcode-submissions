class Solution {
public:
    
    vector<int> ans;
    
    bool dfs(int ind, int par, vector<vector<int> >& adj, vector<int>& nums){
        bool ret=(nums[ind]==1);
        for(auto ele: adj[ind]){
            if(ele==par)continue;
            ret|=dfs(ele, ind, adj, nums);
        }
        if(!ret){
            ans[ind]=1;
        }
        return ret;
    }
    
    void dfs1(int ind, int par, vector<vector<int> >& adj, vector<int>& nums, set<int>& s){
        int rem=-1;
        for(auto ele: adj[ind]){
            if(ele!=par && ans[ele]==-1){
                rem=ele;
            }
        }
        if(rem!=-1)dfs1(rem,ind,adj,nums,s);
        for(auto ele: adj[ind]){
            if(ele==par || ele==rem)continue;
            dfs1(ele, ind, adj, nums, s);
        }
        s.erase(s.find(nums[ind]));
        if(ans[ind]==-1)ans[ind]=*(s.begin());
        return;
    }
    
    vector<int> smallestMissingValueSubtree(vector<int>& p, vector<int>& nums) {
        int n=nums.size();
        vector<vector<int> >adj(n);
        int root=0;
        // We will be creating the adjacency list and find the root
        for(int i=0;i<n;i++){
            if(p[i]==-1){
                root=i;
            }
            else{
                adj[i].push_back(p[i]);
                adj[p[i]].push_back(i);
            }
        }
        
        // initialising the answer array
        ans.resize(n, -1);
        dfs(root,-1,adj,nums);
        set<int> s;
        for(int i=1;i<=100000+2;i++){
            s.insert(i);
        }
        dfs1(root,-1,adj,nums,s);
        return ans;
    }
};