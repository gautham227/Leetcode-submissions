#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

class Solution {
public:
    void dijkstra(int vertex, vector<vector<int> >& adj, vector<int>& dist){
        priority_queue<pii , vector<pii>, greater<pii> > pq;
        pq.push({0,vertex});
        dist[vertex]=0;
        while(!pq.empty()){
            auto node = pq.top();
            int v=node.ss;
            int d=node.ff;
            pq.pop();
            if(d!=dist[v])continue;
            for(auto child: adj[v]){
                int cv=child;
                int w=1;
                if(dist[cv]>dist[v]+w){
                    dist[cv]=dist[v]+w;
                    pq.push({dist[cv],cv});
                }
            }
        }
        return;
    }
    
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        std::vector<int> dist(n*n+5,1e9+1);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int r,c;
                r=n-1-i;
            for(int j=0;j<n;j++){
                if(r%2==0){
                    c=j+1;
                }
                else{
                    c=n-j;
                }
                if(board[i][j]==-1){
                    board[i][j]=r*n+c;
                    
                }
                mp[r*n+c]=board[i][j];
            }
        }
        vector<vector<int> >adj(n*n+1);
        for(int i=1;i<n*n;i++){
            for(int j=i+1;j<=min(n*n, i+6);j++){
                if(mp[j]!=i)adj[i].push_back(mp[j]);
            }
        }
        
        dijkstra(1,adj,dist);
        int ans=dist[n*n];
        if(ans>1e9)return -1;
        return ans;
    }
};