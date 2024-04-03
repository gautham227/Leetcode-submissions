#define ll long long

class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    static bool cmp1(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    
    int maxdist(vector<vector<int> >& points){
        ll n=points.size();
        vector<vector<int> >v;
        vector<vector<int> >v1;
        for(int i=0;i<n;i++){
            v.push_back({points[i][0]+points[i][1], i});
            v1.push_back({points[i][0]-points[i][1],i});
        }
        
        sort(v.begin(), v.end());
        sort(v1.begin(), v1.end());
        return max(v[v.size()-1][0]-v[0][0],v1[v1.size()-1][0]-v1[0][0]);
    }
    
    
    int minimumDistance(vector<vector<int>>& points) {
        ll n=points.size();
        vector<vector<int> >v;
        vector<vector<int> >v1;
        for(int i=0;i<n;i++){
            v.push_back({points[i][0]+points[i][1], i});
            v1.push_back({points[i][0]-points[i][1],i});
        }
        
        sort(v.begin(), v.end());
        sort(v1.begin(), v1.end());
        int x,y;
        if(v[v.size()-1][0]-v[0][0]>v1[v1.size()-1][0]-v1[0][0]){
            x=v[v.size()-1][1];
            y=v[0][1];
        }
        else{
            x=v1[v1.size()-1][1];
            y=v1[0][1];
        }
        
        vector<vector<int> >l1, l2;
        for(int i=0;i<n;i++){
            if(x!=i)l1.push_back(points[i]);
            if(y!=i)l2.push_back(points[i]);
        }
        
        return min(maxdist(l1), maxdist(l2));
    }
};