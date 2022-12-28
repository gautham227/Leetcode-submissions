class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int > mp;
        
        bool flag=false;
        int ans=INT_MAX;
        
        for(int i=0;i<cards.size();i++){
            if(mp.find(cards[i])==mp.end()){
                mp[cards[i]]=i;
            }
            else{
                flag=true;
                ans=min(ans,i-mp[cards[i]]+1);
                mp[cards[i]]=i;
            }
        }
        
        if(flag==false)return -1;
        return ans;
    }
};