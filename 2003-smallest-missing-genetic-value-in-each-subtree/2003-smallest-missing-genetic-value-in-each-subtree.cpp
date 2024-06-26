class Solution {
public:
    
    vector<int> ans;
    bitset<100000+2> bs;
    // assigining an answer of 1 to all the nodes whoch do not have 1 in its subtree     
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
    
    // after the first dfs only 1 path exsts where answer has not been found so at first we will go to those children and determine its answers, then we will be processing the other nodes.     
    void dfs1(int ind, int par, vector<vector<int> >& adj, vector<int>& nums){
        // rem denotes be the child node for which answer has not been found, there will be only 1 child with this property as the numbers are distinct        
        int rem=-1;
        for(auto ele: adj[ind]){
            if(ele!=par && ans[ele]==-1){
                rem=ele;
            }
        }
        if(rem!=-1)dfs1(rem,ind,adj,nums);
        int mini=1;
        for(auto ele: adj[ind]){
            if(ele==par)continue;
            mini=max(mini, ans[ele]);
            if(ele==rem)continue;
            dfs1(ele,ind,adj,nums);
        }
        bs.set(nums[ind]);
        while(bs[mini]){
            mini++;
        }
        if(ans[ind]==-1)ans[ind]=mini;
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
        dfs1(root,-1,adj,nums);
        return ans;
    }
};