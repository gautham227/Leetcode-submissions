#define ll long long

class Solution {
public:
    int change(int amt, vector<int>& deno) {
        int n=deno.size();
        vector<ll> prev(amt+1, 0), cur(amt+1, 0);
        prev[0]=1;
        cur[0]=1;

        for(int i=0;i<n;i++){
            for(int j=1;j<=amt;j++){
                if(j-deno[i]>=0){
                    cur[j]+=cur[j-deno[i]];
                }
                cur[j]+=prev[j];

            }
            prev=cur;
            fill(cur.begin(), cur.end(), 0);
            cur[0]=1;
        }

        return prev[amt];
    }
};