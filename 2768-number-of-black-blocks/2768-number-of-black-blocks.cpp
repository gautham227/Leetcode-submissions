class Solution {
public:
    vector<long long> ans;
    
    unordered_set<long long >s;
    unordered_set<long long >checked;
    
    long long convert(int x, int y){
        return 1ll*x*1000000+y;
    }
    
    bool check(int x, int y, int n, int m){
        // cout<<"check "<<x<<" "<<y<<endl;
        if(x<0 || y<0 || x>=n || y>=m)return false;
        return true;
    }
    
    int fn1(int x, int y, int n, int m){
        // cout<<x<<" "<<y<<endl;
        
        if(checked.find(convert(x,y))!=checked.end())return 0;
        if(!check(x,y,n,m))return 0;
        // cout<<x<<" "<<y<<endl;
        if(!check(x+1,y+1,n,m))return 0;
        int cnt=0;
        if(s.find(convert(x,y))!=s.end())cnt++;
        if(s.find(convert(x+1,y))!=s.end())cnt++;
        if(s.find(convert(x,y+1))!=s.end())cnt++;
        if(s.find(convert(x+1,y+1))!=s.end())cnt++;
        checked.insert(convert(x,y));
        return cnt;
    }
    
    void fn(int x, int y, int n, int m){
        ans[fn1(x-1,y-1,n,m)]++;
        ans[fn1(x,y-1,n,m)]++;
        ans[fn1(x-1,y,n,m)]++;
        ans[fn1(x,y,n,m)]++;
        return;
    }
    
    
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        long long n1=coordinates.size();
        
        for(int i=0;i<5;i++)ans.push_back(0);
        
        for(int i=0;i<n1;i++){
            s.insert(convert(coordinates[i][0], coordinates[i][1]));
        }
        for(int i=0;i<n1;i++){
            int x=coordinates[i][0];
            int y=coordinates[i][1];
            fn(x,y,m,n);
        }
        
        ans[0]=1ll*(n-1)*(m-1);
        
        for(int i=1;i<5;i++){
            // ans[i]/=i;
            ans[0]-=ans[i];
        }
        
        
        return ans;
        
    }
};