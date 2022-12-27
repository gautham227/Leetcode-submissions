class Solution {
public:

    bool check(int val, vector<int>& p, int k){
        int last=p[0]+val;
        int cnt=1;

        while(lower_bound(p.begin(), p.end(),last)!=p.end()){
            cnt++;
            last=*(lower_bound(p.begin(), p.end(),last))+val;
            if(cnt>=k)break;
        }
        return (cnt>=k);
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int ma=0;

        int n=price.size();
        for(int i=0;i<n;i++)ma=max(ma,price[i]);

        int l=0, r=ma;

        while(r-l>1){
            int mid=l+(r-l)/2;
            cout<<mid<<endl;
            if(check(mid,price,k))l=mid;
            else r=mid-1;
        }
        if(check(r,price,k))return r;
        return l;
    }
};