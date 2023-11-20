class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        vector<int> p(n,0),m(n,0),g(n,0);
        for(int i=0;i<garbage.size();i++){
            int cntp=0, cntm=0, cntg=0;
            for(auto ch: garbage[i]){
                if(ch=='M')cntm++;
                if(ch=='P')cntp++;
                if(ch=='G')cntg++;
            }
            p[i]=cntp;
            // cout<<p[i]<<endl;
            m[i]=cntm;
            g[i]=cntg;
        }
        // cout<<"terminate"<<endl;
        vector<int> remp(n,0), remm(n,0), remg(n,0);
        for(int i=n-2;i>=0;i--){
            remp[i]+=remp[i+1]+p[i+1];
            remm[i]+=remm[i+1]+m[i+1];
            remg[i]+=remg[i+1]+g[i+1];
        }
        int ans=0;
        int ind=0;
        while(remp[ind]!=0){
            ans+=p[ind];
            ans+=travel[ind];
            ind++;
        }
        ans+=p[ind];
        ind=0;
        while(remm[ind]!=0){
            ans+=m[ind];
            ans+=travel[ind];
            ind++;
        }
        ans+=m[ind];
        ind=0;
        while(remg[ind]!=0){
            ans+=g[ind];
            ans+=travel[ind];
            ind++;
        }
        ans+=g[ind];
        return ans;
    }
};