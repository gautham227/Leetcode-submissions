#define maxv(a) *max_element(a.begin(), a.end())
class Solution {
public:
    long long max(long long a, long long b){
        if(a>b)return a;
        return b;
    }
    long long vis[100001];
    void f(long long i,vector<vector<int>>& v){
        long long ind=i+v[i][1]+1;
        if(ind<v.size()){
            vis[i]=max(1LL*v[i][0]+1LL*vis[ind],1LL*vis[i+1]);
        }
        else{
            vis[i]=max(1LL*vis[i+1],1LL*v[i][0]);
        }
    }
    long long mostPoints(vector<vector<int>>& questions) {
        // vector<int> vis(questions.size(),0);
        vis[questions.size()-1]=questions[questions.size()-1][0];
        for(long long i=questions.size()-2;i>=0;i--){
            f(i,questions);
        }
        // int ma=0;
        
        return vis[0];
        
    }
};