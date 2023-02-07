class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp;
        int cur=0;
        int ans=0;
        for(int i=0;i<fruits.size();i++){
            mp[fruits[i]]++;
            while(mp.size()>2){
                mp[fruits[cur]]--;
                if(mp[fruits[cur]]==0)mp.erase(mp.find(fruits[cur]));
                cur++;
            }
            ans=max(ans,i-cur+1);
        }
        return ans;
    }
};