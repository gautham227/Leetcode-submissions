class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        queue<pair<int, int>> q;
        for(int i=0;i<t.size();i++){
            q.push({t[i],i});
        }
        int ans=0;
        while(1){
            int rem=(q.front()).first;
            int ind=(q.front()).second;
            q.pop();
            rem--;
            ans++;
            if(rem==0 && ind==k)break;
            if(rem!=0){
                q.push({rem,ind});
            }
        }
        return ans;
    }
};