class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        map<int, int> mp;
        for(auto ele: balls){
            mp[ele]++;
        }
        set<int> freq;
        int mini=1000000000;
        for(auto ele: mp){
            freq.insert(ele.second);
            mini=min(mini, ele.second);
        }
        int div=1;
        for(int i=1;i<=mini;i++){
            bool flag=true;
            for(auto ele: freq){
                if(ele/i<ele%i){
                    flag=false;
                }
            }
            if(flag){
                div=i;
            }
        }
        int ans=0;
        for(auto ele: mp){
            ans+=(ele.second+div)/(div+1);
        }
        return ans;
        
    }
};