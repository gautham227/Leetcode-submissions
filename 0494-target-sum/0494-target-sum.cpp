# define ll long long

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        ll zero=1500;
        vector<ll> prev(2*zero+1, 0), cur(2*zero+1, 0);

        prev[zero]=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<=2*zero;j++){
                if(prev[j]!=0){
                    cur[j+nums[i]]+=prev[j];
                    cur[j-nums[i]]+=prev[j];
                }
            }
            prev=cur;
            fill(cur.begin(), cur.end(), 0);
        }

        return prev[target+zero];
    }
};