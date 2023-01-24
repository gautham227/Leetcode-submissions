#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define all(x) (x).begin(),(x).end()
#define srt(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
#define cpy(v2,v1) v2.assign(v1.begin(),v1.end())
#define maxv(a) *max_element(a.begin(), a.end())
#define minv(a) *min_element(a.begin(), a.end())
#define ff first
#define ss second
#define endl "\n"


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

class Solution {
public:
    
    // const int N=1000;
    
    // std::vector<int> par(1000,-1);
    void dijkstra(int vertex, vector<vector<int> >& adj, vector<int>& dist){
        // cout<<"vertex "<<vertex<<endl;
        priority_queue<pii , vector<pii>, greater<pii> > pq;
        pq.push({0,vertex});
        dist[vertex]=0;
        // int cnt=0;
        while(!pq.empty()){
            auto node = pq.top();
            // cout<<node.ss<<" "<<dist[node.ss]<<" "<<pq.size()<<endl;
            int v=node.ss;
            int d=node.ff;
            pq.pop();
            // cout<<pq.size()<<endl;
            // if(cnt>adj.size()*adj.size())break;
            // cnt++;
            if(d!=dist[v])continue;
            for(auto child: adj[v]){
                int cv=child;
                // cout<<cv<<endl;
                int w=1;
                // cout<<dist[cv]<<" "<<dist[v]+w<<endl;
                if(dist[cv]>dist[v]+w){
                    dist[cv]=dist[v]+w;
                    // par[cv]=v;
                    pq.push({dist[cv],cv});
                }
            }
        }
        
        // cout<<"YES"<<endl;
        
        return;
    }
    
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        std::vector<int> dist(n*n+5,1e9+1);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int r,c;
                r=n-1-i;
                // cout<<r<<endl;
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
                // cout<<board[i][j]<<" ";
            }
            // cout<<endl;
        }
        vector<vector<int> >adj(n*n+1);
        for(int i=1;i<n*n;i++){
            // cout<<i<<" -> ";
            for(int j=i+1;j<=min(n*n, i+6);j++){
                if(mp[j]!=i)adj[i].push_back(mp[j]);
                // cout<<mp[j]<<" ";
            }
            // cout<<endl;
        }
        
        dijkstra(1,adj,dist);
        
        // for(int i=1;i<=n*n;i++)cout<<dist[i]<<" ";
        
        int ans=dist[n*n];
        if(ans>1e9)return -1;
        return ans;
    }
};