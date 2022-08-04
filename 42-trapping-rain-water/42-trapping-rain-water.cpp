class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int vp[n];
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi, height[i]);
            vp[i]=maxi;
        }
        maxi=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi, height[i]);
            ans+=(min(maxi,vp[i])-height[i]);
        }
        return ans;
    }
};