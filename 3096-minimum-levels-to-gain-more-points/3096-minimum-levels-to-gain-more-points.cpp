class Solution {
public:
    int minimumLevels(vector<int>& p) {
        int sum=0;
        int n=p.size();
        for(int i=0;i<p.size();i++){
            if(p[i]==1)sum++;
            else sum--;
        }
        int cur=0;
        bool flag=false;
        for(int i=0;i<n-1;i++){
            if(p[i]==1)cur++;
            else cur--;
            int oth=sum-cur;
            if(cur>oth)return i+1;
        }
        return -1;
    }
};