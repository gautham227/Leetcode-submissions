```
// my first try using recursion
class Solution {
public:
int n;
vector<int> convert(int val){
int r=(val-1)/n;
int c;
r=n-1-r;
if(r%2==1){
c=(val-1)%n;
}
else{
if(val%n==0)c=0;
else c=n-(val%n);
}
return {r,c};
}
set<int> vis;
int dfs(int val, vector<vector<int> >& dp, vector<vector<int> >& board){
// cout<<val<<endl;
if(val>n*n)return 1e9;
if(val==n*n)return 0;
if(vis.find(val)!=vis.end())return 1e9;
vector<int> v1=convert(val);
int r=v1[0];