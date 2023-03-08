class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> s;
        for(auto ele: banned)s.insert(ele);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end()){
                if(i>maxSum)break;
                maxSum-=i;
                ans++;
            }
        }
        return ans;
    }
};