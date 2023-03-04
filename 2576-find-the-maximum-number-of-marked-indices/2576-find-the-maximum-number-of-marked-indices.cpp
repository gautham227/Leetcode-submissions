class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int j=n/2;
        int ans=0;
        for(int i=0;i<n/2;i++){
            while(j!=n && nums[j]<2*nums[i]){
                j++;
            }
            if(j==n)break;
            ans+=2;
            j++;
        }
        return ans;
    }
};