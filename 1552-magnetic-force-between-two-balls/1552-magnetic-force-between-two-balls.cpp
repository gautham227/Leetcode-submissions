class Solution {
public:
    
    bool check(int val, int m, vector<int>& s){
        int cur=*(s.begin());
        m--;
        while(m>0){
            auto it=lower_bound(s.begin(), s.end(), cur+val);
            if(it==s.end())return false;
            cur=*(it);
            m--;
        }
        return (m==0);
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l=1, r=1000000000+2;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(check(mid, m, position)){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        if(check(r, m, position))return r;
        return l;
    }
};