class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<int> mprof(100000+5, 0);
        int n=difficulty.size();
        for(int i=0;i<n;i++){
            mprof[difficulty[i]]=max(mprof[difficulty[i]], profit[i]);
        }
        // precomputing the max profit we can receive for each diff         
        
        for(int i=1;i<mprof.size();i++){
            mprof[i]=max(mprof[i], mprof[i-1]);
        }
         
        int ans=0;
        
        for(int i=0;i<worker.size();i++){
            ans+=mprof[worker[i]];
        }
        return ans;
    }
};