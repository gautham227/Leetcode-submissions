class Solution {
public:

    int cnta, cntb, cntc;

    bool check(int val, string& s, int k){
        
        int n=s.size();
        
        int ca=0, cb=0, cc=0;
        for(int i=0;i<val;i++){
            if(s[i]=='a')ca++;
            else if(s[i]=='b')cb++;
            else cc++;
        }

        ca=cnta-ca;
        cb=cntb-cb;
        cc=cntc-cc;

        if(ca>=k && cb>=k && cc>=k)return true;

        for(int i=0;i<n-val;i++){
            int ind1=(i+val)%n;
            if(s[ind1]=='a')ca--;
            else if(s[ind1]=='b')cb--;
            else cc--;

            if(s[i]=='a')ca++;
            else if(s[i]=='b')cb++;
            else cc++;

            if(ca>=k && cb>=k && cc>=k)return true;
        }


        return false;
    }

    int takeCharacters(string s, int k) {
        cnta=0;
        cntb=0;
        cntc=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a')cnta++;
            else if(s[i]=='b')cntb++;
            else cntc++;
        }

        if(cnta<k || cntb<k || cntc<k)return -1;

        int l=0, r=s.size();

        while(r-l>1){

            // cout<<l<<" "<<r<<endl;

            int mid=l+(r-l)/2;

            cout<<mid<<endl;

            if(check(mid,s,k)){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }

        // cout<<l<<" "<<r<<endl;

        if(check(r,s,k))return n-r;
        return n-l; 

    }
};