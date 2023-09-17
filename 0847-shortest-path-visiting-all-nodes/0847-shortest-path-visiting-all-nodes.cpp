class Solution {
public:
    const static int N=12;
    int dist[N][N];
    int n;

    void initialise(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j){dist[i][j]=0;}
                else{dist[i][j]=1e9+1;}
            }
        }
    }

    void floyd_warshall(){
        //O(N^3)
        // while taking input assign dist[x][y]=wt
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=1e9+1 && dist[k][j]!=1e9+1){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
    }
    
    int recur(int bitmask, int last, vector<vector<int> >&dp){
        if(__builtin_popcount(bitmask)==n)return 0;
        if(dp[bitmask][last]!=-1)return dp[bitmask][last];
        int cur=INT_MAX;
        for(int i=0;i<n;i++){
            if((bitmask>>i)&1){
                continue;
            }
            cur=min(cur, dist[i][last]+recur((bitmask|(1<<i)),i,dp));
        }
        return dp[bitmask][last]=cur;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        n=graph.size();
        initialise();
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                dist[i][graph[i][j]]=1;
            }
        }
        floyd_warshall();
        vector<vector<int> >dp((1<<12)+1, vector<int>(12,-1));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,recur((1<<i),i,dp));
        }
        return ans;
    }
};