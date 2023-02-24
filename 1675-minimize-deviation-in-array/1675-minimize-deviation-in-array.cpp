class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        multiset<int> s;
        int mini=1e9+1;
        for(auto ele: nums){
            if(ele%2==1){s.insert(2*ele);mini=min(mini,2*ele);
                         //cout<<2*ele<<endl;
        }
        else{
            s.insert(ele);
            mini=min(mini,ele);
            //cout<<ele<<endl;
        }
    }
        int ans=(*(--s.end()))-(*(s.begin()));
        // cout<<ans<<endl;
    while((*(--s.end()))%2==0){
        int top=*(--s.end());
        // cout<<top<<endl;
        s.erase(s.find(top));
        s.insert(top/2);
        mini=min(mini,top/2);
        ans=min(ans,(*(--s.end()))-mini);
        // cout<<"ans "<<ans<<endl;
    }
        // cout<<"arr"<<endl;
        // for(auto ele:s)cout<<ele<<endl;
    return ans;
    }
};