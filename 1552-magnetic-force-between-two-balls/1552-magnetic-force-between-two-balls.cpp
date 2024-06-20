class Solution {
public:
    
    bool check(int val, int m, set<int>& s){
        int cur=*(s.begin());
        m--;
        while(m>0){
            auto it=s.lower_bound(cur+val);
            if(it==s.end())return false;
            cur=*(it);
            m--;
        }
        return (m==0);
    }
    
    int maxDistance(vector<int>& position, int m) {
        set<int> s;
        for(auto ele: position)s.insert(ele);
        int l=1, r=1000000000+2;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(check(mid, m, s)){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        if(check(r, m, s))return r;
        return l;
    }
};