class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        priority_queue<long long> pq;
        for(auto &ele: happiness)pq.push(ele);
        long long ind=0;
        while(k--){
            ans+=1ll*max(pq.top()-ind,1ll*0);
            ind++;
            pq.pop();
        }
        return ans;
    }
};