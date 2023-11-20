#define ll long long
#define maxv(a) *max_element(a.begin(), a.end())

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        ll ans=0;
        vector<int> prev(m+1, 0), cur(m+1, 0);

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(nums1[i]==nums2[j]){
                    cur[j]=1+prev[j+1];
                }
            }
            ans=max(ans, 1ll*maxv(cur));
            prev=cur;
            fill(cur.begin(), cur.end(), 0);
        }
        
        return ans;
    }
};