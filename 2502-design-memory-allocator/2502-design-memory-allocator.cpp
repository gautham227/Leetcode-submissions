class Allocator {
public:
    vector<int> v;
    int len;
    Allocator(int n) {
        v.resize(n);
        for(int i=0;i<n;i++){
            v[i]=-1;
        }
        len=n;
    }
    
    int allocate(int size, int mID) {
        int ind=0;
        int cur=0;
        bool flag=false;
        // for(int i=0;i<len;i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<len;i++){
            if(v[i]==-1){
                cur++;
            }
            else{
                ind=i+1;
                cur=0;
            }
            if(cur==size){flag=true;break;}
            
        }
        if(flag==false)return -1;
        for(int i=ind;i<ind+size;i++){
            v[i]=mID;
        }
        return ind;
    }
    
    int free(int mID) {
        int ans=0;
        for(int i=0;i<len;i++){
            if(v[i]==mID){
                ans++;
                v[i]=-1;
            }
        }
        return ans;
    }
};

/*
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */